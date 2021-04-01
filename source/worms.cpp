#include "../headers/worms.h"


/*

Reference System:
The reference system used to describe both worms movement matches Allegro's reference system:

(origin)-----------------> (+)   X axis
    |
    |
    |
    |
    |
    |
(+) V   Y axis

*/

Worm::Worm(float initialXPosition, float initialYPosition){ //Constructor
    x = initialXPosition;
    y = initialYPosition;
    salto = 0;
    wormsteady = true;
    salto_cooldown = 0;
    salto_lock = false;
    wormright = true;
    wormframe = 0;
    wormstate = IDLE;
    keyUpTimer = 0;
    keyRightTimer = 0;
    keyLeftTimer = 0;
}


void move_worms(Worm& worm1, Worm& worm2, Keys& key) {
    

    //Worm 1
    if (key.keyUp == true)  //Realizes the action depending on the pressed key
        worm1.go_up();
    else {
        worm1.keyUpTimer = 0;
        worm1.released_up();
    }
    if (key.keyRight == true)
        worm1.go_right();
    else worm1.keyRightTimer = 0;

    if (key.keyLeft == true)
        worm1.go_left();
    else worm1.keyLeftTimer = 0;
    //Worm 2
    if (key.keyW == true)
        worm2.go_up();
    else
    {
    worm2.keyUpTimer = 0;
    worm2.released_up();
    }
    if (key.keyD == true)
        worm2.go_right();
    else worm2.keyRightTimer = 0;
    if (key.keyA == true)
        worm2.go_left();
    else worm2.keyLeftTimer = 0;

    worm1.jumping();//Manages counters and moves the worm while jumping
    worm2.jumping();
}



void Worm::go_up(){
    keyUpTimer++;
    if (keyUpTimer >= 5) {
        wormstate = JUMPING;
        wormsteady = false;
        if (!isjumping(y) && (salto_lock) == false) {
            (salto) = SALTO_H;
            (salto_lock) = true;
            salto_cooldown = SALTO_COOLDOWN ;
        }
    }
}

void Worm:: released_up(void){
    (salto_lock) = false;
}

void Worm:: go_left(void){
    keyLeftTimer++;
    wormright = false;
    if (keyLeftTimer >= 5) {
        wormstate = WALKING;
        if (collidewborder(x - MOVE_RATE)) {
            if (wormframe < WWALK_FRAMES - 1)
                wormframe++;
            else
                wormframe = 0;
            if(! (wormframe))
            (x) -= MOVE_FRATE;
            wormsteady = false;
        }
    }
}

void Worm:: go_right(void){
    keyRightTimer++;
    wormright = true;
    if (keyRightTimer >= 5) {
        wormstate = WALKING;
        if (collidewborder(x + MOVE_RATE)) {
            if (wormframe < WWALK_FRAMES - 1)
                wormframe++;
            else
                wormframe = 0;
            if(! (wormframe))
            (x) += MOVE_FRATE;
            wormsteady = false;
        }
    }
}

void Worm::jumping(void) {

   
        if (isjumping(y)) { //El worm cae siempre que no detecte nada abajo de él
            y += (MOVE_FRATE * GRAVITY);
            if (wormright == true && (collidewborder(x)))
                x += cos(3.14 / 3) * VELOCIDAD;
            else if (collidewborder(x))
                x -= cos(3.14 / 3) * VELOCIDAD;
        }

        if (salto_cooldown > 0) {
            salto_cooldown--;
            if ((wormframe < WJUMP_FRAMES - 1))
                wormframe++;
            else
                wormframe = 0;
        }
        else salto_cooldown = 0;
            

        if (salto > 0 && salto_cooldown == 0) { //El worm salta lo determinado por la variable salto
            salto -= 1;
            if ((wormframe < WJUMP_FRAMES - 1 ))
                wormframe++;
            else
                wormframe = 0;
            if (!(wormframe)) {
                y -= ((sin(3.14 / 3) * MOVE_FRATE) - (MOVE_FRATE * GRAVITY));
                if (wormright == true && (collidewborder(x)))
                    x += cos(3.14 / 3) * VELOCIDAD;
                else if (collidewborder(x))
                    x -= cos(3.14 / 3) * VELOCIDAD;
                wormframe = 10;

            }

        }
    
}



bool collidewborder(float x){           //if the worm collides with something returns true
    if (x <= BORDEXIZQ || (x + SIZEWORM) >= BORDEXDER) {
        return false;
    }
    else {
        return true;
    }
    
}

bool isjumping(float y){ //if the worm is jumping returns true
    if ((y >= (PISO - MOVE_RATE) && y <= (PISO + MOVE_RATE))) {
        return false;   //The reference system goes from the top to the bottom 
    }
    else {              //If the position is lower than the floor's position, then the worm is jumping 
        return true;
    }
}





