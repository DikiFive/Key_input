#ifndef __KEY_H
#define __KEY_H
#include "sys.h"

#define KEY0 GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4)  //读取key0
#define KEY1 GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3)  //读取key1
#define WK_UP GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) //读取key——wakeup(WK_UP)

#define KEY0_PRES 1 // KEY0按下
#define KEY1_PRES 2 // KEY1按下
#define WKUP_PRES 3 // KEY_UP按下

void Key_int(void);   //按键初始化函数
u8 KEY_Scan(u8 mode); //按键检测函数

#endif
