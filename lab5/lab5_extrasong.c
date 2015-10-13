//lab5_extrasong
//frequency-duration array of notes for legend of zelda song of time

//		NOTE 	DURATION
#define EIGTH	250
#define QUARTER 500
#define HALF	1000
#define WHOLE	2000
		
//		NOTE 	FREQ
#define C3		262
#define D3		294
#define E3		330
#define F3		349
#define G3		392
#define A4		440
#define B4		494
#define C4		523


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
}