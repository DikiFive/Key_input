#include "sys.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "key.h"
int main(void)
{
	delay_init();
	LED_Init();
	
	while (1)
	{
	}
}
