#ifndef __IIC_H
#define __IIC_H

#include "stm32h7xx_hal.h"

/*----------------------------------------- IIIC �������ú� -----------------------------------------------*/
 

#define Touch_IIC_SCL_CLK_ENABLE     __HAL_RCC_GPIOG_CLK_ENABLE()		// SCL ����ʱ��
#define Touch_IIC_SCL_PORT   			 GPIOG                 				// SCL ���Ŷ˿�
#define Touch_IIC_SCL_PIN     		 GPIO_PIN_3  							// SCL ����
         
#define Touch_IIC_SDA_CLK_ENABLE     __HAL_RCC_GPIOG_CLK_ENABLE() 	// SDA ����ʱ��
#define Touch_IIC_SDA_PORT   			 GPIOG                   			// SDA ���Ŷ˿�
#define Touch_IIC_SDA_PIN    			 GPIO_PIN_7              			// SDA ����

#define Touch_INT_CLK_ENABLE    		 __HAL_RCC_GPIOI_CLK_ENABLE()		// INT ����ʱ��
#define Touch_INT_PORT   				 GPIOI                   			// INT ���Ŷ˿�
#define Touch_INT_PIN    				 GPIO_PIN_11             			// INT ����

#define Touch_RST_CLK_ENABLE   		 __HAL_RCC_GPIOI_CLK_ENABLE()		// RST ����ʱ��
#define Touch_RST_PORT   				 GPIOI                   			// RST ���Ŷ˿�
#define Touch_RST_PIN    				 GPIO_PIN_10           				// RST ����

/*------------------------------------------ IIC��ض��� -------------------------------------------------*/

#define ACK_OK  	1  			// ��Ӧ����
#define ACK_ERR 	0				// ��Ӧ����

// IICͨ����ʱ��Touch_IIC_Delay()����ʹ�ã�
//	ͨ���ٶ���100KHz����
#define IIC_DelayVaule  20  	

/*-------------------------------------------- IO�ڲ��� ---------------------------------------------------*/   

#define Touch_IIC_SCL(a)	if (a)	\
										HAL_GPIO_WritePin(Touch_IIC_SCL_PORT, Touch_IIC_SCL_PIN, GPIO_PIN_SET); \
									else		\
										HAL_GPIO_WritePin(Touch_IIC_SCL_PORT, Touch_IIC_SCL_PIN, GPIO_PIN_RESET)	

#define Touch_IIC_SDA(a)	if (a)	\
										HAL_GPIO_WritePin(Touch_IIC_SDA_PORT, Touch_IIC_SDA_PIN, GPIO_PIN_SET); \
									else		\
										HAL_GPIO_WritePin(Touch_IIC_SDA_PORT, Touch_IIC_SDA_PIN, GPIO_PIN_RESET)		

/*--------------------------------------------- �������� --------------------------------------------------*/  		
					
void 		Touch_IIC_GPIO_Config (void);					// IIC���ų�ʼ��
void 		Touch_IIC_Delay(uint32_t a);					// IIC��ʱ����
void		Touch_INT_Out(void);								// INT���ݽ�����Ϊ���ģʽ
void		Touch_INT_In(void);								// INT���ݽ�����Ϊ����ģʽ								
void 		Touch_IIC_Start(void);							// ����IICͨ��
void 		Touch_IIC_Stop(void);							// IICֹͣ�ź�
void 		Touch_IIC_ACK(void);								//	������Ӧ�ź�
void 		Touch_IIC_NoACK(void);							// ���ͷ�Ӧ���ź�
uint8_t 	Touch_IIC_WaitACK(void);						//	�ȴ�Ӧ���ź�
uint8_t	Touch_IIC_WriteByte(uint8_t IIC_Data); 	// д�ֽں���
uint8_t 	Touch_IIC_ReadByte(uint8_t ACK_Mode);		// ���ֽں���
		
#endif //__IIC_H
