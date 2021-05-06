using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <cmath>
#include "Car.h"

// funzione che inizializza una struct device
coca_device* coca_init(){

    coca_device *macch = new coca_device;
    return macch;
}

// errori
void coca_error(int err){
    
    switch (err)
    {
    case 0:
        cout << "ERROR: Scelta non permessa" << endl;
        break;
    case 1:
        cout << "ERROR: Posizione x non corretta, macchina fuori dal foglio di lavoro" << endl;
        break;
    case 2:
        cout << "ERROR: Posizione y non corretta, macchina fuori dal foglio di lavoro" << endl;
        break;
    case 3:
        cout << "ERROR: Cerchioni non disponibili" << endl;
        break;
    case 4:
        cout << "ERROR: Assetto non disponibile" << endl;
        break;
    case 5:
        cout << "ERROR: File non presente, devi prima scrivere o caricare un nuovo file per potermo salvare" << endl;
        break;
    case 6:
        cout << "ERROR: Dimensioni della macchina non compatibili" << endl;
        break;
    case 7:
        cout << "ERROR: Non sono presenti parametri da poter modificare" << endl;
        break;
    default:
        break;
    }
}

// check constrains

int coca_check_car(coca_device* macch){
    
    if(macch->car.width/macch->car.height < 3 && macch->car.width/macch->car.height > 1.5)
    {
        coca_error(6);
        return 1;
    }

    cout << "Ridefinire dimensioni della macchina" << endl;
    coca_cin_carrozzeria(macch);
}

int coca_check_posizione(coca_device* macch, int* pscelta){

    if((macch->car.cx + macch->car.width) > (macch->dimensionex))
    {
        coca_error(1);
        return 2;
    }

    if((macch->car.cy + macch->car.height) > (macch->dimensioney))
    {
        coca_error(2);
        return 3;
    }

    cout << "Ridefinire posizione della machhina" << endl;
    coca_cin_posizione(macch, pscelta);
}

int coca_check_cerchioni(coca_device* macch, int* pdiametro){
    
    if((*pdiametro) != 16 && (*pdiametro) != 17 && (*pdiametro) != 18)
    {
        coca_error(3);
        return 4;
    }

    cout << "Ridefinire diametro dei cerchioni" << endl;
    coca_cin_ruote(macch, pdiametro);
}

int coca_check_assetto(){

}

void coca_check(coca_device* macch, int* pscelta, int* pdiametro, int* px, int* check){
    // dimensioni della macchina non compatibili
    if(macch->car.width/macch->car.height < 3)
    {
        coca_error(6);
        (*check) = 1;
    }
    // posizione x non permessa
    if((macch->car.cx + macch->car.width) > (macch->dimensionex))
    {
        coca_error(1);
        (*check) = 2;
    }
    // posizione y non permessa
    if((macch->car.cy + macch->car.height) > (macch->dimensioney))
    {
        coca_error(2);
        (*check) = 3;
    }
    // scelta cerchioni
    if((*pdiametro) != 16 && (*pdiametro) != 17 && (*pdiametro) != 18)
    {
        coca_error(3);
        (*check) = 4;
    }
    // scelta assetto
    if((*px) != 1 && (*px) != 2 && (*px) != 3)
    {
        coca_error(4);
        (*check) = 5;
    }
}
void coca_riset(coca_device* macch, int* pscelta, int* pdiametro, int* px, int icheck){
    
    switch (icheck)
    {
    case 1:
        cout << "Ridefinire dimensioni della macchina" << endl;
        coca_cin_carrozzeria(macch);
        break;
    case 2:
        cout << "Ridefinire posizione della machhina" << endl;
        coca_cin_posizione(macch, pscelta);
        break;
    case 3:
        cout << "Ridefinire posizione della machhina" << endl;
        coca_cin_posizione(macch, pscelta);
        break;
    case 4:
        cout << "Ridefinire diametro dei cerchioni" << endl;
        coca_cin_ruote(macch, pdiametro);
        break;
    case 5:
        cout << "Ridefinire scelta dell'assetto" << endl;
        coca_cin_assetto(macch, px);
        break;
    case 7:
        cout << "" << endl;

        break;
    
    default:
        break;
    }

}

// My init parametri da funzione
coca_device* coca_init_device(parametri par){
    
    coca_device* indev = new coca_device;

    // carrozzeria
    indev->car.width = par.inwidth;
    indev->car.height = par.inheight;
    indev->car.cx = par.inpx;
    if((indev->car.cx + indev->car.width) > SFONDOX) coca_error(1);
    indev->car.cy = par.inpy;
    if((indev->car.cy + indev->car.height) > SFONDOY) coca_error(2);

    // ruote
    switch (par.indiam)
    {
        case 16:
            indev->sx.ruota = (indev->car.height - 1) / 2;
            indev->sx.cerchione = indev->sx.ruota / 1.6;
            indev->dx.ruota = (indev->car.height - 1) / 2;
            indev->dx.cerchione = indev->dx.ruota / 1.6;
            break;
        case 17:
            indev->sx.ruota = indev->car.height / 2;
            indev->sx.cerchione = indev->sx.ruota / 1.6;
            indev->dx.ruota = indev->car.height / 2;
            indev->dx.cerchione = indev->dx.ruota / 1.6;
            break;
        case 18:
            indev->sx.ruota = (indev->car.height + 1) / 2;
            indev->sx.cerchione = indev->sx.ruota / 1.6;
            indev->dx.ruota = (indev->car.height + 1) / 2;
            indev->dx.cerchione = indev->dx.ruota / 1.6;
            break;
        
        default:
            coca_error(3);

            break;
    }

    // assetto
    switch (par.inass){
        case 1:
            indev->sx.centrox = indev->car.cx + (indev->car.width / 5) - 5;
            indev->dx.centrox = indev->car.cx + indev->car.width - (indev->car.width / 5) + 5;
            indev->sx.centroy = indev->car.cy + indev->car.height;
            indev->dx.centroy = indev->car.cy + indev->car.height;
            break;
        case 2:
            indev->sx.centrox = indev->car.cx + (indev->car.width / 5);
            indev->dx.centrox = indev->car.cx + indev->car.width - (indev->car.width / 5);
            indev->sx.centroy = indev->car.cy + indev->car.height;
            indev->dx.centroy = indev->car.cy + indev->car.height;
            break;
        case 3:
            indev->sx.centrox = indev->car.cx + (indev->car.width / 5) + 5;
            indev->dx.centrox = indev->car.cx + indev->car.width - (indev->car.width / 5) - 5;
            indev->sx.centroy = indev->car.cy + indev->car.height;
            indev->dx.centroy = indev->car.cy + indev->car.height;
            break;

        default:
        coca_error(4);
            break;
        }

    // finestrini
    indev->fin.p1x = indev->car.cx + indev->car.width / 1.75;
    indev->fin.p1y = indev->car.cy - indev->car.height / 1.33333;

    indev->fin.p2x = indev->car.cx + indev->car.width / 1.25;
    indev->fin.p2y = indev->car.cy;

    indev->fin.p3x = indev->car.cx + indev->car.width / 1.75;
    indev->fin.p3y = indev->car.cy;

    // spoiler
    indev->spoil.heights = indev->car.height / (2.666667);
    indev->spoil.widths = indev->car.width / 17.5;
    indev->spoil.px = indev->car.cx + indev->car.width /35;
    indev->spoil.py = indev->car.cy - indev->spoil.heights;

    // tetto
    indev->cap.x1 = indev->car.cx + indev->car.width / 5.8333;
    indev->cap.y1 = indev->car.cy;

    indev->cap.x2 = indev->car.cx + indev->car.width / 3.5;
    indev->cap.y2 = indev->car.cy - indev->car.height / 1.33333;

    indev->cap.x3 = indev->car.cx + indev->car.width / 1.75;
    indev->cap.y3 = indev->car.cy - indev->car.height / 1.33333;

    indev->cap.x4 = indev->car.cx + indev->car.width / 1.75;
    indev->cap.y4 = indev->car.cy;

    indev->cap.x5 = indev->car.cx + indev->car.width / 5.8333;
    indev->cap.y5 = indev->car.cy;

    return indev;
}


// My init parametri da terminale
coca_device* coca_cin_carrozzeria(coca_device* macch){
    
    if (macch==NULL){
        return NULL;
    }

    cout << "Inserire la lunghezza della macchina: ";
    cin >> macch->car.width;
    cout << "Inserire l'altezza della macchina: ";
    cin >> macch->car.height;

    return macch;
}
coca_device* coca_cin_posizione(coca_device* macch, int* pscelta){
    
    if (macch==NULL){
        return NULL;
    }

    macch->dimensionex = SFONDOX;
    macch->dimensioney = SFONDOY;

    cout << "Vuoi indicare la posizione della macchina nel foglio?" << endl;

    do
    {
        cout << "[1] -> Si" << endl;
        cout << "[2] -> No" << endl;
        cin >> (*pscelta);
        if((*pscelta) != 1 && (*pscelta) != 2) coca_error(0);
    } while((*pscelta) != 1 && (*pscelta) != 2);

    if((*pscelta) == 1)
    {
        cout << "Indicare la la posizione x della macchina nel foglio" << endl;
        cin >> macch->car.cx;
 
        cout << "Indicare la la posizione y della macchina nel foglio" << endl;
        cin >> macch->car.cy;
    }
    return macch;
}
coca_device* coca_cin_ruote(coca_device* macch, int* pdiametro){
    
    if (macch==NULL){
        return NULL;
    }

    cout << "Scegliere il diametro dei cerchioni" << endl;
    cout << "Cerchioni disponibili:" << endl;
    cout << "16 pollici\n17 pollici\n18 pollici\n" << endl;
    cin >> (*pdiametro);

    return macch;
}
coca_device* coca_cin_assetto(coca_device* macch, int* px){
    
    if (macch==NULL){
        return NULL;
    }

    cout << "Scegliere l'assetto della macchina" << endl;
    cout << "Assetti disponibili:" << endl;
    cout << "Assetto pista = 1\nAssetto strada = 2\nAssetto fuoristrada = 3\n" << endl;
    cin >> (*px);

    return macch;
}
coca_device* coca_cin_device(coca_device* macch, int* pscelta, int* pdiametro, int* px){
    
    if (macch==NULL){
        return NULL;
    }

    coca_cin_carrozzeria(macch);
    coca_cin_posizione(macch, pscelta);
    coca_cin_ruote(macch, pdiametro);
    coca_cin_assetto(macch, px);

    return macch;
}

// Funzioni che calcolano i parametri della macchina
coca_device* coca_try_posizione(coca_device* macch, int scelta){
    
    if (macch==NULL){
        return NULL;
    }

    if(scelta == 2) 
    {
        macch->car.cx = (macch->dimensionex/2) - (macch->car.width/2);
        macch->car.cy = (macch->dimensioney/2) - (macch->car.height/2);
    }

    return macch;
}
coca_device* coca_try_ruote(coca_device* macch, int diametro){
    if (macch==NULL){
        return NULL;
    }
    switch (diametro)
    {
        case 16:
            macch->sx.ruota = (macch->car.height - 1) / 2;
            macch->sx.cerchione = macch->sx.ruota / 1.6;
            macch->dx.ruota = (macch->car.height - 1) / 2;
            macch->dx.cerchione = macch->dx.ruota / 1.6;
            break;
        case 17:
            macch->sx.ruota = macch->car.height / 2;
            macch->sx.cerchione = macch->sx.ruota / 1.6;
            macch->dx.ruota = macch->car.height / 2;
            macch->dx.cerchione = macch->dx.ruota / 1.6;
            break;
        case 18:
            macch->sx.ruota = (macch->car.height + 1) / 2;
            macch->sx.cerchione = macch->sx.ruota / 1.6;
            macch->dx.ruota = (macch->car.height + 1) / 2;
            macch->dx.cerchione = macch->dx.ruota / 1.6;
            break;       
        default:
            break;
    }

    return macch;
}
coca_device* coca_try_assetto(coca_device* macch, int x){
    if (macch==NULL){
        return NULL;
    }
    switch (x)
    {
        case 1:
            macch->sx.centrox = macch->car.cx + (macch->car.width / 5) - 5;
            macch->dx.centrox = macch->car.cx + macch->car.width - (macch->car.width / 5) + 5;
            macch->sx.centroy = macch->car.cy + macch->car.height;
          macch->dx.centroy = macch->car.cy + macch->car.height;
        break;
        case 2:
            macch->sx.centrox = macch->car.cx + (macch->car.width / 5);
            macch->dx.centrox = macch->car.cx + macch->car.width - (macch->car.width / 5);
            macch->sx.centroy = macch->car.cy + macch->car.height;
            macch->dx.centroy = macch->car.cy + macch->car.height;
            break;
        case 3:
            macch->sx.centrox = macch->car.cx + (macch->car.width / 5) +5;
            macch->dx.centrox = macch->car.cx + macch->car.width - (macch->car.width / 5) - 5;
            macch->sx.centroy = macch->car.cy + macch->car.height;
            macch->dx.centroy = macch->car.cy + macch->car.height;
            break;
        default:
           break;
    }

    return macch;
}
coca_device* coca_try_finestrini(coca_device* macch){
    if (macch==NULL){
        return NULL;
    }
    macch->fin.p1x = macch->car.cx + macch->car.width / 1.75;
    macch->fin.p1y = macch->car.cy - macch->car.height / 1.33333;

    macch->fin.p2x = macch->car.cx + macch->car.width / 1.25;
    macch->fin.p2y = macch->car.cy;

    macch->fin.p3x = macch->car.cx + macch->car.width / 1.75;
    macch->fin.p3y = macch->car.cy;

    return macch;
}
coca_device* coca_try_spoiler(coca_device* macch){
    if (macch==NULL){
        return NULL;
    }
    macch->spoil.heights = macch->car.height / (2.666667);
    macch->spoil.widths = macch->car.width / 17.5;

    macch->spoil.px = macch->car.cx + macch->car.width /35;
    macch->spoil.py = macch->car.cy - macch->spoil.heights;

    return macch;
}
coca_device* coca_try_tetto(coca_device* macch){
    if (macch==NULL){
        return NULL;
    }
    macch->cap.x1 = macch->car.cx + macch->car.width / 5.8333;
    macch->cap.y1 = macch->car.cy;

    macch->cap.x2 = macch->car.cx + macch->car.width / 3.5;
    macch->cap.y2 = macch->car.cy - macch->car.height / 1.33333;

    macch->cap.x3 = macch->car.cx + macch->car.width / 1.75;
    macch->cap.y3 = macch->car.cy - macch->car.height / 1.33333;

    macch->cap.x4 = macch->car.cx + macch->car.width / 1.75;
    macch->cap.y4 = macch->car.cy;

    macch->cap.x5 = macch->car.cx + macch->car.width / 5.8333;
    macch->cap.y5 = macch->car.cy;

    return macch;

}

coca_device* coca_try_device(coca_device* macch, int scelta, int diametro, int x){
    if (macch==NULL){
        return NULL;
    }
    coca_try_posizione(macch, scelta);
    coca_try_ruote(macch, diametro);
    coca_try_assetto(macch, x);
    coca_try_finestrini(macch);
    coca_try_spoiler(macch);
    coca_try_tetto(macch);

    return macch;
}

//STRINGHE
// Stringa di Intestazione
string coca_intestazione(coca_device* macch){
    
    string inte;
    inte = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n\n";
    inte += "<svg xmlns='http://www.w3.org/2000/svg' ";
    inte += "width='" + to_string(macch->dimensionex) + "' ";
    inte += "height='" + to_string(macch->dimensioney) + "'>\n\n";
    return inte;
}
string coca_sfondo(coca_device* macch){
    
    string sfon;
    sfon = "\t<rect  x='0' y='0' ";
    sfon += "width='" + to_string(macch->dimensionex) + "' ";
    sfon += "height='" + to_string(macch->dimensioney) + "' ";
    sfon += "style='fill:rgb(255,255,255);stroke-width:3;stroke:rgb(0,0,0)'/>\n\n"; 
    return sfon;
}

// Stringa finale
string coca_fine(){
    string fin;
    fin = "</svg>\n";
    return fin;
    
}

// stringhe device
string coca_strg_carrozzeria(coca_device* macch){
    string carr;

    carr = "\t<rect x='" + to_string(macch->car.cx) + "' y='" + to_string(macch->car.cy) + "' rx='10' ry='10' width='" + to_string(macch->car.width) + "' height='" + to_string(macch->car.height) + "' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>\n\n"; 
    
    return carr;
}
string coca_strg_ruote(coca_device* macch){
    string ruo;
    // Ruota sinistra
    ruo = "\t<circle cx='" + to_string(macch->sx.centrox) + "' cy='" + to_string(macch->sx.centroy) + "' r='" + to_string(macch->sx.ruota) + "' stroke='black' stroke-width='3' fill='black'/>\n\n";
    // Cerchione sinistra
    ruo += "\t<circle cx='" + to_string(macch->sx.centrox) + "' cy='" + to_string(macch->sx.centroy) + "' r='" + to_string(macch->sx.cerchione) + "' stroke='black' stroke-width='3' fill='gray'/>\n\n";
    // Ruota destra
    ruo += "\t<circle cx='" + to_string(macch->dx.centrox) + "' cy='" + to_string(macch->dx.centroy) + "' r='" + to_string(macch->dx.ruota) + "' stroke='black' stroke-width='3' fill='black'/>\n\n";
    // Cerchione destra
    ruo += "\t<circle cx='" + to_string(macch->dx.centrox) + "' cy='" + to_string(macch->dx.centroy) + "' r='" + to_string(macch->dx.cerchione) + "' stroke='black' stroke-width='3' fill='gray'/>\n\n";

    return ruo;
}
string coca_strg_finestrini(coca_device* macch){
    
    string fines;
    
    fines = "\t<polygon points='" + to_string(macch->fin.p1x) + "," + to_string(macch->fin.p1y) + " " + to_string(macch->fin.p2x) + "," + to_string(macch->fin.p2y) + " " + to_string(macch->fin.p3x) + "," + to_string(macch->fin.p3y) + "' style='fill:lightblue;stroke:black;stroke-width:5' />\n\n";
    
    return fines;
}
string coca_strg_spoiler(coca_device* macch){
    
    string spoil;
    
    spoil = "\t<rect x='" + to_string(macch->spoil.px) + "' y='" + to_string(macch->spoil.py) + "' width='" + to_string(macch->spoil.widths) + "' height='" + to_string(macch->spoil.heights) + "' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>\n\n";
    
    return spoil;
}
string coca_strg_tetto(coca_device* macch){
    
    string te;
    
    te = "\t<polygon points='" + to_string(macch->cap.x1) + "," + to_string(macch->cap.y1) + " " + to_string(macch->cap.x2) + "," + to_string(macch->cap.y2) + " " + to_string(macch->cap.x3) + "," + to_string(macch->cap.y3) + " " + to_string(macch->cap.x4) + "," + to_string(macch->cap.y4) + " " + to_string(macch->cap.x5) + "," + to_string(macch->cap.y5) + "' style='fill:red;stroke:black;stroke-width:5'/>\n\n";
    
    return te;
}

string coca_strg_device(coca_device* macch, int scelta, int quota){
    
    string svg;
    
    if(scelta == 1)
    {
        svg = coca_intestazione(macch);
        svg += coca_sfondo(macch);
    
    }

    svg += coca_strg_carrozzeria(macch);
    svg += coca_strg_ruote(macch);
    svg += coca_strg_tetto(macch);
    svg += coca_strg_finestrini(macch);
    svg += coca_strg_spoiler(macch);

    if(quota == 1)
    {
        svg += coca_quotatura(macch);
    }

    if(scelta == 1)
    {
        svg += coca_fine();
    }

    return svg;
}

// quotatura
string coca_quotatura(coca_device* macch){
    
    string svg;

    //<!--Height-->
    svg = "\t<rect x='" + to_string(macch->car.cx - 50) + "' y='" + to_string(macch->car.cy) + "' width='3' height='" + to_string(macch->car.height) + "' style='stroke-width:0; stroke:' fill='black'/>\n";
    svg += "\t<rect x='" + to_string(macch->car.cx - 60) + "' y='" + to_string(macch->car.cy) + "' width='60' height='1' style='stroke-width:0; stroke:' fill='black'/>\n";
    svg += "\t<rect x='" + to_string(macch->car.cx - 60) + "' y='" + to_string(macch->car.cy + macch->car.height) + "' width='60' height='1' style='stroke-width:0; stroke:' fill='black'/>\n";
    svg += "\t<text x='" + to_string(macch->car.cx - 40) + "' y='" + to_string(macch->car.cy + (macch->car.height/2)) + "' fill='black' dominant-baseline='middle' text-anchor='middle' transform='rotate(90," + to_string(macch->car.cx - 40) + "," + to_string(macch->car.cy + (macch->car.height/2)) + ")'>" + to_string(macch->car.height) + "</text>\n";

    //<!--Width-->
    svg += "\t<rect x='" + to_string(macch->car.cx) + "' y='" + to_string(macch->cap.y2 - 30) + "' width='" + to_string(macch->car.width) + "' height='3' style='stroke-width:0; stroke:' fill='black'/>\n";
    svg += "\t<rect x='" + to_string(macch->car.cx) + "' y='" + to_string(macch->cap.y2 - 40) + "' width='1' height='" + to_string(macch->car.cy - (macch->cap.y2 - 40)) + "' style='stroke-width:0; stroke:' fill='black'/>\n";
    svg += "\t<rect x=' " + to_string(macch->car.cx + macch->car.width) + "' y='" + to_string(macch->cap.y2 - 40) + "' width='1' height='" + to_string(macch->car.cy - (macch->cap.y2 - 40)) + "' style='stroke-width:0; stroke:' fill='black'/>\n";
    svg += "\t<text x='" + to_string(macch->car.cx + (macch->car.width/2)) + "' y='" + to_string(macch->cap.y2 - 40) + "' fill='black' dominant-baseline='middle' text-anchor='middle' transform='rotate(0," + to_string(macch->car.cx + (macch->car.width/2)) + "," + to_string(macch->cap.y2 - 40) + ")'>" + to_string(macch->car.width) + "</text>\n";

    //<!--Ruota sx-->
    svg += "\t<rect x='" + to_string(macch->sx.centrox - macch->sx.ruota) + "' y=' " + to_string(macch->car.cy + macch->car.height + macch->sx.ruota + 20) + "' width='" + to_string(macch->sx.ruota*2) + "' height='3' style='stroke-width:0; stroke:' fill='black' />\n";
    svg += "\t<rect x='" + to_string(macch->sx.centrox - macch->sx.ruota) + "' y='" + to_string(macch->car.cy + macch->car.height) + "' width='1' height='" + to_string(macch->sx.ruota + 30) + "' style='stroke-width:0; stroke:' fill='black'/>\n";
    svg += "\t<rect x='" + to_string(macch->sx.centrox + macch->sx.ruota) + "' y='" + to_string(macch->car.cy + macch->car.height) + "' width='1' height='" + to_string(macch->sx.ruota + 30) + "' style='stroke-width:0; stroke:' fill='black'/>\n";
    svg += "\t<text x='" + to_string(macch->sx.centrox) + "' y='" + to_string(macch->car.cy + macch->car.height + macch->sx.ruota + 15) + "' fill='black' dominant-baseline='middle' text-anchor='middle' transform='rotate(0," + to_string(macch->sx.centrox) + "," + to_string(macch->car.cy + macch->car.height + macch->sx.ruota + 15) + ")'>" + to_string(macch->sx.ruota) + "</text>\n";

    //<!--Ruota dx-->
    svg += "\t<rect x='" + to_string(macch->dx.centrox - macch->dx.ruota) + "' y='" + to_string(macch->car.cy + macch->car.height + macch->dx.ruota + 20) + "' width='" + to_string(macch->dx.ruota*2) + "' height='3' style='stroke-width:0; stroke:' fill='black'/>\n";
    svg += "\t<rect x='" + to_string(macch->dx.centrox - macch->dx.ruota) + "' y='" + to_string(macch->car.cy + macch->car.height) + "' width='1' height='" + to_string(macch->dx.ruota + 30) + "' style='stroke-width:0; stroke:' fill='black'/>\n";
    svg += "\t<rect x='" + to_string(macch->dx.centrox + macch->dx.ruota) + "' y='" + to_string(macch->car.cy + macch->car.height) + "' width='1' height='" + to_string(macch->dx.ruota + 30) + "' style='stroke-width:0; stroke:' fill='black'/>\n";
    svg += "\t<text x='" + to_string(macch->dx.centrox) + "' y='" + to_string(macch->car.cy + macch->car.height + macch->dx.ruota + 15) + "' fill='black' dominant-baseline='middle' text-anchor='middle' transform='rotate(0," + to_string(macch->dx.centrox) + "," + to_string(macch->car.cy + macch->car.height + macch->dx.ruota + 15) + ")'>" + to_string(macch->dx.ruota) + "</text>\n";

    //<!--Cx ruota sx-->
    svg += "\t<rect x='" + to_string(macch->car.cx) + "' y='" + to_string(macch->car.cy + macch->car.height + macch->sx.ruota + 70) + "' width='" + to_string(macch->sx.centrox - macch->car.cx) + "' height='3' style='stroke-width:0; stroke:' fill='black'/>\n";
    svg += "\t<rect x='" + to_string(macch->car.cx) + "' y='" + to_string(macch->car.cy + macch->car.height) + "' width='1' height='" + to_string(macch->dx.ruota + 80) + "' style='stroke-width:0; stroke:' fill='black'/>\n";
    svg += "\t<rect x='" + to_string(macch->sx.centrox) + "' y='" + to_string(macch->car.cy + macch->car.height) + "' width='1' height='" + to_string(macch->dx.ruota + 80) + "' style='stroke-width:0; stroke:' fill='black'/>\n";
    svg += "\t<text x='" + to_string(macch->car.cx + ((macch->sx.centrox - macch->car.cx)/2)) + "' y='" + to_string(macch->car.cy + macch->car.height + macch->sx.ruota + 65) + "' fill='black' dominant-baseline='middle' text-anchor='middle' transform='rotate(0," + to_string(macch->car.cx + (macch->sx.centrox/2)) + "," + to_string(macch->car.cy + macch->car.height + macch->sx.ruota + 65) + ")'>" + to_string(macch->sx.centrox - macch->car.cx) + "</text>\n";

    return svg;
}

// Funzione che scrive su file
void coca_write(string svg){

    if(svg == "") coca_error(5);
    if(svg != ""){
        string nome;

        cout << "Scrivere il nome del file (es: nomefile.svg)" << endl;
        cin >> nome;

        // Create and open a text file
        ofstream MyFile(nome);

        string string_to_write = svg;

        // Write to the file
        MyFile << string_to_write;

        // Close the file
        MyFile.close();
    }
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

// Funzione che legge un svg !!!!
float coca_parse(string svg, string parse, int & partenza, string fine){

    string numero;

    size_t found = svg.find(parse, partenza);

    if (found != string::npos) found += parse.length();
    size_t found1 = svg.find(fine, found+1);
    for (found; found < found1; found++)
    {
        numero += svg[found];
    }
    partenza = found;
    return stof(numero);
}

// Funzione che importa i parametri da file nella struct
void coca_parse_device(coca_device* macch){

    string svg = coca_read();
    int partenza = 0;
    float m;
    
    // dimensione foglio
    macch->dimensionex = coca_parse(svg,"<rect  x='0' y='0' width='",partenza,"'");
    macch->dimensioney = coca_parse(svg,"height='",partenza,"'");

    // carrozzeria
    macch->car.cx = coca_parse(svg,"x='",partenza,"'");
    macch->car.cy = coca_parse(svg,"y='",partenza,"'");
    macch->car.width = coca_parse(svg,"width='",partenza,"'");
    macch->car.height = coca_parse(svg,"height='",partenza,"'");

    // ruota
    macch->sx.centrox = coca_parse(svg,"cx='",partenza,"'");
    macch->sx.centroy = coca_parse(svg,"cy='",partenza,"'");
    macch->sx.ruota = coca_parse(svg,"r='",partenza,"'");

    macch->sx.centrox = coca_parse(svg,"cx='",partenza,"'");
    macch->sx.centroy = coca_parse(svg,"cy='",partenza,"'");
    macch->sx.ruota = coca_parse(svg,"r='",partenza,"'");

    macch->dx.centrox = coca_parse(svg,"cx='",partenza,"'");
    macch->dx.centroy = coca_parse(svg,"cy='",partenza,"'");
    macch->dx.cerchione = coca_parse(svg,"r='",partenza,"'");

    macch->dx.centrox = coca_parse(svg,"cx='",partenza,"'");
    macch->dx.centroy = coca_parse(svg,"cy='",partenza,"'");
    macch->dx.cerchione = coca_parse(svg,"r='",partenza,"'");

    // tetto
    macch->cap.x1 = coca_parse(svg,"points='",partenza,",");
    macch->cap.y1 = coca_parse(svg,",",partenza," ");

    macch->cap.x2 = coca_parse(svg," ",partenza,",");
    macch->cap.y2 = coca_parse(svg,",",partenza," ");

    macch->cap.x3 = coca_parse(svg," ",partenza,",");
    macch->cap.y3 = coca_parse(svg,",",partenza," ");

    macch->cap.x4 = coca_parse(svg," ",partenza,",");
    macch->cap.y4 = coca_parse(svg,",",partenza," ");

    macch->cap.x5 = coca_parse(svg," ",partenza,",");
    macch->cap.y5 = coca_parse(svg,",",partenza,"'");

    // finestrini
    macch->fin.p1x = coca_parse(svg,"points='",partenza,",");
    macch->fin.p1y = coca_parse(svg,",",partenza," ");

    macch->fin.p2x = coca_parse(svg," ",partenza,",");
    macch->fin.p2y = coca_parse(svg,",",partenza," ");

    macch->fin.p3x = coca_parse(svg," ",partenza,",");
    macch->fin.p3y = coca_parse(svg,",",partenza,"'");

    // spoiler
    macch->spoil.px = coca_parse(svg,"x='",partenza,"'");
    macch->spoil.py = coca_parse(svg,"y='",partenza,"'");
    macch->spoil.widths = coca_parse(svg,"width='",partenza,"'");
    macch->spoil.heights = coca_parse(svg,"height='",partenza,"'");
}

// Menù parametri da modificare
int coca_set_menu(){
    
    int cd;
    
    cout << "Quale parametro vuoi modificare: " << endl;
    cout << "[1] -> Lunghezza" << endl;
    cout << "[2] -> Altezza" << endl;  
    cout << "[3] -> Assetto" << endl;
    cout << "[4] -> Dimensioni cerhione" << endl;
    cout << "[5] -> Posizione veicolo" << endl;
    cin >> cd;
    
    return cd;
}

// Funzione che modifica i parametri
void coca_set_param(coca_device* macch, string svg, int* pscelta ,int* pdiametro, int* px){

    if(svg == "") coca_error(7);
    if(svg != "")
    {

        int set = coca_set_menu();

        switch (set)
        {
        case 1:
            do{
                cout << "Inserisci una nuova lunghezza: "; 
                cin >> macch->car.width;
                if(macch->car.width/macch->car.height < 3) coca_error(6);
            } while(macch->car.width/macch->car.height < 3);
            break;
        case 2:
            do{
                cout << "Inserisci una nuova altezza: ";
                cin >> macch->car.height;
                if(macch->car.width/macch->car.height < 3) coca_error(6);
            } while(macch->car.width/macch->car.height < 3);
            break;
        case 3:
            do{
            cout << "Inserisci un nuovo assetto: ";
            cout << "Assetti disponibili:" << endl;
            cout << "Assetto pista = 1\nAssetto strada = 2\nAssetto fuoristrada = 3\n" << endl;
            cin >> (*px);
            if((*px) != 1 && (*px) != 2 && (*px) != 3) coca_error(4);
            } while((*px) != 1 && (*px) != 2 && (*px) != 3);
            break;
        case 4:
            do{
                cout << "Scegli un nuovo cerchione: ";
                cout << "Cerchioni disponibili:" << endl;
                cout << "16 pollici\n17 pollici\n18 pollici\n" << endl;
                cin >> (*pdiametro);
                if((*pdiametro) != 16 && (*pdiametro) != 17 && (*pdiametro) != 18) coca_error(3);
            } while((*pdiametro) != 16 && (*pdiametro) != 17 && (*pdiametro) != 18);
            break;
        case 5:
            (*pscelta) = 1;
            coca_cin_posizione(macch, pscelta);
            break;
        default:
            break;
        }
    coca_try_device(macch, (*pscelta), (*pdiametro), (*px));
    }
}