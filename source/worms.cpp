#include "../headers/worms.h"



Worm::Worm(float initialXPosition, float initialYPosition)
{
    x= initialXPosition;
    y= initialYPosition;
    wormmoves=0;
    salto=0;
    wormsteady=true;
    salto_cooldown=0;
    salto_lock=false;
    wormright=true;
}


void move_worms(Worm* worm1, Worm* worm2, Keys* key)
{
    if (key->keyUp == true)
        worm1->go_up();
    else worm1->released_up();
    if (key->keyRight == true)
        worm1->go_right();
    if (key->keyLeft == true)
        worm1->go_left();

    if (key->keyW == true)
        worm2->go_up();
    else worm2->released_up();
    if (key->keyD == true)
        worm2->go_right();
    if (key->keyA == true)
        worm2->go_left();

    worm1->jumping();
    worm2->jumping();

}



void Worm::go_up()
{
    wormsteady = true;
    if (collidewborder(x, y-MOVE_RATE))
        wormmoves++;
    wormsteady = false;
    if ((salto_cooldown) == 0 && (salto_lock) == false)
    {
        (salto_cooldown) = SALTO_COOLDOWN;
        (salto) = SALTO_H;
        (salto_lock) = true;
    }
}

void Worm:: released_up(void)
{
    (salto_lock) = false;
}


void Worm:: go_left(void)
{
    if (collidewborder(x - MOVE_RATE, y ))
    {
        (x) -= MOVE_RATE;
        wormmoves++;
        wormright = false;
        wormsteady = false;
    }
}

void Worm:: go_right(void)
{
    if (collidewborder(x + MOVE_RATE, y ))
    {
        (x) += MOVE_RATE;
        wormmoves++;
        wormright = true;
        wormsteady = false;
    }
}

void Worm:: jumping(void)
{
    if (collidewborder(x, y + MOVE_RATE)) //Mario cae siempre que no detecte nada abajo de él
    {
        (y) += MOVE_RATE / 3;
        wormmoves++;
    }

    if ((salto_cooldown) > 0) //Se disminuye la variable (salto_cooldown) en cada loop, la cual sirve como un temporizador que no deja que Mario vuelva a saltar
        (salto_cooldown)--;

    if (collidewborder(x, y - MOVE_RATE)) //Mario salta lo determinado por la variable saltito
    {
        (salto) -= 1;
        (y) -= MOVE_RATE * SALTO_SPEED;
    }
   
}



int collidewborder(float x,float y) //si choco con algo devuelve false
{
    if (x <= BORDEXIZQ || (x + SIZEWORM) >= BORDEXDER || y > 616) {
        return false;
    }
    else {
        return true;
    }
    
}

int isjumping(float y) //si esta saltando devuelve true
{
    if (y == PISO) {
        return false;
    }
    else {
        return true;
    }

}

/*
void animationState()
{
    if (!isjumping() && wormsteady == true)//Deteccion de si el worm está estático en el suelo
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
}*/

/*void update(int estado) {
    switch (estado) {
    case START_MOVING_LEFT:
    {
        if (frameCount < 5) {
            frameCount++;
        }
        else {
            estado = MOVE_LEFT;
        }
        break;
    }
    case START_MOVING_RIGHT:
    {
        if (frameCount < 5) {
            frameCount++;
        }
        else {
            estado = MOVE_RIGHT;
        }
        break;
    }
    case MOVING_LEFT:
    {
        if (frameCount < 19) {
            img = getImage(frameCount - 5);
        }
        else if (framecount < 33) {
            img = getImage(frameCount - 19);
        }
        else if (frameCount - 47) {
            img = getImage(frameCount - 38);
        }
        else {
            worm.x += 27;
        }
        go_left;
        estado = START_MOVING_LEFT;
        frameCount = 0;
        break;
    }
    case MOVING_RIGHT:
    {
        if (frameCount < 19) {
            img = getImage(frameCount - 5);
        }
        else if (framecount < 33) {
            img = getImage(frameCount - 19);
        }
        else if (frameCount - 47) {
            img = getImage(frameCount - 38);
        }
        else {
            worm.x += 27;
        }
        go_right;
        estado = START_MOVING_RIGHT;
        frameCount = 0;
        break;
    }
        
}*/
