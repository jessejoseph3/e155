// Turn off LED

#include "GPIO.h"
int main(void)
{

        //Turn of LED	
	SetUpPerif();
	setPinType(LEDPIN, OUTPUT);
	digitalWrite(LEDPIN, 0);

	//Print header and redirect
	printf("%s%c%c\n",
		"Content-Type:text/html;charset=iso-8859-1",13,10);
	printf("<META HTTP-EQUIV=\"Refresh\" CONTENT=\"0;url=/ledcontrol.html\">");
	return 0;

}
