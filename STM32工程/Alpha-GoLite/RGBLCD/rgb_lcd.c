#include "rgb_lcd.h"


void LCD_Clear(uint16_t color)
{
	uint32_t i; 				// ��������
 
	while( LTDC->CDSR != 0X00000001);	// �ж� ��ʾ״̬�Ĵ���LTDC_CDSR �ĵ�0λ VDES����ֱ����ʹ����ʾ״̬�����Ա���˺��ЧӦ
	for(i=0;i<(480*800);i++)	
	{
		*(__IO uint16_t*)( SDRAM_BANK_ADDR + i*2 ) = color ; 	// д���Դ�							
	}	 
	
}

void LCD_Clear_DMA(uint16_t color)
{
	
	DMA2D->CR	  &=	~(DMA2D_CR_START);				//	ֹͣDMA2D
	DMA2D->CR		=	DMA2D_R2M;							//	�Ĵ�����SDRAM
	DMA2D->OPFCCR	=	LTDC_PIXEL_FORMAT_RGB565;						//	������ɫ��ʽ
	DMA2D->OOR		=	0;										//	������ƫ�� 
	DMA2D->OMAR		=	0xC0000000 ;				// ��ַ
	DMA2D->NLR		=	(800<<16)|(480);	//	�趨���ȺͿ��
	DMA2D->OCOLR	=	color;						//	��ɫ
	
/******	
�ȴ� ��ֱ����ʹ����ʾ״̬ ����LTDC����ˢ��һ�������ݵ�ʱ��
��Ϊ����Ļû��ˢ��һ֡ʱ����ˢ��������˺�ѵ�����
�û�Ҳ����ʹ�� �Ĵ��������ж� �����жϣ�����Ϊ�˱�֤���̵ļ���Լ���ֲ�ķ����ԣ�����ֱ��ʹ���жϼĴ����ķ���
	
��������жϣ�DMA2Dˢ���ٶ�����
	
��ɫ��ʽ	RGB565	 RGB888	 ARGB888
��ʱ	   4.3ms	    7.5ms	  11.9ms


����֮�󣬲������ָ�ʽ������Ҫ17.6msˢһ����������Ļ�����ˢ����ֻ��60֡���ң�LTDCʱ��33MHz����
17.6ms���ٶ��Ѿ��㹻�ˣ������Ƕ��ٶ�Ҫ���ر�ߵĳ��ϣ���Ȼ��������жϴ�ֱ�ȴ�����䣬���Ա���˺��ЧӦ

******/
	while( LTDC->CDSR != 0X00000001);	// �ж� ��ʾ״̬�Ĵ���LTDC_CDSR �ĵ�0λ VDES����ֱ����ʹ����ʾ״̬
	
	DMA2D->CR	  |=	DMA2D_CR_START;					//	����DMA2D
		
	while (DMA2D->CR & DMA2D_CR_START) ;				//	�ȴ��������
	 
}

