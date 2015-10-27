//SPI.h
//SPI functionality for e155 lab6

#include "GPIO.h"
#define SPIBASE (volatile unsigned int *) 0x3F204000
void SPIinit(int freq, int settings)
{
	pinMode(7,ALT0);
	pinMode(9,ALT0);
	pinMode(10,ALT0);
	pinMode(11,ALT0);

	SPIBASE[2] = 250000000/freq;
	SPIBASE[0] = settings;
	SPIBASE[0] |= 1 << 7;
}

char spiXFer(char data_out)
{
	SPIBASE[1] = data_out;
	while(!SPIBASE[0]& (1<<4));
	return SPIBASE[1];
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