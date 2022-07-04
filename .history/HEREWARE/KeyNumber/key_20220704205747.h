#ifndef __KEY_H
#define __KEY_H
#include "sys.h"

#define KEY0 GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4)  //
#define KEY1 GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3)  //¶ÁÈ¡°´¼ü1
#define WK_UP GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) //¶ÁÈ¡°´¼ü3(WK_UP)

void Key_int(void); //按键初始化函数

#endif
