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

    macch = coca_myset_poscar(macch);

    return macch;
}

// funzione che setta le posizioni della macchina

coca_machine* coca_myset_poscar(coca_machine* macch){

    // setta la posizione della prima macchina
    macch->car[0]->car.cx = macch->motrice->cabina.x + macch->motrice->cabina.w + macch->dist_macchine;
    macch->car[0]->car.cy = macch->motrice->pianale.y - macch->car[0]->car.height - macch->car[0]->dx.ruota;
    macch->car[0] = coca_myset_device(macch->car[0]);
    
    // set offset tra le macchine
    if(macch->numero > 1){

        coca_device* prova = coca_init_device();
        prova = coca_copy_car(macch->car[0]);

        macch->offset = macch->car[0]->car.width + macch->dist_macchine;

        // setta la posizione delle altre macchine
        for(int i = 1; i < macch->numero; i++){
            macch->car[i] = coca_copy_car(prova);
            macch->car[i]->car.cx += (macch->offset * i);
            macch->car[i] = coca_myset_device(macch->car[i]);
            cout << "DEBUG: " << macch->car[i]->car.cx << endl;
        }
    }
    return macch;
}

coca_device* coca_copy_car(coca_device* car){
    
    coca_device* macchina = coca_init_device();

    macchina->car.cx = car->car.cx;
    macchina->car.cy = car->car.cy;
    macchina->car.height = car->car.height;
    macchina->car.width = car->car.width;
    macchina->diametro = car->diametro;
    macchina->assetto = car->assetto;

    macchina = coca_myset_device(macchina);

    return macchina;
}