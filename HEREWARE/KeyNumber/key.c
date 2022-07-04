#include "key.h"

void Key_int(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOE, ENABLE); //使能PORTA，PORTE时钟

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_3; // KEY0-KEY1
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;          //设置成上拉输入
    GPIO_Init(GPIOE, &GPIO_InitStructure);                 //初始化GPIOE4,3

    //初始化 WK_UP -->GPIOA.0   下拉输入
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; // PA0设置成输入，默认下拉
    GPIO_Init(GPIOA, &GPIO_InitStructure);        //初始化GPIOA.0
}

u8 KEY_Scan(u8 mode)
{
    static u8 key_up = 1; //按键松开标志
    if (mode)
        key_up = 1;                                       //支持连按
    if (key_up && (KEY0 == 0 || KEY1 == 0 || WK_UP == 1)) //有一个按键被按下时并且之前松开的时候
    {
        delay_ms(10); //消除抖动
        key_up = 0;
        if (KEY0 == 0)
            return KEY0_PRES;
        else if (KEY1 == 0)
            return KEY1_PRES;
        else if (WK_UP == 1)
            return WKUP_PRES;
    }
    else if (KEY0 == 1 && KEY1 == 1 && WK_UP == 0) //没有按键被按下时
        key_up = 1;
    return 0; // 无按键按下
}