//lab5_timers.c
//functions for using system timers to set delays
//jjoseph@hmc.edu
#include <stdio.h>

#define TIMER 0x3F003000

volatile unsigned int *timer_base

void timerInit() {
	int  mem_fd;
	void *reg_map;

	// /dev/mem is a psuedo-driver for accessing memory in the Linux filesystem
	if ((mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0) {
	      printf("can't open /dev/mem \n");
	      exit(-1);
	}

	reg_map = mmap(
	  NULL,             //Address at which to start local mapping (null means don't-care)
      BLOCK_SIZE,       //Size of mapped memory block
      PROT_READ|PROT_WRITE,// Enable both reading and writing to the mapped memory
      MAP_SHARED,       // This program does not have exclusive access to this memory
      mem_fd,           // Map to /dev/mem
      TIMER);       // Offset to GPIO peripheral

	if (reg_map == MAP_FAILED) {
      printf("gpio mmap error %d\n", (int)reg_map);
      close(mem_fd);
      exit(-1);
    }

	timer_base = (volatile unsigned *)reg_map;
}

void delayMicros(unsigned int micros)
{
	timer_base[0] = 0b0010;					//clear M1
	timer_base[4] = timer_base[1] + micros;	//set comparison to be CLo + micros
	while(~timer_base[0] & 0b0010);			//wait until match
}
