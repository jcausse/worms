#include "../headers/input.h"



void checkInput(allegroPtrs_t * allegro, Keys& key,bool* redraw,bool* do_exit){
    ALLEGRO_EVENT ev;
    if (al_get_next_event(allegro->eventQueue, &ev)){ //Toma un evento de la cola
        if (ev.type == ALLEGRO_EVENT_TIMER)
            *redraw = true;
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)//Si se cierra el display o click de mouse cerrar
            *do_exit = true;
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            *do_exit = true;
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
            switch (ev.keyboard.keycode){
            case ALLEGRO_KEY_UP:
                key.keyUp = true;
                break;
            case ALLEGRO_KEY_LEFT:
                key.keyLeft = true;
                break;
            case ALLEGRO_KEY_RIGHT:
                key.keyRight = true;
                break;
            case ALLEGRO_KEY_W:
                key.keyW = true;
                break;
            case ALLEGRO_KEY_A:
                key.keyA = true;
                break;
            case ALLEGRO_KEY_D:
                key.keyD = true;
                break;
            }
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP){
            switch (ev.keyboard.keycode){
            case ALLEGRO_KEY_UP:
                key.keyUp = true;
                break;
            case ALLEGRO_KEY_LEFT:
                key.keyLeft = true;
                break;
            case ALLEGRO_KEY_RIGHT:
                key.keyRight = true;
                break;
            case ALLEGRO_KEY_W:
                key.keyW = true;
                break;
            case ALLEGRO_KEY_A:
                key.keyA = true;
                break;
            case ALLEGRO_KEY_D:
                key.keyD = true;
                break;
            }
        }
    }
}