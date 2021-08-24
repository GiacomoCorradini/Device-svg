using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
  
#include "Car.h"

// funzioni che chiedono parametri da terminale singole
coca_device* coca_parcin_dimfoglio(coca_device* device){
    
    do
    {
        cout << "Vuoi impostare le dimensioni del foglio? " << endl;
        cout << "[1] -> Si" << endl;
        cout << "[2] -> No" << endl;
        cin >> device->scelta_sfondo;
        if(device->scelta_sfondo != 1 && device->scelta_sfondo != 2) coca_error(0);

    } while (device->scelta_sfondo != 1 && device->scelta_sfondo != 2);

    if(device->scelta_sfondo == 1){
        do
        {
            cout << "Dimensione x: ";
            cin >> device->dimensionex;
            cout << "Dimensione y: ";
            cin >> device->dimensioney;
            if(device->dimensionex < 0 || device->dimensioney < 0) coca_error(9);
        } while (device->dimensionex < 0 || device->dimensioney < 0);
    }

    if(device->scelta_sfondo == 2){
        device->dimensionex = SFONDOX;
        device->dimensioney = SFONDOY;
    }

    return device;
}
coca_device* coca_parcin_dimmacch(coca_device* device){
        do
        {
            cout << "Inserire la lunghezza della macchina: ";
            cin >> device->car.width;
            cout << "Inserire l'altezza della macchina: ";
            cin >> device->car.height;
            if(device->car.width < 0 || device->car.height < 0) coca_error(9);
        } while (device->car.width < 0 || device->car.height < 0);

    if(coca_check_car(device) == 1)
    {
        device->check = 1;
    } else {
        device->check = 0;
    }

    return device;
}
coca_device* coca_parcin_posmacch(coca_device* device){
    
    do
    {
        cout << "Vuoi indicare la posizione della macchina nel foglio?" << endl;
        cout << "[1] -> Si" << endl;
        cout << "[2] -> No" << endl;
        cin >> device->scelta_posizione;
        if(device->scelta_posizione != 1 && device->scelta_posizione != 2) coca_error(0);
    } while(device->scelta_posizione != 1 && device->scelta_posizione != 2);

    if(device->scelta_posizione == 1)
    {
        do
        {
            cout << "Indicare la la posizione x della macchina nel foglio" << endl;
            cin >> device->car.cx;
            cout << "Indicare la la posizione y della macchina nel foglio" << endl;
            cin >> device->car.cy;
            if(device->car.cx < 0 || device->car.cy < 0) coca_error(9);
        } while (device->car.cx < 0 || device->car.cy < 0);
        
        
    }

    if(device->scelta_posizione == 2) 
    {
        device->car.cx = (device->dimensionex/2) - (device->car.width/2);
        device->car.cy = (device->dimensioney/2) - (device->car.height/2);
    }

    if(coca_check_posizionex(device) == 1 || coca_check_posizioney(device) == 1)
    {
        device->check = 2;
    } else {
        device->check = 0;
    }

    return device;
}
coca_device* coca_parcin_ruote(coca_device* device){

    cout << "Scegliere il diametro dei cerchioni" << endl;
    cout << "Cerchioni disponibili:" << endl;
    cout << "16 pollici\n17 pollici\n18 pollici\n" << endl;
    cin >> device->diametro;

    if(coca_check_cerchioni(device) == 1)
    {
        device->check = 3;
    } else {
        device->check = 0;
    }

    return device;
}
coca_device* coca_parcin_assetto(coca_device* device){

    cout << "Scegliere l'assetto della macchina" << endl;
    cout << "Assetti disponibili:" << endl;
    cout << "Assetto pista = 1\nAssetto strada = 2\nAssetto fuoristrada = 3\n" << endl;
    cin >> device->assetto;

    if(coca_check_assetto(device) == 1)
    {
        device->check = 4;
    } else {
        device->check = 0;
    }

    return device;
}

// funzione che risetta parametri che non rispettano i vincoli
coca_device* coca_riparcin(coca_device* device){

    switch (device->check)
    {
    case 1:
        cout << "Ridefinire dimensioni della macchina" << endl;
        device = coca_parcin_dimmacch(device);
        break;
    case 2:
        cout << "Ridefinire posizione della machhina" << endl;
        device = coca_parcin_posmacch(device);
        break;
    case 3:
        cout << "Ridefinire diametro dei cerchioni" << endl;
        device = coca_parcin_ruote(device);
        break;
    case 4:
        cout << "Ridefinire scelta dell'assetto" << endl;
        device = coca_parcin_assetto(device);
        break;
    default:
        break;
    }
    return device;
}

// funzione che chiede parametri da terminale complessiva
coca_device* coca_parcin_device(coca_device* device){

    // Set dimensioni sfondo
    device = coca_parcin_dimfoglio(device);

    // set dimensioni macchina
    device = coca_parcin_dimmacch(device);
    while(device->check != 0)
    {
        device = coca_riparcin(device);
    }
    // set posizione macchina
    device = coca_parcin_posmacch(device);
    while(device->check != 0)
    {
        device = coca_riparcin(device);
    }
    // set ruote
    device = coca_parcin_ruote(device);
    while(device->check != 0)
    {
        device = coca_riparcin(device);
    }
    // set assetto
    device = coca_parcin_assetto(device);
    while(device->check != 0)
    {
        device = coca_riparcin(device);
    }
    return device;
}

// funzione che modifica i parametri
coca_device* coca_set_param(coca_device* device, string svg){

    coca_device* newmacch = new coca_device;

    if (device == NULL){
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
            device = coca_parcin_dimmacch(device);
            while(device->check != 0)
            {
                device = coca_riparcin(device);
            }
            break;
        case 2:
            device = coca_parcin_assetto(device);
            while(device->check != 0)
            {
                device = coca_riparcin(device);
            }
            break;
        case 3:
            device = coca_parcin_ruote(device);
            while(device->check != 0)
            {
                device = coca_riparcin(device);
            }
            break;
        case 4:
            device = coca_parcin_posmacch(device);
            while(device->check != 0)
            {
                device = coca_riparcin(device);
            }
            break;
        default:
            break;
        }
    device = coca_myset_device(device);
    }

    return device;
}

// Funzione che legge da file
string coca_read(){

    string file, lettura;

    cout << "Scrivere il nome del file (es: nomefile.svg)" << endl;
    cin >> lettura;

    ifstream t(lettura);
    stringstream buffer;
    buffer << t.rdbuf();
    file = buffer.str();

    return file;
}

// Menu generale
char coca_menu_generale(){

    char i;
    cout << "GESTIONE FILE SVG: " << endl;
    cout << "\tMenu generale:" << endl;
    cout << "\tScegliere quale file svg gestire" << endl;
    cout << "\t\t[c] -> Device car" << endl;
    cout << "\t\t[m] -> Device motrice" << endl;
    cout << "\t\t[l] -> Machine macchina + motrice" << endl;
    cout << "\t\t[q] -> Uscire dal programma" << endl;
    cin >> i;

    return i;
}

// Menu macchina
char coca_menu_car(){

    char i;
    cout << "\tMenu macchina:" << endl;
    cout << "\t\t[a] -> Scrivere un file svg" << endl;
    cout << "\t\t[b] -> Scrivere un file svg con quotatura" << endl;
    cout << "\t\t[c] -> Salvare un file svg" << endl;
    cout << "\t\t[d] -> Caricare un file svg" << endl;
    cout << "\t\t[e] -> Modificare un parametro file svg" << endl;
    cout << "\t\t[f] -> Stampa stringa svg a terminale" << endl;
    cout << "\t\t[q] -> Uscire dal programma" << endl;
    cin >> i;

    return i;
}

int main(){

    char m, a;
    string svg;
    coca_device* macch = coca_init_device();  

    while(a != 'q'){

        a = coca_menu_generale();

            switch (a)
            {
            case 'c':
                while(m !='q'){ 
                    m = coca_menu_car();
                    switch (m)
                    {
                        case 'a':
                            macch = coca_parcin_device(macch);
                            macch = coca_myset_device(macch);
                            svg = coca_strg_device(macch, 1, 0);
                            break;

                        case 'b':
                            macch = coca_parcin_device(macch);
                            macch = coca_myset_device(macch);
                            svg = coca_strg_device(macch, 1, 1);
                            break;

                        case 'c':
                            coca_write(svg);
                            break;

                        case 'd':
                            svg = coca_read();
                            macch = coca_parse_device(macch, svg);
                            svg = coca_strg_device(macch, 1, 0);
                            break;
                        case 'e':
                            macch = coca_set_param(macch, svg);
                            svg = coca_strg_device(macch, 1, 0);
                            break;
                        case 'f':
                            if(svg == "") coca_error(5);
                            if(svg != "")
                            {
                            cout << "La stringa svg caricata è: " << endl;
                            cout << svg << endl;
                            }
                            break;

                        case 'q':
                            delete macch;
                            cout << "Programma terminato" << endl;
                            break;
                        
                        default:
                            cout << "Scelta non disponibile" << endl;
                            break;
                    }
                }
                break;
            case 'm':
                cout << "Implementa motrice" << endl;
                break;
            case 'l':
                cout << "Implementa" << endl;
                break;
            case 'q':
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