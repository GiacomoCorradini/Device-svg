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
std::string coca_strg_machine(coca_machine* machine, int quota){

    if(machine == NULL){
        return NULL;
    }

    string svg;
    // intestazione
    svg = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n\n";
    svg += "<svg xmlns='http://www.w3.org/2000/svg' ";
    svg += "width='" + to_string(machine->motrice->w) + "' ";
    svg += "height='" + to_string(machine->motrice->h) + "'>\n\n";

    // sfondo
    svg += "\t<rect  x='0' y='0' ";
    svg += "width='" + to_string(machine->motrice->w) + "' ";
    svg += "height='" + to_string(machine->motrice->h) + "' ";
    svg += "style='fill:rgb(255,255,255);stroke-width:3;stroke:rgb(0,0,0)'/>\n\n";

    // device motrice
    svg += menini_to_svg(machine->motrice, quota);

    // device car
    for(int i = 0; i < machine->numero; i++){
        svg += coca_strg_device(machine->car[i], 0, quota);
    }


    // stringa finale
    svg += "</svg>\n";

    return svg;

}

// funzione che inizializza struct machine e parametri
coca_machine* coca_init_machine(coca_machine* macch){
    macch->numero = 1;
    macch->motrice = menini_init();
    macch->car = new coca_device* [macch->numero];
    for(int i = 0; i < macch->numero; i++){
        macch->car[i] = coca_init_device();
    }
    return macch;
}
/*
// funzione che legge da file machine
coca_machine* coca_parse_machine(coca_machine* macch, std::string svg){

}
*/

// funzione che setta i parametri della machine
coca_machine* coca_myset_machine(coca_machine* macch){

    if(macch == NULL){
        return NULL;
    }

   // distanza tra una macchina e l'altra
    macch->dist_macchine = macch->car[0]->car.width / 100;

    // dimensioni pianale
    macch->motrice->pianale.w = (macch->car[0]->car.width + macch->dist_macchine) * macch->numero; // spazio necessario per le macchine
    macch->motrice->pianale.w += (macch->motrice->pianale.w / 2); // sapzio necessario per la cabina

    macch->motrice->pianale.h = macch->car[0]->car.height / 1.5; 

    // dimensioni ruote
    macch->motrice->ruotasx.r = macch->car[0]->sx.ruota;
    macch->motrice->ruotadx.r = macch->car[0]->dx.ruota;

    // posizione ruote
    macch->motrice->ruotasx.x = macch->motrice->pianale.w / 6 + macch->motrice->margineds;
    macch->motrice->ruotadx.x = macch->motrice->pianale.w * 5 / 6 + macch->motrice->margineds;

    menini_reset(macch->motrice);

    macch->car[0]->car.cx = macch->motrice->cabina.x + macch->motrice->cabina.w + macch->dist_macchine;
    macch->car[0]->car.cy = macch->motrice->pianale.y - macch->car[0]->car.height - macch->car[0]->dx.ruota;

    for(int i = 0; i < macch->numero; i++){
        macch->car[i] = coca_myset_device(macch->car[0]);
        if(i > 0){
            macch->car[i]->car.cx += (macch->car[0]->car.width + macch->dist_macchine);
            macch->car[i] = coca_myset_device(macch->car[i]);
        }
    }

    return macch;
}