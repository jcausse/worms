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
	Worm(float initialXPosition, float initialYPosition);	//Explicit worm constructor with initial position
	//int state;

	//Data members
	float x;				//X-axis position
	float y;				//Y-axis position
	int wormmoves;
	int salto;
	bool wormsteady;		//Equals "true" if the worm is NOT moving
	int salto_cooldown;
	bool salto_lock;
	bool wormright;			//Equals "true" if the worm is facing right

	//Movement methods
	void go_up(void);		
	void go_right(void);
	void go_left(void);
	void jumping(void);
	void released_up(void);
};

void move_worms(Worm* worm1, Worm* worm2, Keys* key);	
int collidewborder(float x,float y);					//Check if the worm collides with a screen border
int isjumping(float y);

#endif // WORMS_H 