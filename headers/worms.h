/*
* worms.h - Header file for worms objects
*/

#ifndef WORMS_H
#define WORMS_H

//INCLUDES
#include "generalHeader.h"
#include "input.h"
#include "allegroMain.h"

//CLASSES
class Worm {
public:
	//Constructor
	Worm(float initialXPosition, float initialYPosition);	//Explicit worm constructor with initial position
	//int state;

	//Data members
	float x;				//X-axis position
	float y;				//Y-axis position			
	int salto;				//Counter for jump height
	bool wormsteady;		//Equals "true" if the worm is NOT moving
	int salto_cooldown;
	bool salto_lock;		//Equals "true" if the worm is jumping. Ignores keyboard input while "true"
	bool wormright;			//Equals "true" if the worm is facing right
	int wormframe;			//Frame to draw 
	int wormstate;			//state of the worm
	int keyUpTimer;         //Timer to wait 100 ms when de key up is pressed
	int keyRightTimer;		//Timer to wait 100 ms when de key right is pressed
	int keyLeftTimer;		//Timer to wait 100 ms when de key left is pressed


	//Movement methods
	void go_up(void);		
	void go_right(void);
	void go_left(void);
	void jumping(void);
	void released_up(void);
};

void move_worms(Worm& worm1, Worm& worm2, Keys& key);	//Moves worms
bool collidewborder(float x);							//Check if the worm collides with a screen border
bool isjumping(float y);								//Checks if the worm is jumping

#endif // WORMS_H 