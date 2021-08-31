#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>

#include "Car.h"
#include "motrice.h"

/**
 * parametri della machine (parametri car + parametri motrice)
 * @param coca_machine contiene: i device car e motrice con i relativi parametri
*/

struct coca_machine{
    int dist_macchine;
    int numero; // numero di macchine 
    coca_device* car; // macchine
    MeniniDevice* motrice; // motrice
};

/**
 * funzione che scrive la strigna svg della struct machine
 * @param coca_strg_machine vengono passati: puntatore a struct machine, scelta se inserire l'intestazione, scelta se inserire quota
 * @return la stringa svg
*/

std::string coca_strg_machine(coca_machine* machine, int quota);

/**
 * funzione che inizializza struct machine e parametri
 * @return un puntatore alla struct device
*/

coca_machine* coca_init_machine();

/**
 * funzione che legge da file svg e setta i parametri della struct machine
 * @param coca_parse_machine vengono passati: puntatore a struct machine da settare e stringa da leggere
 * @return un puntatore alla struct device
*/

coca_machine* coca_parse_machine(coca_machine* macch, std::string svg);

/**
 * funzione che setta i parametri della machine
 * @param coca_myset_machine vengono passati: puntatore a struct machine da settare
 * @return un puntatore alla struct device
*/

coca_machine* coca_myset_machine(coca_machine* macch);


#endif // MACHINE_H