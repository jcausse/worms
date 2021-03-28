/*
* mainHeader.h - This is the main header of the project. It contains all the includes and general purpose classes needed by
* most of the files in the project
*/

#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H

//INCLUDES
//	1. Standard C++ libraries
#include <iostream>
#include <string>

//	2. Standard C libraries (legacy)
#ifdef __cplusplus
extern "C" {
#endif
#include <stdlib.h>
#include <math.h>
#ifdef __cplusplus
}
#endif

//	3. Non-standard libraries
#include "constants.h"

#endif /*MAIN_HEADER_H*/