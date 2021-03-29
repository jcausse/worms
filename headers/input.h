#ifndef INPUT_H
#define INPUT_H

//INCLUDES
#include "generalHeader.h"
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

void checkInput(allegroPtrs_t* allegro, Keys* key, bool* redraw, bool* do_exit);

#endif /* INPUT_H */
