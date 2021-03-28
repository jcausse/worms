#ifndef VISUAL_H
#define VISUAL_H

//INCLUDES
#include "mainHeader.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>

//STRUCTURES
typedef struct {
	ALLEGRO_DISPLAY* display;
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
	ALLEGRO_EVENT_QUEUE* eventQueue;
	ALLEGRO_FONT* font;
};
#endif /* VISUAL_H */