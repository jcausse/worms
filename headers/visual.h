#ifndef VISUAL_H
#define VISUAL_H

//INCLUDES
#include "allegroMain.h"
#include "worms.h"

//PROTOTYPES
bool allegroRedraw(allegroPtrs_t* allegroPtrs, Worm& worm1, Worm& worm2, bool* doRedraw);
//This function manages the entire redraw process using Allegro
void allegroClearToBackground(allegroPtrs_t* allegroPtrs);
//This function clears the display, leaving only the background visible
bool allegroDrawWorm(allegroPtrs_t* allegroPtrs, Worm& worm);
//This function draws the worm. "Worm" is a Worm object defined in worms.h

#endif /*VISUAL_H*/