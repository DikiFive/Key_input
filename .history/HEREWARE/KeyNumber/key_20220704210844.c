#include "key.h"

void Key_int(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //使能GPIOB端口时钟

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;         // BEEP-->PB.8 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //速度为50MHz
    GPIO_Init(GPIOB, &GPIO_InitStructure);            //根据参数初始化GPIOB.8

    GPIO_ResetBits(GPIOB, GPIO_Pin_8); //初始化输出为0，关闭蜂鸣器
}

u8 KEY_Scan(u8 mode)
{
    static u8 key_up = 1; //
    if (mode)
        key_up = 1; //Ö§³ÖÁ¬°´
    if (key_up && (KEY0 == 0 || KEY1 == 0 || WK_UP == 1))
    {
        delay_ms(10); //È¥¶¶¶¯
        key_up = 0;
        if (KEY0 == 0)
            return KEY0_PRES;
        else if (KEY1 == 0)
            return KEY1_PRES;
        else if (WK_UP == 1)
            return WKUP_PRES;
    }
    else if (KEY0 == 1 && KEY1 == 1 && WK_UP == 0)
        key_up = 1;
    return 0; // ÎÞ°´¼ü°´ÏÂ
}