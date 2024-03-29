using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
  
#include "Car.h"
#include "motrice.h"
#include "machine.h"

/**
 * FUNZIONI GIACOMO
 * Funzioni necessarie a gestire il device car
*/

/**
 * funzioni che chiedono parametri da terminale dimensioni foglio
 * @param device puntatore a struct device car
 * @return puntatore a struct device car
*/
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
/**
 * funzioni che chiedono parametri da terminale dimensioni macchina
 * @param device puntatore a struct device car
 * @return puntatore a struct device car
*/
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
/**
 * funzioni che chiedono parametri da terminale posizione macchina nel foglio
 * @param device puntatore a struct device car
 * @return puntatore a struct device car
*/
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
/**
 * funzioni che chiedono parametri da terminale dimensioni ruote
 * @param device puntatore a struct device car
 * @return puntatore a struct device car
*/
coca_device* coca_parcin_ruote(coca_device* device){

    cout << "Scegliere il diametro dei cerchioni" << endl;
    cout << "Cerchioni disponibili:" << endl;
    cout << "16 pollici\n17 pollici\n18 pollici" << endl;
    cin >> device->diametro;

    if(coca_check_cerchioni(device) == 1)
    {
        device->check = 3;
    } else {
        device->check = 0;
    }

    return device;
}
/**
 * funzioni che chiedono parametri da terminale assetto macchina
 * @param device puntatore a struct device car
 * @return puntatore a struct device car
*/
coca_device* coca_parcin_assetto(coca_device* device){

    cout << "Scegliere l'assetto della macchina" << endl;
    cout << "Assetti disponibili:" << endl;
    cout << "Assetto pista = 1\nAssetto strada = 2\nAssetto fuoristrada = 3" << endl;
    cin >> device->assetto;

    if(coca_check_assetto(device) == 1)
    {
        device->check = 4;
    } else {
        device->check = 0;
    }

    return device;
}
/**
 * funzione che risetta parametri che non rispettano i vincoli
 * @param device puntatore a struct device car
 * @return puntatore a struct device car
*/
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
/**
 * funzione che chiede parametri da terminale
 * @param device puntatore a struct device car
 * @return puntatore a struct device car
*/
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
/**
 * funzioni che chiedono quale parametre modificare
 * @param device puntatore a struct device car
 * @param svg stringa svg contenente i parametri struct device car
 * @return puntatore a struct device car
*/
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
/**
 * Funzione che legge da file
 * @return stringa letta
*/

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

/**
 * FUNZIONI MENNI
 * Funzioni necessarie a gestire il device motrice
*/

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 * @return un puntatore a device
 */

MeniniDevice* menini_set(MeniniDevice* device){
    cout << "Creazione di un nuovo Device: \n";
    float r = 0;
    int control;

    cout << "Quanto deve essere lungo il pianale? ";
    cin >> device->pianale.w; //Non può fallire in quanto non ho definito nessun altro parametro
    
    cout << "Quanto deve essere alto il pianale? ";
    cin >> device->pianale.h; //Non può fallire in quanto non ho definito nessun altro parametro
    
    cout << "A che distanza dalla linea fronale della cabina deve essere posizionata la ruota anteriore? ";
    cin >> r;
    control = menini_set_ruotasx(device,r);
    while(control==1){
        cout << "ERRORE: La ruota di sinistra deve essere nella prima metà del pianale\n";
        cout << "A che distanza dalla linea fronale della cabina deve essere posizionata la ruota anteriore? ";
        cin >> r;
        control = menini_set_ruotasx(device,r);
    }

    cout << "A che distanza dalla linea fronale della cabina deve essere posizionata la ruota posteriore? ";
    cin >> r;
    control = menini_set_ruotadx(device,r);
    while(control==1){
        cout << "ERRORE: La ruota di destra deve essere nella seconda metà del pianale\n";
        cout << "A che distanza dalla linea fronale della cabina deve essere posizionata la ruota posteriore? ";
        cin >> r;
        control = menini_set_ruotadx(device,r);
    }

    device->ruotasx.x += device->margineds;
    device->ruotadx.x += device->margineds;

    cout << "Qual è il raggio delle ruote? ";
    cin >> r;
    control = menini_set_raggi(device,r);
    while(control==1){
        cout << "ERRORE: Le ruote devono avere raggio inferiore all'altezza del pianale\n";
        cout << "Qual è il raggio delle ruote? ";
        cin >> r;
        control = menini_set_raggi(device,r);
    }

    menini_reset(device);
    return device;
}

/**
 * MACHINE
 * Funzioni necessarie a gestire la machine car + motrice
*/

/**
 * funzione che chiede parametri da terminale machine
 * @param device puntatore a struct device car
 * @return puntatore a struct device car
*/
// 
coca_device* coca_parcin_device_machine(coca_device* device){

    // set dimensioni macchina
    device = coca_parcin_dimmacch(device);
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
/**
 * funzione che chiede il numero di macchine e inizializza una struct machine
 * @param device puntatore a struct machine car + motrice
 * @return puntatore a struct machine car + motrice
*/
coca_machine* coca_parcin_machine(coca_machine* machine){
    do
    {
        cout << "Quante macchine vuoi caricare sul carro attrezzi?" << endl;
        cin >> machine->numero;
        if(machine->numero < 0) coca_error(9);
    } while (machine->numero < 0);
    machine = coca_init_machine(machine);
    cout << "Impostare caratteristiche della macchina" << endl;
    machine->car[0] = coca_parcin_device_machine(machine->car[0]);
    machine->car[0] = coca_myset_device(machine->car[0]);
    return machine;
}

/**
 * MENU
 * Funzioni necessarie a gestire il menu programma
*/

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
    cout << "\t\t[l] -> caricare svg da file" << endl;
    cout << "\t\t[c] -> creare un nuovo svg" << endl;
    cout << "\t\t[s] -> salvare un svg su file" << endl;
    cout << "\t\t[e] -> Modificare un parametro file svg" << endl;
    cout << "\t\t[q] -> Uscire dal menu macchina" << endl;
    cin >> i;

    return i;
}

// Menu motrice
char coca_menu_motrice(){

    char i;
    cout << "\tMenu motrice:" << endl;
    cout << "\t\t[l] -> caricare svg da file" << endl;
    cout << "\t\t[c] -> creare un nuovo svg" << endl;
    cout << "\t\t[s] -> salvare svg su file" << endl;
    cout << "\t\t[q] -> Uscire dal menu motrice" << endl;
    cin >> i;

    return i;
}

// Menu machine
char coca_menu_machine(){

    char p;
    cout << "\tMenu machine:" << endl;
    cout << "\t\t[l] -> caricare svg da file" << endl;
    cout << "\t\t[c] -> creare un nuovo svg" << endl;
    cout << "\t\t[s] -> salvare svg su file" << endl;
    cout << "\t\t[q] -> Uscire dal menu machine" << endl;
    cin >> p;

    return p;
}

int main(){

    int scelta_quota;
    char m, a, b, c;
    string svg, stringa, testoletto;
    coca_device* macch = coca_init_device();
    MeniniDevice *device = menini_init();
    coca_machine* machine = new coca_machine;

    while(a != 'q'){

        a = coca_menu_generale();

            switch (a)
            {
            case 'c':
                while(m !='q'){ 
                    m = coca_menu_car();
                    switch (m)
                    {
                        case 'l': // caricare svg da file
                            svg = coca_read();
                            macch = coca_parse_device(macch, svg, 1);
                            svg = coca_strg_device(macch, 1, 0);
                            break;

                        case 'c': // scrivere un file SVG
                            macch = coca_parcin_device(macch);
                            macch = coca_myset_device(macch);
                            do
                            {
                                cout << "Si desidera visializzare le misure? (Premere 1 per si, 0 per no) ";
                                cin >> scelta_quota;
                                if(scelta_quota != 1 && scelta_quota != 0) coca_error(0);
                            } while (scelta_quota != 1 && scelta_quota != 0);
                            svg = coca_strg_device(macch, 1, scelta_quota);
                            break;

                        case 's': // salvare un file svg
                            coca_write(svg);
                            break;

                        case 'e': // modificare un parametro file svg
                            macch = coca_set_param(macch, svg);
                            svg = coca_strg_device(macch, 1, 0);
                            break;

                        case 'q': // quit
                            cout << "Quit" << endl;
                            break;
                        
                        default:
                            cout << "Scelta non disponibile" << endl;
                            break;
                    }
                }
                break;
            case 'm':
                while (b != 'q'){
                    b = coca_menu_motrice();
                    switch (b)
                    {
                        case 'l': //caricamento
                            cout << "Inserire file da cui si vuole leggere ";
                            cin >> stringa;
                            testoletto = menini_read_file(stringa);
                            device = menini_parse(testoletto);
                            break;

                        case 'c'://creazione
                            menini_set (device);
                            break;

                        case 's'://salvataggio
                            stringa = "";
                            cout << "Inserire nome file su cui salvare l'svg ";
                            cin >> testoletto;
                            int risposta;
                            cout << "Si desidera visializzare le misure? (Premere 1 per si, 0 per no) ";
                            cin >> risposta;
                            while(risposta != 1 && risposta != 0){
                                cout << "ERRORE: Inserire 1 o 0\n";
                                cout << "Si desidera visualizzare le misure? (Premere 1 per si, 0 per no) ";
                                cin >> risposta;
                            }
                            stringa += "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n";
                            stringa += "<svg xmlns='http://www.w3.org/2000/svg' style='background-color:white' width='";
                            stringa += to_string(device->w);
                            stringa += "' height='";
                            stringa += to_string(device->h);
                            stringa += "' viewBox='0 0 ";
                            stringa += to_string(device->w);
                            stringa += " ";
                            stringa += to_string(device->h);
                            stringa += "'>\n<g>\n";
                            stringa += menini_to_svg(device,risposta);
                            stringa += "</g>\n</svg>\n";
                            menini_write_file(stringa, testoletto);
                            break;

                        case 'q': // quit
                            cout << "Quit" << endl;
                            break;

                        default:
                            cout << "Scelta non disponibile" << endl;
                            break;
                    }
                }
                break;
            case 'l':
                while (c != 'q'){
                    c = coca_menu_machine();
                    switch (c)
                    {
                        case 'l': // caricare un file SVG
                            svg = coca_read();
                            machine = coca_parse_machine(svg);
                            svg = coca_strg_machine(machine, 0);
                            break;

                        case 'c': // scrivere un file SVG machine
                            //machine = coca_init_machine(machine);
                            machine = coca_parcin_machine(machine);
                            machine = coca_myset_machine(machine);
                            do
                            {
                                cout << "Si desidera visializzare le misure? (Premere 1 per si, 0 per no) ";
                                cin >> scelta_quota;
                                if(scelta_quota != 1 && scelta_quota != 0) coca_error(0);
                            } while (scelta_quota != 1 && scelta_quota != 0);
                            
                            svg = coca_strg_machine(machine, scelta_quota);
                            break;

                        case 's': // salvare un file SVG
                            coca_write(svg);
                            break;

                        case 'q': // quit
                            cout << "Quit" << endl;
                            break;

                        default:
                            cout << "Scelta non disponibile" << endl;
                            break;
                    }
                }
                break;

            case 'q': // quit
                delete macch;
                delete device;
                delete machine;
                cout << "Programma terminato" << endl;
                break;

            default:
                cout << "Scelta non disponibile" << endl;
                break;
            }
    }
    return 0;
} 