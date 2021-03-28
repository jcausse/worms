#ifndef VISUAL_H
#define VISUAL_H

//INCLUDES
#include "allegroMain.h"
#include "worms.h"

//PROTOTYPES
void allegroClearToBackground(allegroPtrs_t*);
//This function clears the display, leaving only the background visible
void allegroDrawWorm(allegroPtrs_t*, Worm);
//This function draws the worm. "Worm" is a Worm object defined in worms.h

#endif /*VISUAL_H*/