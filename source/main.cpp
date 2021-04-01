/*
* Trabajo Practico 4 - Worms
* 22.08 - Algoritmos y Estructuras de Datos
* Primer cuatrimestre 2021
* Grupo 9:
*   Causse, Juan Ignacio. Legajo 61105.
*   Estrella, Matias Ezequiel. Legajo 61040.
*   Greco, Trinidad Eugenia. Legajo 61118.
*/

#include "../headers/visual.h"
#include "../headers/worms.h"

int main(void) {
    std::cout << "TP4. Worms. Grupo 9." << std::endl;
    
    //Initializations
    allegroPtrs_t* allegroPtrs = allegroInit();
    Worm worm1(800., PISO); //se inicializan ambos worms con sus posicones iniciales
    Worm worm2(1100., PISO);
    Keys keys;
    bool do_exit = false;
    bool redraw = false;

    //Worms simulator loop
    while (!do_exit){ // idem anterior
        checkInput(allegroPtrs, keys, &redraw, &do_exit);
        if ((redraw) && (al_is_event_queue_empty(allegroPtrs->eventQueue))){
            redraw = true;
            move_worms(worm1, worm2, keys);
            allegroRedraw(allegroPtrs, worm1, worm2, &redraw);
        }
    }
    return 0;
}