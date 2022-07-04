#include "sys.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "key.h"
int main(void)
{
	delay_init();
	LED_Init();
	Key_int();
	Beep_int();
	while (1)
	{
	}
}
