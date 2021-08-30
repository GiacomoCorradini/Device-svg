#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>

#include "Car.h"
#include "motrice.h"

// parametri della machine (parametri car + parametri motrice)
struct coca_machine{
    int dist_macchine;
    int numero; // numero di macchine 
    coca_device** arr_car; // macchine
    MeniniDevice* motrice; // motrice
};

// funzione che scrive la strigna machine
std::string coca_strg_machine(coca_machine* machine, int scelta, int quota);

// funzione che inizializza struct machine e parametri
coca_machine* coca_init_machine(int n);

// funzione che legge da file machine
coca_machine* coca_parse_machine(coca_machine* macch, std::string svg);

// funzione che setta i parametri della machine
coca_machine* coca_myset_machine(coca_machine* macch);


#endif // MACHINE_H