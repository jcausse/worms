/*
* Trabajo Practico 4 - Worms
* 22.08 - Algoritmos y Estructuras de Datos
* Primer cuatrimestre 2021
* Grupo 9:
*   Causse, Juan Ignacio. Legajo 61105.
*   Estrella, Matias Ezequiel. Legajo 61040.
*   Greco, Trinidad Eugenia. Legajo 61118.
*/

#include <iostream>
#include "../headers/generalHeader.h"
#include "../headers/allegroMain.h"
#include "../headers/worms.h"

int main(void) {
    std::cout << "TP4. Worms. Grupo 9." << std::endl;

    allegroPtrs_t al;

    Worm worm1;
    Worm worm2;

    Keys keys;

    while (!al.do_exit) // idem anterior
    {
        check_input(&al, &keys);

        if (al.redraw && al_is_event_queue_empty(al.eventQueue))
        {
            al.redraw = false;

            move_worms(&worm1, &worm2, keys);

            draw_all();//fincion que deberia dibujar todo

        }
    }

    return 0;
}