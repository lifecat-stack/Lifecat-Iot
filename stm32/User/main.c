/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   LCD显示JPG文件及截图
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火 F103-指南者 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
#include "stm32f10x.h"
#include "./lcd/bsp_ili9341_lcd.h"
#include "./usart/bsp_usart.h" 
#include "./led/bsp_led.h"   
#include "ff.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void jpgDisplay(char *pic_name);
char *join(char *, char *,char *);  

void delay_us(u16 t)
{  
  u16 i,j;
	for(i=0;i<t;i++){
    for(j=0;j<t;j++){
		}
	}
}


FATFS fs;													/* FatFs文件系统对象 */
FRESULT res_sd;                /* 文件操作结果 */

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main ( void )
{
	int p = 0;

	ILI9341_Init ();         //LCD 初始化
	
	LCD_SetFont(&Font8x16);
	LCD_SetColors(RED,BLACK);
  ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* 清屏，显示全黑 */
  ILI9341_GramScan ( 6 );
	
	USART_Config();		
	LED_GPIO_Config();

	LED_BLUE;
	
	//本工程编译后 jpg解码库有一些warning，不影响使用。
	//移植本工程时，请注意启动文件的堆栈大小
	printf("\r\n ********** 显示JPG文件*********** \r\n"); 
	printf("\r\n 实验前请确保SD卡的目录下具有实验使用的JPG图片文件, \r\n"); 
	
	/*挂载sd文件系统*/
	res_sd = f_mount(&fs,"0:",1);
	if(res_sd != FR_OK)
	{
		printf("\r\n请给开发板插入已格式化成fat格式的SD卡。\r\n");
	}
	
	ILI9341_GramScan ( 6 );
	/*显示SD卡内的JPG文件，请确保SD卡该路径下有该文件，
	可在工程目录下的“需要拷贝到SD卡”的文件夹中复制到SD卡的该目录*/
	
	jpgDisplay("0:/Image/background.jpg");
	delay_us(4000);
	
	while ( 1 )
	{
		switch(p%10){
			case 0:
		    jpgDisplay("0:/img0.jpg");
		    break;
			case 1:
		    jpgDisplay("0:/img1.jpg");
		    break;
			case 2:
		    jpgDisplay("0:/img2.jpg");
		    break;
			case 3:
		    jpgDisplay("0:/img3.jpg");
		    break;
			case 4:
		    jpgDisplay("0:/img4.jpg");
		    break;
			case 5:
		    jpgDisplay("0:/img5.jpg");
		    break;
			case 6:
		    jpgDisplay("0:/img6.jpg");
		    break;
			case 7:
		    jpgDisplay("0:/img7.jpg");
		    break;
			case 8:
		    jpgDisplay("0:/img8.jpg");
		    break;
			case 9:
		    jpgDisplay("0:/img9.jpg");
		    break;
		}
	
		p++;
		delay_us(8000);
	}
}
  
char* join(char *s1, char *s2,char *s3)  
{  
    char *result = malloc(strlen(s1)+strlen(s2)+strlen(s3)+1);//+1 for the zero-terminator  
  
    strcpy(result, s1);  
    strcat(result, s2);  
	  strcat(result, s3); 
  
    return result;  
}  

/* ------------------------------------------end of file---------------------------------------- */

