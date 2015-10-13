//lab5_timers.c
//functions for using system timers to set delays
//jjoseph@hmc.edu
#include <stdio.h>

#define TIMER_BASE (volatile unsigned int *) 0x3F003000

void delayMicros(unsigned int micros)
{
	TIMER_BASE[0] = 0b0010;					//clear M1
	TIMER_BASE[4] = TIMER_BASE[1] + micros;	//set comparison to be CLo + micros
	while(~TIMER_BASE[0] & 0b0010);			//wait until match
}
