#include "../headers/worms.h"

void go_up(Worm* worm);
void go_right(Worm* worm);
void go_left(Worm* worm);
void jumping(Worm* worm);

void move_worms(Worm* worm1, Worm* worm2, Keys* key)
{
    if (key->keyUp == true)
        go_up(worm1);
    else released_up(worm1);
    if (key->keyRight == true)
        go_right(worm1);
    if (key->keyLeft == true)
        go_left(worm1);

    if (key->keyW == true)
        go_up(worm2);
    else released_up(worm2);
    if (key->keyD == true)
        go_right(worm2);
    if (key->keyA == true)
        go_left(worm2);

    jumping(worm1);
    jumping(worm2);

}



void go_up(Worm* worm)
{
    worm->wormsteady = true;
    if (collidewborder(worm->x, worm->y-MOVE_RATE))
        worm->wormmoves++;
    worm->wormsteady = false;
    if ((worm->salto_cooldown) == 0 && (worm->salto_lock) == false)
    {
        (worm->salto_cooldown) = SALTO_COOLDOWN;
        (worm->salto) = SALTO_H;
        (worm->salto_lock) = true;
    }
}

void released_up(Worm* worm)
{
    (worm->salto_lock) = false;
}


void go_left(Worm* worm)
{
    if (collidewborder(worm->x - MOVE_RATE, worm->y ))
    {
        (worm->x) -= MOVE_RATE;
        worm->wormmoves++;
        worm->marioright = false;
        worm->wormsteady = false;
    }
}

void go_right(Worm* worm)
{
    if (collidewborder(worm->x + MOVE_RATE, worm->y ))
    {
        (worm->x) += MOVE_RATE;
        worm->wormmoves++;
        worm->wormright = true;
        worm->wormsteady = false;
    }
}

void jumping(Worm* worm)
{
    if (collidewborder(worm->x, worm->y + MOVE_RATE)) //Mario cae siempre que no detecte nada abajo de él
    {
        (worm->y) += MOVE_RATE / 3;
        worm->wormmoves++;
    }

    if ((worm->salto_cooldown) > 0) //Se disminuye la variable (worm->salto_cooldown) en cada loop, la cual sirve como un temporizador que no deja que Mario vuelva a saltar
        (worm->salto_cooldown)--;

    if (collidewborder(worm->x, worm->y - MOVE_RATE)) //Mario salta lo determinado por la variable saltito
    {
        (worm->salto) -= 1;
        (worm->y) -= MOVE_RATE * SALTO_SPEED;
    }
   
}



collidewborder(float x,float y) //si choco con algo devuelve false



if ((!collidewborder() && wormsteady == true)//Deteccion de si el worm está estático en el suelo
{
    if (worm->wormright == true)
        al_draw_bitmap(worm6, (worm->x), (worm->y), 0);
    else al_draw_bitmap(worm6, (worm->x), (worm->y), ALLEGRO_FLIP_HORIZONTAL);
}
else if (worm->wormmoves < 20 && wormmove >= 0)
{
    if (worm->wormright == true)
        al_draw_bitmap(worm1, (worm->x), (worm->y), 0);
    else al_draw_bitmap(worm1, (worm->x), (worm->y), ALLEGRO_FLIP_HORIZONTAL);
}
else if (worm->wormmoves < 40)
{
    if (worm->wormright == true)
        al_draw_bitmap(worm2, (worm->x), (worm->y), 0);
    else al_draw_bitmap(worm2, (worm->x), (worm->y), ALLEGRO_FLIP_HORIZONTAL);
}
else if (worm->wormmoves < 60)
{
    if (worm->wormright == true)
        al_draw_bitmap(worm3, (worm->x), (worm->y), 0);
    else al_draw_bitmap(worm3, (worm->x), (worm->y), ALLEGRO_FLIP_HORIZONTAL);
}
else if (worm->wormmoves < 80)
{
    if (worm->wormright == true)
        al_draw_bitmap(worm4, (worm->x), (worm->y), 0);
    else al_draw_bitmap(worm4, (worm->x), (worm->y), ALLEGRO_FLIP_HORIZONTAL);
}
else if (worm->wormmoves < 100)
{
    if (worm->wormright == true)
        al_draw_bitmap(worm5, (worm->x), (worm->y), 0);
    else al_draw_bitmap(worm5, (worm->x), (worm->y), ALLEGRO_FLIP_HORIZONTAL);
}
else
{
    worm->wormmoves = 0;
    if (worm->wormright == true)
        al_draw_bitmap(worm5, (worm->x), (worm->y), 0);
    else al_draw_bitmap(worm5, (worm->x), (worm->y), ALLEGRO_FLIP_HORIZONTAL);
}
