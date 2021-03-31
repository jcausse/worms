#include "../headers/allegroMain.h"
#include "../headers/visual.h"

bool allegroRedraw(allegroPtrs_t* allegroPtrs, Worm& worm1, Worm& worm2, bool* doRedraw){
	if (!(*doRedraw))
		return BOOL_SUCCESS;
	allegroClearToBackground(allegroPtrs);
	if (!allegroDrawWorm(allegroPtrs, worm1))
		return BOOL_FAIL;
	if (!allegroDrawWorm(allegroPtrs, worm2))
		return BOOL_FAIL;
	*doRedraw = false;
	return BOOL_SUCCESS;
}

void allegroClearToBackground(allegroPtrs_t* allegroPtrs) {
	al_draw_bitmap(allegroPtrs->background, 0, 0, 0);
	al_flip_display();
}

bool allegroDrawWorm(allegroPtrs_t* allegroPtrs, Worm& worm){
	int flip = ((worm.wormright == true) ? ALLEGRO_FLIP_HORIZONTAL : 0); //Worms are facing left by default
	switch (worm.state) {
		case walking:
			al_draw_bitmap(allegroPtrs->wwalkArr[worm.frame], worm.x, worm.y, flip);
			break;
		case startingJump:
			/*!*/
			break;
		case jumping:
			/*!*/
			break;
		default:
			fprintf(stderr, "visual.cpp -> allegroDrawWorm. Internal error.\n");
			return BOOL_FAIL;
	}
	return BOOL_SUCCESS;
}

/*
enum wormStates {
	idle = 0,
	walking,
	startingJump,
	jumping
};
*/