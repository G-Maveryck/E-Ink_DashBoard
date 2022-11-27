/*
Simple fonction de test pour simuler un capteur de température et avoir 
une information à afficher.

Renvoie un Float à chaque appel.
Incrémente toutes les 5sec jusqu'à 120, puis 
Décrémente pour les 10 sec jusqu'à -40.

Permet de tester les structures conditionnelles à implémenter dans "Display"
*/


#ifndef SIM_TEMP_H
#define SIM_TEMP_H

#include <Arduino.h>
#include "Timer.h"

#define DELAY_INCDEC 5000



enum tEtat {E_INC, E_DEC};
static tEtat etat = E_INC;

ObjTimer timerVariation(5000);

int16_t getTemp()
{
    static int16_t T(0);                     //Température simulée.

    if (timerVariation.gap())
    {

        switch (etat)
        {
        case E_INC :

            T++;

            if (T >= 120) 
            {
                etat = E_DEC;
            }

            break;
            
        case E_DEC :

            T--;

            if (T <= -40)
            {
                etat = E_INC;
            }
            
            break;

        /* 
        default:
            T = 666.0;
            break;
        */
        }
    }
    
   
    return T;

}


#endif