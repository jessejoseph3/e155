//lab5_extrasong
//frequency-duration array of notes for legend of zelda song of time and song of storms

//		NOTE 		DURATION
#define EIGTH		250
#define QUARTER 	500
#define HALF		1000
#define WHOLE		2000
#define EIGTH180	167
#define QUARTER180	333
#define HALF180		666
#define WHOLE180	1332	
		
//		NOTE 	FREQ
#define C3		262
#define D3		294
#define E3		330
#define F3		349
#define G3		392
#define A4		440
#define Bb		466
#define B4		494
#define C4		523
#define D4		587
#define E4		659
#define F4		698


const int songOfTime[][2] = {
	{A4,	QUARTER},
	{D3,	HALF},
	{F3,	QUARTER},
	{A4,	QUARTER},
	{D3,	HALF},
	{F3,	QUARTER},
	{A4,	EIGTH},
	{C4,	EIGTH},
	{B4,	QUARTER},
	{G3,	QUARTER},
	{F3,	EIGTH},
	{G3,	EIGTH},
	{A4,	QUARTER},
	{D3,	QUARTER},
	{C3,	EIGTH},
	{E3,	EIGTH},
	{D3,	HALF},
	{D3,	WHOLE},
	{0,		0}
};

const int songOfStorms[][2] = {
	{D3,	EIGTH180},
	{F3, 	EIGTH180},
	{D4,	HALF180},
	{D3,	EIGTH180},
	{F3, 	EIGTH180},
	{D4,	HALF180},
	{E4,	QUARTER180},
	{E4,	EIGTH180},
	{F4,	EIGTH180},
	{E4,	EIGTH180},
	{F4,	EIGTH180},
	{E4,	EIGTH180},
	{C4,	EIGTH180},
	{A4,	HALF180},
	{A4,	QUARTER180},
	{D3,	QUARTER180},
	{F3,	EIGTH180},
	{G3,	EIGTH180},
	{A4,	HALF180},		
	{A4,	QUARTER180},
	{0,		QUARTER180},
	{A4,	QUARTER180},
	{D3,	QUARTER180},
	{F3,	EIGTH180},
	{G3,	EIGTH180},
	{E3,	HALF180},
	{E3,	QUARTER180},
	{0,		QUARTER180},
	{D3,	EIGTH180},
	{F3, 	EIGTH180},
	{D4,	HALF180},
	{D3,	EIGTH180},
	{F3, 	EIGTH180},
	{D4,	HALF180},
	{E4,	QUARTER180},
	{E4,	EIGTH180},
	{F4,	EIGTH180},
	{E4,	EIGTH180},
	{F4,	EIGTH180},
	{E4,	EIGTH180},
	{C4,	EIGTH180},
	{A4,	HALF180},
	{A4,	QUARTER180},
	{D3,	QUARTER180},
	{F3,	EIGTH180},
	{G3,	EIGTH180},
	{A4,	QUARTER180},			
	{A4,	EIGTH180},
	{0,		QUARTER180},
	{A4,	EIGTH180},
	{D3,	HALF180},
	{0,		0}
};

const int emptyNote[2] = {0,1};