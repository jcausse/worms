/*
* worms.h - Header file for worms objects
*/

#ifndef WORMS_H
#define WORMS_H

//INCLUDES
#include "generalHeader.h"
#include "input.h"

//CLASSES
class Worm {
public:
	//Constructor
	Worm(float initialXPosition, float initialYPosition);
	//int state;

	//Data members
	float x;
	float y;
	int wormmoves;
	int salto;
	bool wormsteady;
	int salto_cooldown;
	bool salto_lock;
	bool wormright;
};

void move_worms(Worm* worm1, Worm* worm2, Keys* key);

#endif // WORMS_H 