#ifndef INPUT_H
#define INPUT_H

//INCLUDES
#include "generalHeader.h"
#include "visual.h"

//CLASSES
class keys_t 
{
public:
	//Constructor
	keys_t(float initialXPosition, float initialYPosition);

	//Data members
	bool key_up;
	bool key_down;
	bool key_left;
	bool key_right;

	bool key_w;
	bool key_s;
	bool key_a;
	bool key_d;
};

void check_input(allegroPtrs_t* allegro, keys_t* key);

#endif /* INPUT_H */