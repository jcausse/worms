#include "../headers/input.h"



void check_input(allegroPtrs_t * allegro, keys_t* key)
{

    ALLEGRO_EVENT ev;
    if (al_get_next_event(allegro->eventQueue, &ev)) //Toma un evento de la cola
    {
        if (ev.type == ALLEGRO_EVENT_TIMER)
            allegro->redraw = true;

        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)//Si se cierra el display o click de mouse cerrar
            allegro->do_exit = true;


        else if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            allegro->do_exit = true;

        else if (ev->type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch (ev->keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
                key->key_up = true;
                break;

            case ALLEGRO_KEY_DOWN:
                key->key_down = true;
                break;

            case ALLEGRO_KEY_LEFT:
                key->key_left = true;
                break;

            case ALLEGRO_KEY_RIGHT:
                key->key_right = true;
                break;

            case ALLEGRO_KEY_W:
                key->key_w = true;
                break;

            case ALLEGRO_KEY_S:
                key->key_s = true;
                break;

            case ALLEGRO_KEY_A:
                key->key_a = true;
                break;

            case ALLEGRO_KEY_D:
                key->key_d = true;
                break;
            }
        }

        else if (ev->type == ALLEGRO_EVENT_KEY_UP)
        {
            switch (ev->keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
                key->key_up = true;
                break;

            case ALLEGRO_KEY_DOWN:
                key->key_down = true;
                break;

            case ALLEGRO_KEY_LEFT:
                key->key_left = true;
                break;

            case ALLEGRO_KEY_RIGHT:
                key->key_right = true;
                break;

            case ALLEGRO_KEY_W:
                key->key_w = true;
                break;

            case ALLEGRO_KEY_S:
                key->key_s = true;
                break;

            case ALLEGRO_KEY_A:
                key->key_a = true;
                break;

            case ALLEGRO_KEY_D:
                key->key_d = true;
                break;
            }
        }

    }
}