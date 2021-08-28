using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <cmath>

#include "Car.h"
#include "motrice.h"
#include "machine.h"

// funzione che scrive la strigna machine
std::string coca_strg_machine(coca_machine* machine, int scelta, int quota){

}

// funzione che inizializza struct machine e parametri
coca_machine* coca_init_machine(){
    coca_machine* macch = new coca_machine;
    macch->motrice = menini_init();
    for(int i = 0; i < macch->numero; i++){
        macch->arr_car[i] = coca_init_device();
    }
    return macch;
}

// funzione che legge da file machine
coca_machine* coca_parse_machine(coca_machine* macch, std::string svg){

}

// funzione che setta i parametri della machine
coca_machine* coca_myset_machine(coca_machine* macch){

}