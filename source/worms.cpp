#include "../headers/worms.h"



Worm::Worm(float initialXPosition, float initialYPosition){ //Constructor
    x = initialXPosition;
    y = initialYPosition;
    wormmoves = 0;
    salto = 0;
    wormsteady = true;
    salto_cooldown = 0;
    salto_lock = false;
    wormright = true;
    wormframe = 0;
    wormstate = IDLE;
}


void move_worms(Worm& worm1, Worm& worm2, Keys& key){
    //Worm 1
    worm1.wormstate = IDLE;
    worm2.wormstate = IDLE;
    if (key.keyUp == true)
        worm1.go_up(); 
    else worm1.released_up();
    if (key.keyRight == true)
        worm1.go_right();
    if (key.keyLeft == true)
        worm1.go_left();
    //Worm 2
    if (key.keyW == true)
        worm2.go_up();
    else worm2.released_up();
    if (key.keyD == true)
        worm2.go_right();
    if (key.keyA == true)
        worm2.go_left();

    worm1.jumping();
    worm2.jumping();
}



void Worm::go_up(){
    
    wormstate = JUMPING;
    if (isjumping( y-MOVE_RATE))
        wormmoves++;
    wormsteady = false;
    if ((salto_cooldown) == 0 && (salto_lock) == false){
        (salto_cooldown) = SALTO_COOLDOWN;
        (salto) = SALTO_H;
        (salto_lock) = true;
    }
}

void Worm:: released_up(void){
    (salto_lock) = false;
}

void Worm:: go_left(void){
    wormstate = WALKING;
    if (collidewborder(x - MOVE_RATE)){
        (x) -= MOVE_RATE;
        wormmoves++;
        wormright = false;
        wormsteady = false;
    }
}

void Worm:: go_right(void){
    wormstate = WALKING;
    if (collidewborder(x + MOVE_RATE )){
        (x) += MOVE_RATE;
        wormmoves++;
        wormright = true;
        wormsteady = false;
    }
}

void Worm:: jumping(void){
    if (isjumping(y + MOVE_RATE)){ //El worm cae siempre que no detecte nada abajo de �l
        (y) += MOVE_RATE / 3;
        wormmoves++;
    }
    if ((salto_cooldown) > 0) //Se disminuye la variable (salto_cooldown) en cada loop, la cual sirve como un temporizador que no deja que el worm vuelva a saltar
        (salto_cooldown)--;
    if (isjumping( y - MOVE_RATE)){ //El worm salta lo determinado por la variable saltito
        (salto) -= 1;
        (y) -= MOVE_RATE * SALTO_SPEED;
    }
}



int collidewborder(float x){ //si choco con algo devuelve false
    if (x <= BORDEXIZQ || (x + SIZEWORM) >= BORDEXDER) {
        return false;
    }
    else {
        return true;
    }
    
}

int isjumping(float y){ //si esta saltando devuelve true
    if (y == PISO) {
        return false;
    }
    else {
        return true;
    }
}


void Worm:: animationState(){
    int i = 0;
    bool frameFound = false;
    if (!isjumping(y) && wormsteady == true) {//Deteccion de si el worm est� est�tico en el suelo

        for (i = 0; i < WWALK_FRAMES, frameFound != true; i++) {
            if (wormmoves < (10 * i)) {
                wormframe = i;
                frameFound = true;
            }
        }
        if (wormframe == (WWALK_FRAMES * i))
            wormmoves = 0;
    }
    else{
     for (i = 0; i < WJUMP_FRAMES, frameFound != true; i++) {
            if (wormmoves < (10 * i)) {
                wormframe = i;
                frameFound = true;
            }
        }
        if (wormframe >= (WJUMP_FRAMES * i))
            wormmoves = 0;
    }
}

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
