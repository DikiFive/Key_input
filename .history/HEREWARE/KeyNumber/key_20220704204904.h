#ifndef __KEY_H
#define __KEY_H
#include "sys.h"

#define Key0 PEout(4) // PE4,输出端口
#define Key1 PEout(3) // PE3,输出端口
#de

void Key_int(void); //按键初始化函数

#endif