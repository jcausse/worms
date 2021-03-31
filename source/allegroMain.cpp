#include "../headers/allegroMain.h"

allegroPtrs_t* allegroInit(void) {
	allegroPtrs_t* allegroPtrs = (allegroPtrs_t*) malloc(sizeof(allegroPtrs_t));
    if (allegroPtrs == NULL) {
        fprintf(stderr, "Failed to reserve memory: malloc error.\n");
        return POINTER_FAIL;
    }

    //RESOURCES DECLARATION AND NULL INITIALIZATION
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_BITMAP* background =NULL ;
    ALLEGRO_BITMAP* wjumpArr[WJUMP_FRAMES];
    ALLEGRO_BITMAP* wwalkArr[WWALK_FRAMES];
    ALLEGRO_EVENT_QUEUE* eventQueue = NULL;
    ALLEGRO_FONT* font = NULL;
    ALLEGRO_TIMER* tickTimer = NULL;
    //The following for cycle initializes the elements of both arrays as NULL pointers. To do this in a single
    //repetition structure, the maximum value for i is the number of elements of the largest array
    for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
        if (i < WJUMP_FRAMES)   //Then we initialize the pointers in both arrays as NULL, keeping in mind
            wjumpArr[i] = NULL; //that they are not necessarily the same size
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
    if (!al_install_keyboard()) {
        fprintf(stderr, "Failed to initialize allegro keyboard!\n");
        return POINTER_FAIL;
    }
   

    //ALLEGRO RESOURCES INITIALIZATION
    font = al_load_font("./resources/arial.ttf", 20, 0);
    if (!font) {
        fprintf(stderr, "Failed to create font!\n");
        return POINTER_FAIL;
    }
    background = al_load_bitmap("./resources/background.png");
    if (!background) {
        fprintf(stderr, "Failed to load background.png\n");
        al_destroy_font(font);
        return POINTER_FAIL;
    }
    int displayWidth = al_get_bitmap_width(background);
    int displayHeight = al_get_bitmap_height(background);
    display = al_create_display(displayWidth, displayHeight);
    if (!display) {
        fprintf(stderr, "Failed to create display!\n");
        al_destroy_font(font);
        al_destroy_bitmap(background);
        return POINTER_FAIL;
    }
    eventQueue = al_create_event_queue();
    if (!eventQueue) {
        fprintf(stderr, "Failed to create event queue!\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        return POINTER_FAIL;
    }
    tickTimer = al_create_timer(1.0 / FPS); //crea el timer pero NO empieza a correr
    if (!tickTimer) {
        fprintf(stderr, "Failed to create tickTimer!\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        return POINTER_FAIL;
    }

    //ALLEGRO WORMS SPRITES INITIALIZATIONS
    wjumpArr[0] = al_load_bitmap("./resources/wjump/wjumpF1.png");
    if (!wjumpArr[0]) {
        fprintf(stderr, "Failed to load wjumpF1.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wjumpArr[1] = al_load_bitmap("./resources/wjump/wjumpF2.png");
    if (!wjumpArr[1]) {
        fprintf(stderr, "Failed to load wjumpF2.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wjumpArr[2] = al_load_bitmap("./resources/wjump/wjumpF3.png");
    if (!wjumpArr[2]) {
        fprintf(stderr, "Failed to load wjumpF3.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wjumpArr[3] = al_load_bitmap("./resources/wjump/wjumpF4.png");
    if (!wjumpArr[3]) {
        fprintf(stderr, "Failed to load wjumpF4.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    }wjumpArr[4] = al_load_bitmap("./resources/wjump/wjumpF5.png");
    if (!wjumpArr[4]) {
        fprintf(stderr, "Failed to load wjumpF5.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wjumpArr[5] = al_load_bitmap("./resources/wjump/wjumpF6.png");
    if (!wjumpArr[5]) {
        fprintf(stderr, "Failed to load wjumpF6.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wjumpArr[6] = al_load_bitmap("./resources/wjump/wjumpF7.png");
    if (!wjumpArr[6]) {
        fprintf(stderr, "Failed to load wjumpF7.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    }wjumpArr[7] = al_load_bitmap("./resources/wjump/wjumpF8.png");
    if (!wjumpArr[7]) {
        fprintf(stderr, "Failed to load wjumpF8.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wjumpArr[8] = al_load_bitmap("./resources/wjump/wjumpF9.png");
    if (!wjumpArr[8]) {
        fprintf(stderr, "Failed to load wjumpF9.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wjumpArr[9] = al_load_bitmap("./resources/wjump/wjumpF10.png");
    if (!wjumpArr[9]) {
        fprintf(stderr, "Failed to load wjumpF10.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wwalkArr[0] = al_load_bitmap("./resources/wwalk/wwalkF1.png");
    if (!wwalkArr[0]) {
        fprintf(stderr, "Failed to load wwalkF1.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wwalkArr[1] = al_load_bitmap("./resources/wwalk/wwalkF2.png");
    if (!wwalkArr[1]) {
        fprintf(stderr, "Failed to load wwalkF2.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wwalkArr[2] = al_load_bitmap("./resources/wwalk/wwalkF3.png");
    if (!wwalkArr[2]) {
        fprintf(stderr, "Failed to load wwalkF3.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wwalkArr[3] = al_load_bitmap("./resources/wwalk/wwalkF4.png");
    if (!wwalkArr[3]) {
        fprintf(stderr, "Failed to load wwalkF4.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    }wwalkArr[4] = al_load_bitmap("./resources/wwalk/wwalkF5.png");
    if (!wwalkArr[4]) {
        fprintf(stderr, "Failed to load wwalkF5.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wwalkArr[5] = al_load_bitmap("./resources/wwalk/wwalkF6.png");
    if (!wwalkArr[5]) {
        fprintf(stderr, "Failed to load wwalkF6.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wwalkArr[6] = al_load_bitmap("./resources/wwalk/wwalkF7.png");
    if (!wwalkArr[6]) {
        fprintf(stderr, "Failed to load wwalkF7.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    }wwalkArr[7] = al_load_bitmap("./resources/wwalk/wwalkF8.png");
    if (!wwalkArr[7]) {
        fprintf(stderr, "Failed to load wwalkF8.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wwalkArr[8] = al_load_bitmap("./resources/wwalk/wwalkF9.png");
    if (!wwalkArr[8]) {
        fprintf(stderr, "Failed to load wwalkF9.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wwalkArr[9] = al_load_bitmap("./resources/wwalk/wwalkF10.png");
    if (!wwalkArr[9]) {
        fprintf(stderr, "Failed to load wwalkF10.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wwalkArr[10] = al_load_bitmap("./resources/wwalk/wwalkF11.png");
    if (!wwalkArr[10]) {
        fprintf(stderr, "Failed to load wwalkF11.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wwalkArr[11] = al_load_bitmap("./resources/wwalk/wwalkF12.png");
    if (!wwalkArr[11]) {
        fprintf(stderr, "Failed to load wwalkF12.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wwalkArr[12] = al_load_bitmap("./resources/wwalk/wwalkF13.png");
    if (!wwalkArr[12]) {
        fprintf(stderr, "Failed to load wwalkF13.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wwalkArr[13] = al_load_bitmap("./resources/wwalk/wwalkF14.png");
    if (!wwalkArr[13]) {
        fprintf(stderr, "Failed to load wwalkF14.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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
    wwalkArr[14] = al_load_bitmap("./resources/wwalk/wwalkF15.png");
    if (!wwalkArr[14]) {
        fprintf(stderr, "Failed to load wwalkF15.png\n");
        al_destroy_display(display);
        al_destroy_font(font);
        al_destroy_bitmap(background);
        al_destroy_event_queue(eventQueue);
        al_destroy_timer(tickTimer);
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

   

    //ALLEGRO EVENT SOURCE EVENT REGISTERS
    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_register_event_source(eventQueue, al_get_timer_event_source(tickTimer));
    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    //TIMER INITIALIZATION
    al_start_timer(tickTimer); //Game tick timer (20 ms)
    //STRUCTURE FILL
    allegroPtrs->display = display;
    allegroPtrs->eventQueue = eventQueue;
    allegroPtrs->font = font;
    allegroPtrs->background = background;
    for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
        if (i < WJUMP_FRAMES)
            allegroPtrs->wjumpArr[i] = wjumpArr[i];
        if (i < WWALK_FRAMES)
            allegroPtrs->wwalkArr[i] = wwalkArr[i];
    }

    return allegroPtrs; //Return structure pointer
}

void allegroDestroy(allegroPtrs_t* allegroPtrs) {
    al_destroy_display(allegroPtrs->display);
    al_destroy_font(allegroPtrs->font);
    al_destroy_bitmap(allegroPtrs->background);
    al_destroy_event_queue(allegroPtrs->eventQueue);
    al_destroy_timer(allegroPtrs->tickTimer);
    for (unsigned int i = 0; i < ((WJUMP_FRAMES > WWALK_FRAMES) ? WJUMP_FRAMES : WWALK_FRAMES); i++) {
        if (i < WJUMP_FRAMES) {
            if (allegroPtrs->wjumpArr[i] != NULL) {
                al_destroy_bitmap(allegroPtrs->wjumpArr[i]);
            }
        }
        if (i < WWALK_FRAMES) {
            if (allegroPtrs->wwalkArr[i] != NULL) {
                al_destroy_bitmap(allegroPtrs->wwalkArr[i]);
            }
        }
    }
    free(allegroPtrs);
}