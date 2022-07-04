#include "sys.h"
#include "delay.h"
#include "led.h"
int main(void)
{
	delay_init();
	LED_Init();
	while (1)
	{
	}
}
