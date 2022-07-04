#include "sys.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "key.h"
int main(void)
{
	vu8 key = 0;
	delay_init();
	LED_Init();
	Key_int();
	Beep_int();
	LED0 = 0;
	while (1)
	{
		key = KEY_Scan(0);
		if (key)
		{
			switch (key)
			{
			case WKUP_PRES: //控制蜂鸣器
				BEEP = !BEEP;
				break;
			case KEY1_PRES: //¿ØÖÆLED1·­×ª
				LED1 = !LED1;
			case KEY0_PRES: //Í¬Ê±¿ØÖÆLED0,LED1·­×ª
				LED0 = !LED0;
				LED1 = !LED1;
				break;
			}
		}
	}
}
