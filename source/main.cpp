/*
* Trabajo Practico 4 - Worms
* 22.08 - Algoritmos y Estructuras de Datos
* Primer cuatrimestre 2021
* Grupo 9:
*   Causse, Juan Ignacio. Legajo 61105.
*   Estrella, Matias Ezequiel. Legajo 61040.
*   Greco, Trinidad Eugenia. Legajo 61118.
*/

#include "../headers/allegroMain.h"
#include "../headers/worms.h"

int main(void) {
    std::cout << "TP4. Worms. Grupo 9." << std::endl;

    allegroPtrs_t al;

    Worm worm1(800.,500.); //se inicializan ambos worms con sus posicones iniciales
    Worm worm2(800.,500.);

    Keys keys;

    bool do_exit = false;
    bool redraw = false;

    while (!do_exit) // idem anterior
    {
        checkInput(&al, keys&, &redraw,&do_exit);

        if (redraw && al_is_event_queue_empty(al.eventQueue))
        {
            redraw = false;

            move_worms(&worm1, &worm2, &keys);

            std::cout << "coord x:" <<worm1.x << "coord y:" << worm1.y << std::endl;
            //draw_all();//fincion que deberia dibujar todo

        }
    }

    return 0;
}