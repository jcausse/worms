/*
* constants.h - General constants file.
*/

#ifndef CONSTANTS_H
#define CONSTANTS_H

//CONSTANTS RETURNED BY FUNCTIONS
//  1. bool-returning functions
#define BOOL_SUCCESS true
#define BOOL_FAIL false

//  2. int-returning functions
#define INT_SUCCESS 0
#define INT_FAIL -1

//  3. pointer-returning functions
#define POINTER_FAIL NULL

//GENERAL CONSTANTS
#define REFRESH_RATE_HZ 50	//Set refresh rate to 50 Hz. This means the display is updated every 0.02 seconds
#define REFRESH_RATE_S 0.02
#define GRAVITY 0.24
#define BORDEXIZQ 701
#define BORDEXDER 1212
#define PISOY 616
#define SIZEWORM 60


//MOVEMENT CONSTANTS
#define MOVE_RATE 2.0
#define SALTO_COOLDOWN 30
#define SALTO_H 10
#define SALTO_SPEED 1
#define WJUMP_FRAMES 10	//Amount of different images used to jump
#define WWALK_FRAMES 15 //Amount of different images used to walk

#endif /* CONSTANTS_H */