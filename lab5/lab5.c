//lab5.c
//uses GPIO to play fur elise
//jjoseph@hmc.edu

#include "lab5_starter.c"
#include "lab5_gpio.c"
#include "lab5_timers.c"


#define OUTPUTPIN 5

void play_note(int freq, int millis){
	int halfPeriodMicros = 500000/freq;
	int numCycles = freq*millis/1000;
	int i;
	for(i = 0; i < numCycles; i++){
		digitalWrite(OUTPUTPIN,0);
		delayMicros(halfPeriodMicros);
		digitalWrite(OUTPUTPIN,1);
		delayMicros(halfPeriodMicros);
	}
}

void main(){
	//pioInit();
	timerInit();
	printf("start");
	delayMicros(1000000);
	printf("done");
	//pinMode(OUTPUTPIN,OUTPUT);
	//digitalWrite(OUTPUTPIN,1);
	//for(int i = 0; i < 108; i++){
	//	play_note(notes[i][0], notes[i][1]);
	//}
}