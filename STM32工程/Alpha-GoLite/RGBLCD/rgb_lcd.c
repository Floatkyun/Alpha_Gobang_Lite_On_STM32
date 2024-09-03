#include "rgb_lcd.h"


void LCD_Clear(uint16_t color)
{
	uint32_t i; 				// 计数变量
 
	while( LTDC->CDSR != 0X00000001);	// 判断 显示状态寄存器LTDC_CDSR 的第0位 VDES：垂直数据使能显示状态，可以避免撕裂效应
	for(i=0;i<(480*800);i++)	
	{
		*(__IO uint16_t*)( SDRAM_BANK_ADDR + i*2 ) = color ; 	// 写入显存							
	}	 
	
}

void LCD_Clear_DMA(uint16_t color)
{
	
	DMA2D->CR	  &=	~(DMA2D_CR_START);				//	停止DMA2D
	DMA2D->CR		=	DMA2D_R2M;							//	寄存器到SDRAM
	DMA2D->OPFCCR	=	LTDC_PIXEL_FORMAT_RGB565;						//	设置颜色格式
	DMA2D->OOR		=	0;										//	设置行偏移 
	DMA2D->OMAR		=	0xC0000000 ;				// 地址
	DMA2D->NLR		=	(800<<16)|(480);	//	设定长度和宽度
	DMA2D->OCOLR	=	color;						//	颜色
	
/******	
等待 垂直数据使能显示状态 ，即LTDC即将刷完一整屏数据的时候
因为在屏幕没有刷完一帧时进行刷屏，会有撕裂的现象
用户也可以使用 寄存器重载中断 进行判断，不过为了保证例程的简洁以及移植的方便性，这里直接使用判断寄存器的方法
	
如果不做判断，DMA2D刷屏速度如下
	
颜色格式	RGB565	 RGB888	 ARGB888
耗时	   4.3ms	    7.5ms	  11.9ms


加了之后，不管哪种格式，都需要17.6ms刷一屏，不过屏幕本身的刷新率只有60帧左右（LTDC时钟33MHz），
17.6ms的速度已经足够了，除非是对速度要求特别高的场合，不然建议加上判断垂直等待的语句，可以避免撕裂效应

******/
	while( LTDC->CDSR != 0X00000001);	// 判断 显示状态寄存器LTDC_CDSR 的第0位 VDES：垂直数据使能显示状态
	
	DMA2D->CR	  |=	DMA2D_CR_START;					//	启动DMA2D
		
	while (DMA2D->CR & DMA2D_CR_START) ;				//	等待传输完成
	 
}

