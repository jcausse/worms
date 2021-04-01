/*
* allegroMain.h - main header for functions that manage Allegro's initialization and destroys.
* This functions are needed to be able to use both input and visual cpp/h duos.
* 
*/

#ifndef ALLEGRO_MAIN_H
#define ALLEGRO_MAIN_H

//INCLUDES
#include "generalHeader.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

//STRUCTURES
	//This structure contains pointers to all objects created and used by Allegro. This is needed to have separate
	//functions for initialization, drawing, and destroys
typedef struct {
	//Display
	ALLEGRO_DISPLAY* display;
	//Bitmaps
	ALLEGRO_BITMAP* background;
	//Bitmap pointer arrays
	ALLEGRO_BITMAP* wjumpArr[WJUMP_FRAMES];
	ALLEGRO_BITMAP* wwalkArr[WWALK_FRAMES];
	//Timer
	ALLEGRO_TIMER* tickTimer;
	//Other
	ALLEGRO_EVENT_QUEUE* eventQueue;
	ALLEGRO_FONT* font;
}allegroPtrs_t;

//PROTOTYPES
allegroPtrs_t* allegroInit(void);
	//This function initializes Allegro and all needed addons
	//allegroPtrs_t * is a pointer to a allegroPtrs_t - type structure which will contain all the pointers to the Allegro - created objects
	//The structure is allocated in the heap.
void allegroDestroy(allegroPtrs_t*);
	//This function destroys all Allegro - created resources / objects

#endif /*ALLEGRO_MAIN_H*/

