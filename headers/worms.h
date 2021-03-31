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

	void go_up(void);
	void go_right(void);
	void go_left(void);
	void jumping(void);
	void released_up(void);
};

void move_worms(Worm* worm1, Worm* worm2, Keys* key);
int collidewborder(float x,float y);
int isjumping(float y);

#endif // WORMS_H 