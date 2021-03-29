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

//CONSTANTS
#define WJUMP_FRAMES 10
#define WWALK_FRAMES 15

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
	//Other
	ALLEGRO_EVENT_QUEUE* eventQueue;
	ALLEGRO_FONT* font;
	bool redraw;
	bool do_exit;
}allegroPtrs_t;

//PROTOTYPES
allegroPtrs_t* allegroInit(void);
	//This function initializes Allegro and all needed addons
	//allegroPtrs_t * is a pointer to a allegroPtrs_t - type structure which will contain all the pointers to the Allegro - created objects
	//The structure is allocated in the heap.
void allegroDestroy(allegroPtrs_t*);
	//This function destroys all Allegro - created resources / objects

#endif /*ALLEGRO_MAIN_H*/

/*
typedef struct {
	//Display
	ALLEGRO_DISPLAY* display;
	//Bitmaps
	ALLEGRO_BITMAP* background;
	ALLEGRO_BITMAP* wjumpF1;
	ALLEGRO_BITMAP* wjumpF2;
	ALLEGRO_BITMAP* wjumpF3;
	ALLEGRO_BITMAP* wjumpF4;
	ALLEGRO_BITMAP* wjumpF5;
	ALLEGRO_BITMAP* wjumpF6;
	ALLEGRO_BITMAP* wjumpF7;
	ALLEGRO_BITMAP* wjumpF8;
	ALLEGRO_BITMAP* wjumpF9;
	ALLEGRO_BITMAP* wjumpF10;
	ALLEGRO_BITMAP* wwalkF1;
	ALLEGRO_BITMAP* wwalkF2;
	ALLEGRO_BITMAP* wwalkF3;
	ALLEGRO_BITMAP* wwalkF4;
	ALLEGRO_BITMAP* wwalkF5;
	ALLEGRO_BITMAP* wwalkF6;
	ALLEGRO_BITMAP* wwalkF7;
	ALLEGRO_BITMAP* wwalkF8;
	ALLEGRO_BITMAP* wwalkF9;
	ALLEGRO_BITMAP* wwalkF10;
	ALLEGRO_BITMAP* wwalkF11;
	ALLEGRO_BITMAP* wwalkF12;
	ALLEGRO_BITMAP* wwalkF13;
	ALLEGRO_BITMAP* wwalkF14;
	ALLEGRO_BITMAP* wwalkF15;
	//Bitmap pointer arrays
	ALLEGRO_BITMAP* wjumpArr[10];
	ALLEGRO_BITMAP* wwalkArr[15];
	//Other
	ALLEGRO_EVENT_QUEUE* eventQueue;
	ALLEGRO_FONT* font;
}allegroPtrs_t;
*/