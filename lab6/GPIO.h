//lab5_gpio.c
//basic gpio functions for reading and writing digital pins
//jjoseph@hmc.edu
#include "STARTER.h"
#define LEDPIN 21

void pinMode(int pin, int type)
{	
	if(pin<0 | pin > 54){
		printf("invalid pin");
	}
	else{
		unsigned int offset = pin/10;		//address offset for GPFSEL
		unsigned int shift = (pin%10)*3;	//shift to appropriate 3 bit pin function select
		GPFSEL[offset] &= ~(7 << shift);	//bitmask current signal with to clear current Fselect
		GPFSEL[offset] |= type << shift;	//input new Fselect
	}
}

void digitalWrite(int pin, int val)
{	
	unsigned int offset = pin/31;			//determines if clr/set is clr/set 0 or 1
	unsigned int shift = pin%31;			//shift amount to find specific pin in clr/set signals
	if(pin < 0 | pin > 54){
		printf("invalid pin");
	}
	else if(val == 0){
		GPCLR[offset] &= 1 << shift; 		//if writing a 0 to pin, write 1 to appropriate clear index
	}
	else if(val == 1){
		GPSET[offset] &= 1 << shift;		//if writing a 1 to pin, write 1 to appropriate set index
	}
	else{
		printf("invalid write value");
	}
}

