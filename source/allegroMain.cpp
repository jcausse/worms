#include "../headers/allegroMain.h"

#define WJUMP_MACRO(x) 

allegroPtrs_t* allegroInit(void) {
	allegroPtrs_t* allegroPtrs = (allegroPtrs_t*) malloc(sizeof(allegroPtrs_t));

    //RESOURCES DECLARATION AND NULL INITIALIZATION
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_BITMAP* background =NULL ;
    ALLEGRO_BITMAP* wjumpArr[WJUMP_FRAMES];
    ALLEGRO_BITMAP* wwalkArr[WWALK_FRAMES];
    ALLEGRO_EVENT_QUEUE* eventQueue = NULL;
    ALLEGRO_FONT* font = NULL;
    for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
        if (i < WJUMP_FRAMES)
            wjumpArr[i] = NULL;
        if (i < WWALK_FRAMES)
            wwalkArr[i] = NULL;
    }

    //ALLEGRO AND ALLEGRO ADDONS INITIALIZATION
    if (!al_init()) {
        fprintf(stderr, "Failed to initialize allegro!\n");
        return POINTER_FAIL;
    }
    if (!al_init_image_addon()) {
        fprintf(stderr, "Failed to initialize image addon!\n");
        return POINTER_FAIL;
    }
    if (!al_init_font_addon()) {
        fprintf(stderr, "Failed to initialize allegro fonts!\n");
        return POINTER_FAIL;
    }
    if (!al_init_ttf_addon()) {
        fprintf(stderr, "Failed to initialize allegro ttf fonts!\n");
        return POINTER_FAIL;
    }

    //ALLEGRO RESOURCES INITIALIZATION
   font = al_load_font("../resources/arial.ttf", 20, 0);
    if (!font) {
        fprintf(stderr, "Failed to create font!\n");
        return POINTER_FAIL;
    }
    background = al_load_bitmap("../resources/background.png");
    if (!background) {
        fprintf(stderr, "Failed to load background.png\n");
        al_destroy_font(font);
        return POINTER_FAIL;
    }

    wwalkArr[0] = al_load_bitmap("../resources/wwalk/wwalkF1.png");
    if (!wwalkArr[0]) {
        fprintf(stderr, "Failed to load wwalkF1.png\n");
        al_destroy_font(font);
        al_destroy_bitmap(background);
        for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
            if (i < WJUMP_FRAMES) {
                if (wjumpArr[i] != NULL) {
                    al_destroy_bitmap(wjumpArr[i]);
                }
            }
            if (i < WWALK_FRAMES) {
                if (wwalkArr[i] != NULL) {
                    al_destroy_bitmap(wwalkArr[i]);
                }
            }
        }
        return POINTER_FAIL;
    }
    wwalkArr[1] = al_load_bitmap("../resources/wwalk/wwalkF2.png");
    if (!wwalkArr[1]) {
        fprintf(stderr, "Failed to load wwalkF2.png\n");
        al_destroy_font(font);
        al_destroy_bitmap(background);
        for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
            if (i < WJUMP_FRAMES) {
                if (wjumpArr[i] != NULL) {
                    al_destroy_bitmap(wjumpArr[i]);
                }
            }
            if (i < WWALK_FRAMES) {
                if (wwalkArr[i] != NULL) {
                    al_destroy_bitmap(wwalkArr[i]);
                }
            }
        }
        return POINTER_FAIL;
    }
    wwalkArr[2] = al_load_bitmap("../resources/wwalk/wwalkF3.png");
    if (!wwalkArr[2]) {
        fprintf(stderr, "Failed to load wwalkF3.png\n");
        al_destroy_font(font);
        al_destroy_bitmap(background);
        for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
            if (i < WJUMP_FRAMES) {
                if (wjumpArr[i] != NULL) {
                    al_destroy_bitmap(wjumpArr[i]);
                }
            }
            if (i < WWALK_FRAMES) {
                if (wwalkArr[i] != NULL) {
                    al_destroy_bitmap(wwalkArr[i]);
                }
            }
        }
        return POINTER_FAIL;
    }
    wwalkArr[3] = al_load_bitmap("../resources/wwalk/wwalkF4.png");
    if (!wwalkArr[3]) {
        fprintf(stderr, "Failed to load wwalkF4.png\n");
        al_destroy_font(font);
        al_destroy_bitmap(background);
        for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
            if (i < WJUMP_FRAMES) {
                if (wjumpArr[i] != NULL) {
                    al_destroy_bitmap(wjumpArr[i]);
                }
            }
            if (i < WWALK_FRAMES) {
                if (wwalkArr[i] != NULL) {
                    al_destroy_bitmap(wwalkArr[i]);
                }
            }
        }
        return POINTER_FAIL;
    }wwalkArr[4] = al_load_bitmap("../resources/wwalk/wwalkF5.png");
    if (!wwalkArr[4]) {
        fprintf(stderr, "Failed to load wwalkF5.png\n");
        al_destroy_font(font);
        al_destroy_bitmap(background);
        for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
            if (i < WJUMP_FRAMES) {
                if (wjumpArr[i] != NULL) {
                    al_destroy_bitmap(wjumpArr[i]);
                }
            }
            if (i < WWALK_FRAMES) {
                if (wwalkArr[i] != NULL) {
                    al_destroy_bitmap(wwalkArr[i]);
                }
            }
        }
        return POINTER_FAIL;
    }
    wwalkArr[5] = al_load_bitmap("../resources/wwalk/wwalkF6.png");
    if (!wwalkArr[5]) {
        fprintf(stderr, "Failed to load wwalkF6.png\n");
        al_destroy_font(font);
        al_destroy_bitmap(background);
        for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
            if (i < WJUMP_FRAMES) {
                if (wjumpArr[i] != NULL) {
                    al_destroy_bitmap(wjumpArr[i]);
                }
            }
            if (i < WWALK_FRAMES) {
                if (wwalkArr[i] != NULL) {
                    al_destroy_bitmap(wwalkArr[i]);
                }
            }
        }
        return POINTER_FAIL;
    }
    wwalkArr[6] = al_load_bitmap("../resources/wwalk/wwalkF7.png");
    if (!wwalkArr[6]) {
        fprintf(stderr, "Failed to load wwalkF7.png\n");
        al_destroy_font(font);
        al_destroy_bitmap(background);
        for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
            if (i < WJUMP_FRAMES) {
                if (wjumpArr[i] != NULL) {
                    al_destroy_bitmap(wjumpArr[i]);
                }
            }
            if (i < WWALK_FRAMES) {
                if (wwalkArr[i] != NULL) {
                    al_destroy_bitmap(wwalkArr[i]);
                }
            }
        }
        return POINTER_FAIL;
    }wwalkArr[7] = al_load_bitmap("../resources/wwalk/wwalkF8.png");
    if (!wwalkArr[7]) {
        fprintf(stderr, "Failed to load wwalkF8.png\n");
        al_destroy_font(font);
        al_destroy_bitmap(background);
        for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
            if (i < WJUMP_FRAMES) {
                if (wjumpArr[i] != NULL) {
                    al_destroy_bitmap(wjumpArr[i]);
                }
            }
            if (i < WWALK_FRAMES) {
                if (wwalkArr[i] != NULL) {
                    al_destroy_bitmap(wwalkArr[i]);
                }
            }
        }
        return POINTER_FAIL;
    }
    wwalkArr[8] = al_load_bitmap("../resources/wwalk/wwalkF9.png");
    if (!wwalkArr[8]) {
        fprintf(stderr, "Failed to load wwalkF9.png\n");
        al_destroy_font(font);
        al_destroy_bitmap(background);
        for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
            if (i < WJUMP_FRAMES) {
                if (wjumpArr[i] != NULL) {
                    al_destroy_bitmap(wjumpArr[i]);
                }
            }
            if (i < WWALK_FRAMES) {
                if (wwalkArr[i] != NULL) {
                    al_destroy_bitmap(wwalkArr[i]);
                }
            }
        }
        return POINTER_FAIL;
    }
    wwalkArr[9] = al_load_bitmap("../resources/wwalk/wwalkF10.png");
    if (!wwalkArr[9]) {
        fprintf(stderr, "Failed to load wwalkF10.png\n");
        al_destroy_font(font);
        al_destroy_bitmap(background);
        for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
            if (i < WJUMP_FRAMES) {
                if (wjumpArr[i] != NULL) {
                    al_destroy_bitmap(wjumpArr[i]);
                }
            }
            if (i < WWALK_FRAMES) {
                if (wwalkArr[i] != NULL) {
                    al_destroy_bitmap(wwalkArr[i]);
                }
            }
        }
        return POINTER_FAIL;
    }
    wwalkArr[10] = al_load_bitmap("../resources/wwalk/wwalkF11.png");
    if (!wwalkArr[10]) {
        fprintf(stderr, "Failed to load wwalkF11.png\n");
        al_destroy_font(font);
        al_destroy_bitmap(background);
        for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
            if (i < WJUMP_FRAMES) {
                if (wjumpArr[i] != NULL) {
                    al_destroy_bitmap(wjumpArr[i]);
                }
            }
            if (i < WWALK_FRAMES) {
                if (wwalkArr[i] != NULL) {
                    al_destroy_bitmap(wwalkArr[i]);
                }
            }
        }
        return POINTER_FAIL;
    }
    wwalkArr[11] = al_load_bitmap("../resources/wwalk/wwalkF12.png");
    if (!wwalkArr[11]) {
        fprintf(stderr, "Failed to load wwalkF12.png\n");
        al_destroy_font(font);
        al_destroy_bitmap(background);
        for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
            if (i < WJUMP_FRAMES) {
                if (wjumpArr[i] != NULL) {
                    al_destroy_bitmap(wjumpArr[i]);
                }
            }
            if (i < WWALK_FRAMES) {
                if (wwalkArr[i] != NULL) {
                    al_destroy_bitmap(wwalkArr[i]);
                }
            }
        }
        return POINTER_FAIL;
    }
    wwalkArr[12] = al_load_bitmap("../resources/wwalk/wwalkF13.png");
    if (!wwalkArr[12]) {
        fprintf(stderr, "Failed to load wwalkF13.png\n");
        al_destroy_font(font);
        al_destroy_bitmap(background);
        for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
            if (i < WJUMP_FRAMES) {
                if (wjumpArr[i] != NULL) {
                    al_destroy_bitmap(wjumpArr[i]);
                }
            }
            if (i < WWALK_FRAMES) {
                if (wwalkArr[i] != NULL) {
                    al_destroy_bitmap(wwalkArr[i]);
                }
            }
        }
        return POINTER_FAIL;
    }
    wwalkArr[13] = al_load_bitmap("../resources/wwalk/wwalkF14.png");
    if (!wwalkArr[13]) {
        fprintf(stderr, "Failed to load wwalkF14.png\n");
        al_destroy_font(font);
        al_destroy_bitmap(background);
        for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
            if (i < WJUMP_FRAMES) {
                if (wjumpArr[i] != NULL) {
                    al_destroy_bitmap(wjumpArr[i]);
                }
            }
            if (i < WWALK_FRAMES) {
                if (wwalkArr[i] != NULL) {
                    al_destroy_bitmap(wwalkArr[i]);
                }
            }
        }
        return POINTER_FAIL;
    }
    wwalkArr[14] = al_load_bitmap("../resources/wwalk/wwalkF15.png");
    if (!wwalkArr[14]) {
        fprintf(stderr, "Failed to load wwalkF15.png\n");
        al_destroy_font(font);
        al_destroy_bitmap(background);
        for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
            if (i < WJUMP_FRAMES) {
                if (wjumpArr[i] != NULL) {
                    al_destroy_bitmap(wjumpArr[i]);
                }
            }
            if (i < WWALK_FRAMES) {
                if (wwalkArr[i] != NULL) {
                    al_destroy_bitmap(wwalkArr[i]);
                }
            }
        }
        return POINTER_FAIL;
    }
}
void allegroDestroy(allegroPtrs_t* allegroPtrs) {
	free(allegroPtrs);
}