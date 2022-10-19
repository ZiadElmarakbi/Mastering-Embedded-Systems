
#include "BareMetalDriver.h"
#include "TypeDef.h"

void Delay(int nCount)
{
	for(; nCount != 0; nCount--);
}

uint32_t getPressureVal(){
	return (GPIOA_IDR & 0xFF);
}

void Set_Alarm_Buzzer(int i){
	if (i == 1){
		 // DPRINTF("!!! Alarm is Buzzing !!!\n");
		SET_BIT(GPIOA_ODR,13);
	}
	else if (i == 0){
		 // DPRINTF("Alarm is OFF\n");
		RESET_BIT(GPIOA_ODR,13);
	}
}

void Set_Alarm_Indicator(Indicator_status LEDstatus){

	if (LEDstatus == Green_On){
		// DPRINTF("GREEN LED is ON !! \n");
		RESET_BIT(GPIOA_ODR,10);
	}
	else if (LEDstatus == Green_Off){
		 // DPRINTF("GREEN LED is OFF\n\n");
		SET_BIT(GPIOA_ODR,10);
	}
	else if (LEDstatus == Yellow_On){
		// DPRINTF("YELLOW LED is ON !!\n\n");
		RESET_BIT(GPIOA_ODR,11);
	}
	else if (LEDstatus == Yellow_Off){
		// DPRINTF("\nYELLOW LED is OFF\n\n");
		SET_BIT(GPIOA_ODR,11);
	}
	else if (LEDstatus == Red_On){
		// DPRINTF("RED LED is ON !!\n");
		RESET_BIT(GPIOA_ODR,12);
	}
	else if (LEDstatus == Red_Off){
		// DPRINTF("RED LED is OFF\n\n");
		SET_BIT(GPIOA_ODR,12);
	}
}

void GPIO_INITIALIZATION (){
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0000FF;
	GPIOA_CRH |= 0x22222222;
}
