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
/*
// funzione che scrive la strigna machine
std::string coca_strg_machine(coca_machine* machine, int scelta, int quota){

}
*/
// funzione che inizializza struct machine e parametri
coca_machine* coca_init_machine(){
    coca_machine* macch = new coca_machine;
    macch->numero = 0;
    macch->motrice = menini_init();
    macch->car = coca_init_device();
    return macch;
}
/*
// funzione che legge da file machine
coca_machine* coca_parse_machine(coca_machine* macch, std::string svg){

}
*/

// funzione che setta i parametri della machine
coca_machine* coca_myset_machine(coca_machine* macch){
    float r;
    int control;

   // distanza tra una macchina e l'altra
    macch->dist_macchine = macch->car->car.width / 100;

    // dimensioni pianale
    macch->motrice->pianale.w = (macch->car->car.width + macch->dist_macchine) * macch->numero; // spazio necessario per le macchine
    macch->motrice->pianale.w += (macch->motrice->pianale.w / 3); // sapzio necessario per la cabina

    macch->motrice->pianale.h = macch->car->car.height / 4;

    // dimensioni ruote
    macch->motrice->ruotasx.r = macch->car->sx.ruota * 1.5;
    macch->motrice->ruotadx.r = macch->car->dx.ruota * 1.5;

    // posizione ruote
    macch->motrice->ruotasx.x = macch->motrice->pianale.w / 5;
    macch->motrice->ruotadx.x = macch->motrice->pianale.w * 4 / 5;

    menini_reset(macch->motrice);

    return macch;
}