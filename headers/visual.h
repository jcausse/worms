#ifndef VISUAL_H
#define VISUAL_H

//INCLUDES
#include "mainHeader.h"
#include "worms.h"
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

//PROTOTYPES
allegroPtrs_t* allegroInit(void);
//This function initializes Allegro and all needed addons
//allegroPtrs_t * is a pointer to a allegroPtrs_t - type structure which will contain all the pointers to the Allegro - created objects
void allegroDestroy(allegroPtrs_t*);
//This function destroys all Allegro - created resources / objects
void allegroClearToBackground(allegroPtrs_t*);
//This function clears the display, leaving only the background visible
void allegroDrawWorm(allegroPtrs_t*, Worm);
//This function draws the worm. "Worm" is a Worm object defined in worms.h

