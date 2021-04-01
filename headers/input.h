#ifndef INPUT_H
#define INPUT_H

//INCLUDES
#include "allegroMain.h"

//CLASSES
class Keys{
public:
	//Constructor

	//Data members
	bool keyUp;
	bool keyLeft;
	bool keyRight;

	bool keyW;
	bool keyA;
	bool keyD;
};

void checkInput (allegroPtrs_t *, Keys&, bool *, bool *); //Function that checks the keyboard input

#endif /* INPUT_H */
