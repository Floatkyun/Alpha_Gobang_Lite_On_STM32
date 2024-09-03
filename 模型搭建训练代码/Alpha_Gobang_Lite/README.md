# 本训练框架由项目[Alpha-Gobang-Zero](https://github.com/zhiyiYo/Alpha-Gobang-Zero)修改而来，欢迎给原项目点star，阅读原项目博客[点击这里](https://www.cnblogs.com/zhiyiYo/p/14683450.html)。以下是原项目的项目大纲，本项目部分修改了其训练策略和网络结构。


# 思路
本项目使用Pytorch深度学习框架，下面由微观到宏观的顺序对整个项目的创建过程进行梳理。

## 一、定义棋盘类 `ChessBoard`
棋盘类用于记录玩家的动作，并根据需要返回当前棋盘的 `state_feature_planes`(一个 `C×H×W` 的矩阵)。棋盘类的构造如下：

### Attribute
* `board_len: int`: 棋盘边长
* `current_player: int`: 当前玩家
* `available_actions: list`: 可用的落点
* `n_feature_planes: int`: 特征平面个数
* `state: dict`: 棋盘状态字典，key 为 `action`，value 为 `current_player`

### Method
* `copy() -> ChessBoard`: 复制棋盘
* `clear_board() -> None`: 清空棋盘
* `is_game_over() -> Tuple[bool, int]`: 判断游戏是否结束
  * 如果还没分出胜负，返回 `(False, None)`
  * 如果分出了胜负，返回 `(True, winner)`
  * 如果平局，返回 `(True, None)`
* `do_action(action: int) -> None`: 根据输入的动作更新棋盘和当前玩家
* `get_feature_planes() -> Tensor`: 返回棋盘状态特征张量，用于策略-价值网络的输入，维度为 `(n_feature_planes, board_len, board_len)`
* `self_play(mcts) -> NamedTuple[pi_list, z_list, state_feature_planes_list]`: 自演一局，返回局内每一个时间步 $t$ 产生的 $\boldsymbol{\pi}_t$ 组成的列表 `pi_list` 、这一局的胜负结果 $z$ 相对于当前玩家的奖赏 $z_t$ 组成的列表 `z_list` 、以及每一个时间步 $t$ 的 `state_feature_planes​` 组成的 `state_feature_planes_list`

## 二、定义节点类 `Node`
节点类用来构造蒙特卡洛树，根据论文中的说法:
> Each node $s$ in the search tree contains edges $(s, a)$ for all legal action $s ∈\mathcal{A}(s)$. Each edge stores a set of statistics:
>
> $\left\{N(s,a), W(s,a), Q(s,a), P(s,a)\right\}$,
>
> where $N(s, a)$ is the visit count, $W(s, a)$ is the total action value, $Q(s, a)$ is the mean action value and $P(s, a)$ is the prior probability of selecting that edge.

节点应该具有以下属性:
## Attribute
* `c_puct: float`: 探索常数 $c_{puct}$
* `P: float`: 选择节点的先验概率 $P(s,a)$
* `N: int, default=0`: 访问次数 $N(s,a)$
* `Q: float, default=0`: 累计平均奖赏 $Q(s,a)=1/N(s,a) \sum_{s'|s,a\rightarrow s'} V(s')$
* `U: float, default=0`: 根据 PUCT 算法有: $U(s, a) = c_{puct} P(s, a) \sqrt{\sum_b N(s, b)}/\left(1 + N(s,a) \right)$
* `score: float`: 节点评分 `Score = Q(s,a) + U(s,a)`，在**选择**步骤起作用
* `parent: Node, default=None`: 父级节点
* `children: dict, default={}`: 子节点字典，key 为 `action`，`value` 为 `Node`

## Method
* `select() -> Tuple[int, Node]`: 返回 `score` 最大的子节点，同时返回该节点的 `action`
* `expand(action_probs: List[Tuple[int, float]]) -> None`: 拓展节点，`action_probs` 的每一个元素为 `(action, prior_prob)` 元组，根据这个创建子节点，`action_probs` 的长度为当前棋盘的可用落点的总数
* `update(value: float) -> None`: 更新节点的访问次数 $N(s,a)$ 、节点的累计平均奖赏 $Q(s,a)$ 、
* `backup(value: float) -> None`: 反向传播，更新自己和所有父节点的属性
* `is_leave_node() -> bool`: 返回自己是否为叶节点
* `get_score() -> float`: 更新节点的 $U(s,a)$ 和评分 $Score = Q(s,a)+U(s,a)$ 并返回当前的 $Score$


## 三、定义策略-价值网络类 `PolicyValueNet`
现在有一个棋局进行到第 $t$ 步，局面为 $s_t$。 策略价值网络输入 $s_t$，输出策略向量 $\boldsymbol{p}_t \in \mathbb{R}^{n^2}$ 和值 $V_t$，其中 $n$ 为棋盘的边长。$\boldsymbol{p} _t$ 和局面 $s_t$ 下的可用落点 `available_actions` 一起构成 `action_probs`，作为叶节点 $s_L$ 的 `expand(action_probs, c_puct)` 的参数 对叶节点进行拓展；$V_t$ 作为叶节点 $s_L$ 的 `backup(value)` 的参数进行反向传播。

### Blocks
#### `ULite()`
一个`U_Net`的轻量化版本`U_Lite`，具体请[点击这里](https://github.com/duong-db/U-Lite)查看原本项目。

#### `ResidualBlock(in_channels=42, out_channels=42)`

残差块，自上（输入）而下（输出）的组成如下：

* `conv1: nn.Conv2d`: 输入通道数为`in_channels`，输出通道数为 `out_channels`,，卷积核大小为 3×3 ，`padding` 为 1 的卷积层
*  `batch_norm1: nn.BatchNorm2d`: `num_features` 为输出通道数 `out_channels ` 的批量归一化层
*  `nn.ReLU`
* `conv2: nn.Conv2d`: 输入通道数为 `out_channels`,，输出通道数为  `out_channels`，卷积核大小为 3×3 ，步长为 1，`padding` 为 1 的卷积层
* `batch_norm2: nn.BatchNorm2d`：`num_features` 为  `out_channels` 的批量归一化层
* 跳连接，将输入和 `batch_norm` 的输出相加
* `nn.RelU`    

        Alpha Gobang Lite 将 Res_Net 网络与 U_Net 网络并行连接，其中包含的4层 Res_Net 负责获取棋盘的表层特征，而 U_Net 则利用其编码器串联解码器的结构特性提取棋盘的深层特征。



#### `PolicyHead(in_channels=128)`

用来计算对数动作概率向量 $\hat{\boldsymbol{p}} = \log\left(\frac{\exp(x_i) }{ \sum_j \exp(x_j)} \right)$，$x_i$ 为全连接层的输出，`policy_head` 组成如下：

* `conv: nn.Conv2d`: 输入通道数为 `in_channels`，输出通道数为 2，卷积核大小为 1×1，步长为 1 的卷积层
* `batch_norm: nn.BatchNorm2d`：`num_features` 为 2 的批量归一化层
* `nn.ReLU`
* `fc: nn.Linear`: 输入特征数为 `2*H*W`，输出特征数为 `H*W` 的全连接层
* `F.log_softmax`: 对数 `softmax`

#### `ValueHead(in_channels=128)`

用来计算 $V$ ，组成如下：

* `conv: nn.Conv2d`: 输入通道数为 `in_channels`，输出通道数为 1，卷积核大小为 1×1 的卷积层
* `batch_norm: nn.BatchNorm2d`：`num_features` 为 1 的批量归一化层
* `nn.ReLU`
* `fc: nn.Sequencial`: 全连接神经网络，组成如下：
    * `nn.Linear`: 输入特征数为 `H*W`，输出特征数为 128 的全连接层
    * `nn.ReLU`
    * `nn.Linear`: 输入特征数为 128，输出特征数为 1 的全连接层
    * `nn.Tanh`: 将全连接层的输出映射到 [-1, 1]

### Attribute

* `conv: nn.Sequancial`: 卷积块的组成为：
    * `nn.Conv2d`: 输入通道数为`C`，输出通道数为 128,，卷积核大小为 3×3 ，`padding` 为 1 的卷积层
    *  `nn.BatchNorm2d`: `num_features` 为输入通道数 128 的批量归一化层
    *  `nn.ReLU`
* `residues: nn.Sequencial`: 4 个结构相同的的残差块: `ResidueBlock(128, 128)`
* `policy_head: PolicyHead`:  输入通道数为 128
* `value_head: ValueHead`:  输入通道数为 128

### Method

* `forward(X: Tensor) -> tuple`： 返回对数先验概率向量  $\hat{\boldsymbol{p}}$ 和 `value`
* `predict(chess_board: ChessBoard) -> Tuple[np.ndarray, float]`: 返回每一个可行的动作对应的先验概率`P(s, a)`，以及 `value`。数组的长度为 `chess_board` 可用落点的总数，小于等于 `self.forward(state_feature_planes)` 返回的 $\hat{\boldsymbol{p}}$ 的长度


## 四、定义基于策略-价值网络的蒙特卡洛搜索树类 `AlphaZeroMCTS`

根据输入的局面 $s_t$ ，得到表示每一个可行动作执行动作的向量 $\boldsymbol{\pi}_t$ ，并依概率返回一个 `action` 的搜索树，其中 $\boldsymbol{\pi}_t$ 的选取依赖于策略-价值网络 `PolicyValueNet` 的输出 $\boldsymbol{p}_t$。

### Attribute

* `root: Node`: 根节点
* `n_iters`: 迭代搜索次数
* `c_puct: float`: 探索常数
* `is_self_play: bool`: 是否处于自我博弈状态
* `policy_value_net: PolicyValueNet`: 策略-价值网络

### Method

* `reset_root()`: 重置根节点为 `Node(prior_prob=1, parent=None)`
* `get_action(chess_board: ChessBoard) -> Union[int, tuple]`: 根据当前局面执行蒙特卡洛数搜索，返回 `action` 或 `(action, pi)`，其中 `pi` 的计算公式为：$\pi(a|s)=N(s,a)^{1/\tau}/\sum_b N(s, b)^{1/\tau}$，其中 $\tau$ 为温度，`action` 依概率 $\pi(a|s)$ 从所有可行的 `action` 中选择。
    **Note:**  在自我博弈时，根据论文中的描述

    > For the first 30 moves of each game, the temperature is set to $\tau=1$; this selects moves proportionally to their visit count in MCTS, and ensures a diverse set of positions are encountered. For the remainder of the game, an infinitesimal temperature is used, $\tau \rightarrow 0$. Additional exploration is achieved by adding Dirichlet noise to the prior probabilities in the root node $s_0$, specifically $P(s, a) =(1−\varepsilon) p_a + \varepsilon \eta_a$, where $\eta_a ∼Dir(0.03)$ and $\varepsilon=0.25$;

    应该随时间步 $t$ 改变温度 $\tau$ 并在依概率选择 `action` 的时候添加狄利克雷噪声


### 树搜索过程
1. 从当前的根节点出发，如果子节点不是叶节点，就选择 $Score = Q(s,a)+U(s,a)$ 最大的子节点继续向下搜索；
2. 遇到叶节点后，将叶节点对应的局面 $s_L$ 输入 `PolicyValueNet`，得到先验概率向量 $\boldsymbol{p}$ 和价值 $V$，使用 $\boldsymbol{p}$ 来拓展叶节点，$V$ 来反向传播；如果迭代次数 `i < n_iters`，回到步骤1，否则进行步骤3；
3. 根据根节点下面各个子节点的访问次数 $N(s,a)$，计算 $\pi(a|s)=N(s,a)^{1/\tau}/\sum_b N(s, b)^{1/\tau}$，依概率 $\pi(a|s)$ 来选择子节点及其对应的动作
4. 更新蒙特卡洛树的根节点为动作对应的子节点

## 五、自我博弈（一局）

1. 清空棋盘，初始化 `pi_list`、`z_list` 和 `feature_planes_list`；
2. 将当前的局面 `state` 输入蒙特卡洛树并将其推入列表中，得到蒙特卡洛树搜索的结果 `action` 和 $\boldsymbol{\pi}$；
3. 根据蒙特卡洛树返回的 `action` 更新棋盘，将 $\boldsymbol{\pi}$ 添加到对应的列表中；
4. 判断游戏是否结束，如果结束，根据当前的玩家计算出 `z_list` ，接着创建 `self_play_data = namedtuple(pi_list=pi_list, z_list=z_list, feature_planes_list=feature_planes_list)` 并返回；如果还没结束，回到步骤 2；

## 六、训练

1. 设置自我博弈的次数和 `batch_size` ，实例化`ChessBoard`、`PolicyValueNet` 和 `AlphaZeroMCTS`；
2. 进行一局自我博弈，得到 `self_play_data`，对 `self_play_data` 进行旋转和镜像变换来拓展数据集，将 `self_play_data` 中的数据添加到数据集中；
3. 如果数据集长度大于等于 `start_train_size` 时，开始训练。每次从数据集中拿出 `batch_size` 的 `feature_planes` ，调用 `policy_value_net(batch_feature_planes)` 产生 $\log{\boldsymbol{p}}$ 和 $v$，根据公式  $loss = (z-v)^2-\boldsymbol{\pi}^T \log \boldsymbol{p} + c||\theta||^2$ 进行误差的反向传播，由此完成一次参数 $\theta$ 的更新；
4. 如果遇到 `checkpoint`，需要对模型进行一次评估，让当前模型和历史最优模型对战，计算胜利率；每当胜率超过 55%，就保存当前的 `PolicyValueNet` 为历史最优模型；
5. 如果没有完成所有的自我博弈，回到步骤2，如果完成所有自我博弈或者发生外部中断，则退出循环。