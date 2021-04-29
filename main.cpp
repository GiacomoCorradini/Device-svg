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
    cout << "[5] -> Modificare un file svg" << endl;
    cout << "[6] -> Modificare un parametro file svg" << endl;
    cout << "[7] -> Stampa stringa svg a terminale" << endl;
    cout << "[8] -> Uscire dal programma" << endl;
    cin >> i;

    return i;
}


int main(){

    int scelta;
    string svg;
    coca_device* macch;
    coca_device dev;
    macch = &dev;

    while(scelta != 8){
        
        scelta = coca_menu();
    
        switch (scelta)
        {
            case 1:
                coca_try_device(macch);
                svg = coca_strg_device(macch, 1, 0);
                break;

            case 2:
                coca_try_device(macch);
                svg = coca_strg_device(macch, 1, 1);
                break;

            case 3:
                coca_write(svg);
                break;

            case 4:
                svg = coca_read();
                break;

            case 5:

                break;

            case 6:
                coca_set_param(macch, svg);
                svg = coca_strg_device(macch, 1, 0);
                break;

            case 7:
                cout << "La stringa svg caricata è: " << endl;
                cout << svg << endl;
                break;

            case 8:
                cout << "Programma terminato" << endl;
                break;
            
            default:
                cout << "Scelta non disponibile" << endl;
                break;
        }
    }

    return 0;
} 