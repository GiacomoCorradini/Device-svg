using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>

#include "Car.h"

// funzioni che chiedono parametri da terminale singole
parametri* coca_parcin_dimfoglio(parametri* par){
    
    do
    {
        cout << "Vuoi impostare le dimensioni del foglio? " << endl;
        cout << "[1] -> Si" << endl;
        cout << "[2] -> No" << endl;
        cin >> par->sceltasfondo;
        if(par->sceltasfondo != 1 && par->sceltasfondo != 2) coca_error(0);

    } while (par->sceltasfondo != 1 && par->sceltasfondo != 2);

    if(par->sceltasfondo == 1){
        cout << "Dimensione x: ";
        cin >> par->indimx;
        cout << "Dimensione y: ";
        cin >> par->indimy;
    }

    if(par->sceltasfondo == 2){
        par->indimx = SFONDOX;
        par->indimy = SFONDOY;
    }

    return par;
}
parametri* coca_parcin_dimmacch(parametri* par){

    cout << "Inserire la lunghezza della macchina: ";
    cin >> par->inwidth;
    cout << "Inserire l'altezza della macchina: ";
    cin >> par->inheight;

    if(coca_check_car(par) == 1)
    {
        par->check = 1;
    } else {
        par->check = 0;
    }

    return par;
}
parametri* coca_parcin_posmacch(parametri* par){
    
    do
    {
        cout << "Vuoi indicare la posizione della macchina nel foglio?" << endl;
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
        par->inpx = (par->indimx/2) - (par->inwidth/2);
        par->inpy = (par->indimy/2) - (par->inheight/2);
    }

    if(coca_check_posizionex(par) == 1 || coca_check_posizioney(par) == 1)
    {
        par->check = 2;
    } else {
        par->check = 0;
    }

    return par;
}
parametri* coca_parcin_ruote(parametri* par){

    cout << "Scegliere il diametro dei cerchioni" << endl;
    cout << "Cerchioni disponibili:" << endl;
    cout << "16 pollici\n17 pollici\n18 pollici\n" << endl;
    cin >> par->indiam;

    if(coca_check_cerchioni(par) == 1)
    {
        par->check = 3;
    } else {
        par->check = 0;
    }

    return par;
}
parametri* coca_parcin_assetto(parametri* par){

    cout << "Scegliere l'assetto della macchina" << endl;
    cout << "Assetti disponibili:" << endl;
    cout << "Assetto pista = 1\nAssetto strada = 2\nAssetto fuoristrada = 3\n" << endl;
    cin >> par->inass;

    if(coca_check_assetto(par) == 1)
    {
        par->check = 4;
    } else {
        par->check = 0;
    }

    return par;
}

// funzione che risetta parametri che non rispettano i vincoli
parametri* coca_riparcin(parametri* par){

    switch (par->check)
    {
    case 1:
        cout << "Ridefinire dimensioni della macchina" << endl;
        par = coca_parcin_dimmacch(par);
        break;
    case 2:
        cout << "Ridefinire posizione della machhina" << endl;
        par = coca_parcin_posmacch(par);
        break;
    case 3:
        cout << "Ridefinire diametro dei cerchioni" << endl;
        par = coca_parcin_ruote(par);
        break;
    case 4:
        cout << "Ridefinire scelta dell'assetto" << endl;
        par = coca_parcin_assetto(par);
        break;
    default:
        break;
    }
    return par;
}

// funzione che chiede parametri da terminale complessiva
parametri* coca_parcin_device(parametri* par){

    // Set dimensioni sfondo
    par = coca_parcin_dimfoglio(par);

    // set dimensioni macchina
    par = coca_parcin_dimmacch(par);

    while(par->check != 0)
    {
        par = coca_riparcin(par);
    }

    // set posizione macchina
    par = coca_parcin_posmacch(par);

    while(par->check != 0)
    {
        par = coca_riparcin(par);
    }

    // set ruote
    par = coca_parcin_ruote(par);

    while(par->check != 0)
    {
        par = coca_riparcin(par);
    }

    // set assetto
    par = coca_parcin_assetto(par);

    while(par->check != 0)
    {
        par = coca_riparcin(par);
    }

    return par;
}

// funzione che modifica i parametri
parametri* coca_set_param(parametri* par, coca_device* macch, string svg){

    if (par == NULL){
        return NULL;
    }

    if(svg == "") 
    {
        coca_error(7);
        return NULL;
    }

    if(svg != "")
    {
        int set;

        cout << "Quale parametro vuoi modificare: " << endl;
        cout << "[1] -> Dimensioni della macchina" << endl;
        cout << "[2] -> Assetto" << endl;
        cout << "[3] -> Dimensioni cerhione" << endl;
        cout << "[4] -> Posizione veicolo" << endl;
        cin >> set;

        switch (set)
        {
        case 1:
            par = coca_parcin_dimmacch(par);
            while(par->check != 0)
            {
                par = coca_riparcin(par);
            }
            break;
        case 2:
            par = coca_parcin_assetto(par);
            while(par->check != 0)
            {
                par = coca_riparcin(par);
            }
            break;
        case 3:
            par = coca_parcin_ruote(par);
            while(par->check != 0)
            {
                par = coca_riparcin(par);
            }
            break;
        case 4:
            par = coca_parcin_posmacch(par);
            while(par->check != 0)
            {
                par = coca_riparcin(par);
            }
            break;
        default:
            break;
        }
    macch = coca_try_device(macch, (*pscelta), (*pdiametro), (*px));
    }

    return macch;
}


// menu del programma da terminale
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

    int menu;
    string svg;
    coca_device* macch = coca_init_device();  
    parametri* par = coca_init_parametri();

    while(menu != 7){
        
        menu = coca_menu();
    
        switch (menu)
        {
            case 1:
                par = coca_parcin_device(par);
                macch = coca_myset_device(par, macch);
                svg = coca_strg_device(macch, 1, 0);
                break;

            case 2:
                par = coca_parcin_device(par);
                macch = coca_myset_device(par, macch);
                svg = coca_strg_device(macch, 1, 1);
                break;

            case 3:
                coca_write(svg);
                break;

            case 4:
                svg = coca_read();
                coca_parse_device(macch, svg);
                svg = coca_strg_device(macch, 1, 0);
                break;
/*
            case 5:
                macch = coca_set_param(macch, svg, pscelta, pdiametro, px, check);
                svg = coca_strg_device(macch, 1, 0);
                break;
*/
            case 6:
                if(svg == "") coca_error(5);
                if(svg != "")
                {
                cout << "La stringa svg caricata è: " << endl;
                cout << svg << endl;
                }
                break;

            case 7:
                delete par;
                delete macch;
                cout << "Programma terminato" << endl;
                break;
            
            default:
                cout << "Scelta non disponibile" << endl;
                break;
        }
    }

    return 0;
} 