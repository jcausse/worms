#include "../headers/input.h"



void check_input(allegroPtrs_t * allegro, Keys* key)
{

    ALLEGRO_EVENT ev;
    if (al_get_next_event(allegro->eventQueue, &ev)) //Toma un evento de la cola
    {
        if (ev.type == ALLEGRO_EVENT_TIMER)
            allegro->redraw = true;

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)//Si se cierra el display o click de mouse cerrar
            allegro->do_exit = true;


        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            allegro->do_exit = true;

        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch (ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
                key->keyUp = true;
                break;

            case ALLEGRO_KEY_LEFT:
                key->keyLeft = true;
                break;

            case ALLEGRO_KEY_RIGHT:
                key->keyRight = true;
                break;

            case ALLEGRO_KEY_W:
                key->keyW = true;
                break;

            case ALLEGRO_KEY_A:
                key->keyA = true;
                break;

            case ALLEGRO_KEY_D:
                key->keyD = true;
                break;
            }
        }

        else if (ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch (ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
                key->keyUp = true;
                break;

            case ALLEGRO_KEY_LEFT:
                key->keyLeft = true;
                break;

            case ALLEGRO_KEY_RIGHT:
                key->keyRight = true;
                break;

            case ALLEGRO_KEY_W:
                key->keyW = true;
                break;

            case ALLEGRO_KEY_A:
                key->keyA = true;
                break;

            case ALLEGRO_KEY_D:
                key->keyD = true;
                break;
            }
        }

    }
}