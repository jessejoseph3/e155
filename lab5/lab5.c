//lab5.c
//uses GPIO to play fur elise
//jjoseph@hmc.edu

#include "lab5_starter.c"
#include "lab5_gpio.c"
#include "lab5_timers.c"
#include "lab5_extrasong.c"


#define OUTPUTPIN 5

void play_note(int freq, int millis){
	if(freq == 0){
		delayMicros(millis*1000);
	}
	
	else{
		int halfPeriodMicros = 500000/freq;
		int numCycles = (freq*millis)/1000;
		int i;
		for(i = 0; i < numCycles; i++){
			digitalWrite(OUTPUTPIN,0);
			delayMicros(halfPeriodMicros);
			digitalWrite(OUTPUTPIN,1);
			delayMicros(halfPeriodMicros);
		}
	}
}

void main(){
	pioInit();
	timerInit();
	pinMode(OUTPUTPIN,OUTPUT);
	int songSel;
	printf("Select a song: ");
	scanf("%d", &songSel);
	int *note;
	int i = 0;
	while(!(note[1] == 0)){
		if(songSel == 0){
			note = notes[i];
		}
		else if(songSel == 1){
			note = songOfTime[i];
		}
		else{
			note = songOfStorms[i];
		}
		play_note(note[0], note[1]);
		i++;
	}
}