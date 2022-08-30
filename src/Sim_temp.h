/*
Simple fonction de test pour simuler un capteur de température et avoir un information à afficher.

Renvoie un Float à chaque appel.
Incrémente toutes les 5sec jusqu'à 120, puis Décrémente pour les 10 sec jusqu'à -40.

Permet de tester les structures conditionnelles à implémenter dans "Display"
*/


#ifndef SIM_TEMP_H
#define SIM_TEMP_H

#include <Arduino.h>


#define DELAY_INCDEC 5000



enum tEtat {E_INC, E_DEC};
static tEtat etat = E_INC;

float getTemp()
{
    static float T = 0;                     //Température simulée.
    
    static uint32_t gT_time = 0;
    static uint32_t gT_l_time = 0;   
    
    gT_time = millis();             

    if (gT_time - gT_l_time >= DELAY_INCDEC)
    {
        gT_l_time = gT_time;


        switch (etat)
        {
        case E_INC :
            T += 1.0f;

            if (T >= 120)
            {
                etat = E_DEC;
            }
            break;
            
        case E_DEC :
            T-= 1.0f;

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