#ifndef __LCD_H
#define __LCD_H
#include "main.h"

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;
extern SPI_HandleTypeDef hspi2;

// LCD��Ҫ������
typedef struct
{
    u16 width;      // LCD ���
    u16 height;     // LCD �߶�
    u16 id;         // LCD ID
    u8 dir;         // ���������������ƣ�0��������1��������
    u16 wramcmd;    // ��ʼдgramָ��
    u16 setxcmd;    // ����x����ָ��
    u16 setycmd;    // ����y����ָ��
} _lcd_dev;

extern _lcd_dev lcddev;

/////////////////////////////////////�û�������///////////////////////////////////	 
//֧�ֺ��������ٶ����л���֧��8/16λģʽ�л�
#define USE_HORIZONTAL  	0	//�����Ƿ�ʹ�ú��� 		0,��ʹ��.1,ʹ��.
//ʹ��Ӳ��SPI ����ģ��SPI��Ϊ����
#define USE_HARDWARE_SPI    1  //1:Enable Hardware SPI;0:USE Soft SPI
//////////////////////////////////////////////////////////////////////////////////	  


#if USE_HORIZONTAL == 1
#define LCD_W 320
#define LCD_H 240
#else
#define LCD_W 240
#define LCD_H 320
#endif

//TFTLCD������Ҫ���õĺ���		   
extern u16  POINT_COLOR;//Ĭ�Ϻ�ɫ    
extern u16  BACK_COLOR; //������ɫ.Ĭ��Ϊ��ɫ


////////////////////////////////////////////////////////////////////
//-----------------LCD�˿ڶ���---------------- 
//ģ������������ܿ��Ʊ��������û�Ҳ���Խ�PWM���ڱ�������
//#define LCD_LED        	GPIO_Pin_9  //PB9 ������TFT -LED
//�ӿڶ�����Lcd_Driver.h�ڶ��壬����ݽ����޸Ĳ��޸���ӦIO��ʼ��LCD_GPIO_Init()
// LCD���ƿڶ���
#define LCD_CTRL GPIOB
#define LCD_CTRL2 GPIOC
#define LCD_RS GPIO_PIN_6
#define LCD_CS GPIO_PIN_12
#define LCD_SCL GPIO_PIN_13
#define LCD_SDA GPIO_PIN_15

// Һ�����ƿ���1�����궨��
#define LCD_CS_SET LCD_CTRL->BSRR = LCD_CS
#define LCD_RS_SET LCD_CTRL2->BSRR = LCD_RS
#define LCD_SDA_SET LCD_CTRL->BSRR = LCD_SDA
#define LCD_SCL_SET LCD_CTRL->BSRR = LCD_SCL

// Һ�����ƿ���0�����궨��
#define LCD_CS_CLR LCD_CTRL->BRR = LCD_CS
#define LCD_RS_CLR LCD_CTRL2->BRR = LCD_RS
#define LCD_SDA_CLR LCD_CTRL->BRR = LCD_SDA
#define LCD_SCL_CLR LCD_CTRL->BRR = LCD_SCL

//������ɫ
#define WHITE       0xFFFF
#define BLACK      	0x0000	  
#define BLUE       	0x001F  
#define BRED        0XF81F
#define GRED 			 	0XFFE0
#define GBLUE			 	0X07FF
#define RED         0xF800
#define MAGENTA     0xF81F
#define GREEN       0x07E0
#define CYAN        0x7FFF
#define YELLOW      0xFFE0
#define BROWN 			0XBC40 //��ɫ
#define BRRED 			0XFC07 //�غ�ɫ
#define GRAY  			0X8430 //��ɫ
//GUI��ɫ

#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
//������ɫΪPANEL����ɫ 
 
#define LIGHTGREEN     	0X841F //ǳ��ɫ
//#define LIGHTGRAY     0XEF5B //ǳ��ɫ(PANNEL)
#define LGRAY 			 		0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE      	0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE          0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)
	    															  
extern u16 BACK_COLOR, POINT_COLOR ;  

void HAL_LCD_SPIv_WriteData(uint8_t Data);
uint8_t HAL_SPI_WriteByte(SPI_HandleTypeDef *hspi, uint8_t TxData);
void LCD_WR_REG(uint16_t data);
void LCD_WR_DATA(uint8_t data);
void LCD_WR_DATA_16Bit(u16 data);
void LCD_WriteReg(u16 LCD_Reg, u16 LCD_RegValue);
void LCD_WriteRAM_Prepare(void);
void LCD_DrawPoint(u16 x, u16 y);
void LCD_GPIOInit(void);
void LCD_RESET(void);
void LCD_Init(void);
void LCD_Clear(uint16_t Color);
void LCD_SetWindows(uint16_t xStart, uint16_t yStart, uint16_t xEnd, uint16_t yEnd);
void LCD_SetCursor(u16 Xpos, u16 Ypos);
void LCD_SetParam(void);


#endif
