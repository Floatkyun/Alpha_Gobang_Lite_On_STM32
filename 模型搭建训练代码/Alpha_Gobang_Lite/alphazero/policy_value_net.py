# coding: utf-8
import torch
from torch import nn
from torch.nn import functional as F

from .chess_board import ChessBoard

from torchsummary import summary


class AxialDW(nn.Module):
    def __init__(self, dim, mixer_kernel, dilation = 1):
        super().__init__()
        h, w = mixer_kernel
        self.dw_h = nn.Conv2d(dim, dim, kernel_size=(h, 1), padding='same', groups = dim, dilation = dilation)
        self.dw_w = nn.Conv2d(dim, dim, kernel_size=(1, w), padding='same', groups = dim, dilation = dilation)

    def forward(self, x):
        x = x + self.dw_h(x) + self.dw_w(x)
        return x

class EncoderBlock(nn.Module):
    """Encoding then downsampling"""
    def __init__(self, in_c, out_c, mixer_kernel = (7, 7)):
        super().__init__()
        self.dw = AxialDW(in_c, mixer_kernel = (7, 7))
        self.bn = nn.BatchNorm2d(in_c)
        self.pw = nn.Conv2d(in_c, out_c, kernel_size=1)
        self.down = nn.MaxPool2d((2,2))
        self.act = nn.GELU()

    def forward(self, x):
        skip = self.bn(self.dw(x))
        x = self.act(self.down(self.pw(skip)))
        return x, skip

class DecoderBlock(nn.Module):
    """Upsampling then decoding"""
    def __init__(self, in_c, out_c, mixer_kernel = (7, 7)):
        super().__init__()
        self.up = nn.Upsample(scale_factor=2)
        self.pw = nn.Conv2d(in_c + out_c, out_c,kernel_size=1)
        self.bn = nn.BatchNorm2d(out_c)
        self.dw = AxialDW(out_c, mixer_kernel = (7, 7))
        self.act = nn.GELU()
        self.pw2 = nn.Conv2d(out_c, out_c, kernel_size=1)

    def forward(self, x, skip):
        x = self.up(x)
        x = torch.cat([x, skip], dim=1)
        x = self.act(self.pw2(self.dw(self.bn(self.pw(x)))))
        return x
    
class BottleNeckBlock(nn.Module):
    """Axial dilated DW convolution"""
    def __init__(self, dim):
        super().__init__()

        gc = dim//4
        self.pw1 = nn.Conv2d(dim, gc, kernel_size=1)
        self.dw1 = AxialDW(gc, mixer_kernel = (3, 3), dilation = 1)
        self.dw2 = AxialDW(gc, mixer_kernel = (3, 3), dilation = 2)
        self.dw3 = AxialDW(gc, mixer_kernel = (3, 3), dilation = 3)

        self.bn = nn.BatchNorm2d(4*gc)
        self.pw2 = nn.Conv2d(4*gc, dim, kernel_size=1)
        self.act = nn.GELU()

    def forward(self, x):
        x = self.pw1(x)
        x = torch.cat([x, self.dw1(x), self.dw2(x), self.dw3(x)], 1)
        x = self.act(self.pw2(self.bn(x)))
        return x

class ULite(nn.Module):
    def __init__(self):
        super().__init__()

        """Encoder"""

        self.e1 = EncoderBlock(16, 32)
        self.e2 = EncoderBlock(32,64)
        self.e3 = EncoderBlock(64, 128)

        """Bottle Neck"""
        self.b5 = BottleNeckBlock(128)

        """Decoder"""

        self.d3 = DecoderBlock(128, 64)
        self.d2 = DecoderBlock(64, 32)
        self.d1 = DecoderBlock(32, 16)

    def forward(self, x):
        """Encoder"""
        x, skip1 = self.e1(x)
        x, skip2 = self.e2(x)
        x, skip3 = self.e3(x)

        
        """BottleNeck"""
        x = self.b5(x)         # (512, 8, 8)

        """Decoder"""

        x = self.d3(x, skip3)
        x = self.d2(x, skip2)
        x = self.d1(x, skip1)
        return x



class ConvBlock(nn.Module):


    def __init__(self, in_channels: int, out_channel: int, kernel_size, padding=0):
        super().__init__()
        self.conv = nn.Conv2d(in_channels, out_channel,
                              kernel_size=kernel_size, padding=padding)
        self.batch_norm = nn.BatchNorm2d(out_channel)

    def forward(self, x):
        return F.relu(self.batch_norm(self.conv(x)))


class ResidueBlock(nn.Module):

    def __init__(self, in_channels=128, out_channels=128):

        super().__init__()
        self.in_channels = in_channels
        self.out_channels = out_channels
        self.conv1 = nn.Conv2d(in_channels, out_channels,
                               kernel_size=3, stride=1, padding=1)
        self.conv2 = nn.Conv2d(out_channels, out_channels,
                               kernel_size=3, stride=1, padding=1)
        self.batch_norm1 = nn.BatchNorm2d(num_features=out_channels)
        self.batch_norm2 = nn.BatchNorm2d(num_features=out_channels)

    def forward(self, x):
        out = F.relu(self.batch_norm1(self.conv1(x)))
        out = self.batch_norm2(self.conv2(out))
        return F.relu(out + x)


class PolicyHead(nn.Module):


    def __init__(self, in_channels=128, board_len=9):

        super().__init__()
        self.board_len = board_len
        self.in_channels = in_channels
        self.conv = ConvBlock(in_channels, 2, 1)
        self.fc = nn.Linear(2*board_len**2, board_len**2)

    def forward(self, x):
        x = self.conv(x)
        x = self.fc(x.flatten(1))
        return F.log_softmax(x,dim=1)


class ValueHead(nn.Module):
    

    def __init__(self, in_channels=128, board_len=9):
       
        super().__init__()
        self.in_channels = in_channels
        self.board_len = board_len
        self.conv = ConvBlock(in_channels, 1, kernel_size=1)
        self.fc = nn.Sequential(
            nn.Linear(board_len**2, 128),
            nn.ReLU(),
            nn.Linear(128, 1),
            nn.Tanh()
        )

    def forward(self, x):
        x = self.conv(x)
        x = self.fc(x.flatten(1))
        return x


class PolicyValueNet(nn.Module):
    

    def __init__(self, board_len=9, n_feature_planes=6, is_use_gpu=True):
        
        super().__init__()
        self.board_len = board_len
        self.is_use_gpu = is_use_gpu
        self.n_feature_planes = n_feature_planes
        self.device = torch.device('cuda:1' if is_use_gpu else 'cpu')
        self.conv1 = ConvBlock(n_feature_planes, 42, 3, padding=1)
        self.conv2 = ConvBlock(42, 16, 4, padding=1)
        self.ULite=ULite()
        self.residues = nn.Sequential(
            *[ResidueBlock(42, 42) for i in range(4)])
        self.conv3 = ConvBlock(16, 32, 4, padding=2)
        self.conv4 = ConvBlock(32+42, 128, 3, padding=1)
        self.policy_head = PolicyHead(128, board_len)
        self.value_head = ValueHead(128, board_len)

    def forward(self, x):
        
        x1 = self.conv1(x)
        x2 = self.conv2(x1)
        
        x1 = self.residues(x1)
        x2=self.ULite(x2)
        x2 = self.conv3(x2)
        x= torch.cat([x1, x2], dim=1)
        x = self.conv4(x)
        p_hat = self.policy_head(x)
        value = self.value_head(x)
        return p_hat, value

    def predict(self, chess_board: ChessBoard):
        
        feature_planes = chess_board.get_feature_planes().to(self.device)
        feature_planes.unsqueeze_(0)
        p_hat, value = self(feature_planes)

        
        p = torch.exp(p_hat).flatten()


        if self.is_use_gpu:
            p = p[chess_board.available_actions].cpu().detach().numpy()
        else:
            p = p[chess_board.available_actions].detach().numpy()

        return p, value[0].item()

    def set_device(self, is_use_gpu: bool):
        
        self.is_use_gpu = is_use_gpu
        self.device = torch.device('cuda:1' if is_use_gpu else 'cpu')


if __name__=="__main__":
    net=PolicyValueNet()
    net.eval()
    summary(net, input_size=(6, 9, 9))
    torch_input=torch.zeros(1,6,9,9)
    input_name=["input"]
    output_name=["output"]
    torch.onnx.export(net,torch_input,"test.onnx",input_names=input_name,output_names=output_name,opset_version=17)