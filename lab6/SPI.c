//SPI.h
//SPI functionality for e155 lab6

#include "GPIO.h"
#define SPI_BASE 0x3F204000

volatile unsigned int *spi0; //pointer to base of gpio

void SPImmap() {
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
      SPI_BASE);       // Offset to GPIO peripheral

	if (reg_map == MAP_FAILED) {
      printf("gpio mmap error %d\n", (int)reg_map);
      close(mem_fd);
      exit(-1);
    }

	spi0 = (volatile unsigned *)reg_map;
}




void SPIinit(int freq, int settings)
{
	SPImmap();
	pinMode(7,ALT0);
	pinMode(9,ALT0);
	pinMode(10,ALT0);
	pinMode(11,ALT0);

	spi0[2] = 250000000/freq;
	spi0[0] = settings;
	spi0[0] |= 1 << 7;
}

char spiXFer(char data_out)
{
	spi0[1] = data_out;
	while(!spi0[0]& (1<<4));
	return spi0[1];
}

int main(void)
{
	pioInit();
	SPIinit(100000,0x0);
	char data = spiXFer('0');

	printf("%s%c%c\n", "Content-Type:text/html;charset=iso-8859-1",13,10);

	printf("<META HTTP-EQUIV=\"Refresh\" CONTENT=\"0;url=/ledcontrol.html/voltage=%d\">",data);
	return 0;

}