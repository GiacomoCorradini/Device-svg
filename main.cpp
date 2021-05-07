using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>

#include "Car.h"

parametri* parcin(parametri* par){

    //foglio di lavoro
    par->sfox = SFONDOX;
    par->sfoy = SFONDOY;
    // carrozzeria
    cout << "Inserire la lunghezza della macchina: ";
    cin >> par->inwidth;
    cout << "Inserire l'altezza della macchina: ";
    cin >> par->inheight;
    // posizione
    cout << "Vuoi indicare la posizione della macchina nel foglio?" << endl;
    do
    {
        cout << "[1] -> Si" << endl;
        cout << "[2] -> No" << endl;
        cin >> par->scpos;
        if(par->scpos != 1 && par->scpos != 2) coca_error(0);
    } while(par->scpos != 1 && par->scpos != 2);
    if(par->scpos == 1)
    {
        cout << "Indicare la la posizione x della macchina nel foglio" << endl;
        cin >> par->inpx;
 
        cout << "Indicare la la posizione y della macchina nel foglio" << endl;
        cin >> par->inpy;
    }

    if(par->scpos == 2) 
    {
        par->inpx = (par->sfox/2) - (par->inheight/2);
        par->inpy = (par->sfoy/2) - (par->inwidth/2);
    }
    // ruote
    cout << "Scegliere il diametro dei cerchioni" << endl;
    cout << "Cerchioni disponibili:" << endl;
    cout << "16 pollici\n17 pollici\n18 pollici\n" << endl;
    cin >> par->indiam;
    // assetto
    cout << "Scegliere l'assetto della macchina" << endl;
    cout << "Assetti disponibili:" << endl;
    cout << "Assetto pista = 1\nAssetto strada = 2\nAssetto fuoristrada = 3\n" << endl;
    cin >> par->inass;

    return par;
}

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
    parametri* par = new parametri;
    parametri* newpar = new parametri;
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
                cout << "La stringa svg caricata è: " << endl;
                cout << svg << endl;
                break;

            case 7:
                if(svg == "") coca_error(5);
                if(svg != "")
                {
                cout << "Programma terminato" << endl;
                }
                break;
            
            default:
                cout << "Scelta non disponibile" << endl;
                break;
        }
    }

    return 0;
} 