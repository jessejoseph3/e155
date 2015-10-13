//lab5.c
//uses GPIO to play fur elise
//jjoseph@hmc.edu

#include "lab5_starter.c"
#include "lab5_gpio.c"
#include "lab5_timers.c"
#include "lab5_extrasong.c"


#define OUTPUTPIN 5

void play_note(int freq, int millis){
	if(freq == 0){						//for rest note 0Hz, just pause for millis
		delayMicros(millis*1000);
	}
	
	else{
		int halfPeriodMicros = 500000/freq;		//else find half the period
		int numCycles = (freq*millis)/1000;		//and the number of cycles that corresponds to duration
		int i;
		for(i = 0; i < numCycles; i++){			//iterate fornumber of cycles
			digitalWrite(OUTPUTPIN,0);			//pin lo for half of the period
			delayMicros(halfPeriodMicros);
			digitalWrite(OUTPUTPIN,1);			//hi for half the period
			delayMicros(halfPeriodMicros);
		}
	}
}

void main(){
	pioInit();				//initialize gpio memory map
	timerInit();			//initialize timer memory map
	pinMode(OUTPUTPIN,OUTPUT);	//initialize output pin
	int songSel;				//will be used to choose song to play
	printf("Select a song: ");	//prompt user
	scanf("%d", &songSel);		//get user input
	if(songSel == 0){			//if user pressed 0, song is Fur Elise
		printf("\n You selected Fur Elise \n");
	}
	else if(songSel == 1){		//if user pressed 1, song is Song of Time
		printf("\n You selected the Song of Time \n");
	}
	else{						//else, song is song of Storms
		printf("\n You selected the Song of Storms \n");
	}
	const int *note;			//note is an array so must be a pointer
	int i = 0;
	note = emptyNote;			//get first empty note to initialize loop
	while(!(note[1] == 0)){		//keep going until a 0 duration note is reached
		if(songSel == 0){		//if fur elise, get fur elise note
			note = notes[i];
		}
		else if(songSel == 1){	//if song of time, get song o ftime note 
			note = songOfTime[i];
		}
		else{					//else get song of storms note
			note = songOfStorms[i];	
		}
		play_note(note[0],note[1]);	//play the note
		i++;					//increment note
	}
}