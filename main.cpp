using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>

#include "Car.h"

int coca_menu(){

    int i;
    cout << "Che cosa vuoi fare: " << endl;
    cout << "[1] -> Scrivere un file svg" << endl;
    cout << "[2] -> Scrivere un file svg con quotatura" << endl;
    cout << "[3] -> Salvare un file svg" << endl;
    cout << "[4] -> Caricare un file svg" << endl;
    cout << "[5] -> Modificare un parametro file svg" << endl;
    cout << "[6] -> Stampa stringa svg a terminale" << endl;
    cout << "[7] -> Uscire dal programma" << endl;
    cin >> i;

    return i;
}


int main(){

    int menu, icheck = 0;
    string svg;
    coca_device* macch = coca_init();
    int scelta, diametro, x;
    int* pscelta = &scelta;
    int* pdiametro = &diametro;
    int* px = &x;
    int* check = &icheck;
    
    while(menu != 7){
        
        menu = coca_menu();
    
        switch (menu)
        {
            case 1:
                macch = coca_cin_device(macch, pscelta, pdiametro, px, check);
                macch = coca_try_device(macch, scelta, diametro, x);                
                svg = coca_strg_device(macch, 1, 0);
                break;

            case 2:
                macch = coca_cin_device(macch, pscelta, pdiametro, px, check);
                macch = coca_try_device(macch, scelta, diametro, x);
                svg = coca_strg_device(macch, 1, 1);
                break;

            case 3:
                coca_write(svg);
                break;

            case 4:
                coca_parse_device(macch);
                svg = coca_strg_device(macch, 1, 0);
                break;

            case 5:
                macch = coca_set_param(macch, svg, pscelta, pdiametro, px, check);
                svg = coca_strg_device(macch, 1, 0);
                break;

            case 6:
                if(svg == "") coca_error(5);
                if(svg != "")
                {
                cout << "La stringa svg caricata è: " << endl;
                cout << svg << endl;
                }
                break;

            case 7:
                cout << "Programma terminato" << endl;
                break;
            
            default:
                cout << "Scelta non disponibile" << endl;
                break;
        }
    }

    return 0;
} 