using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <cmath>
#include "Car.h"

// funzione che inizializza una struct device e parametri
coca_device* coca_init_device(){

    coca_device *macch = new coca_device;
    return macch;
    
}

// funzione che raccoglie i possibili errori
void coca_error(int err){
    
    string erro; 

    switch (err)
    {
    case 0:
        erro = "ERROR: Scelta non permessa";
        cout << erro << endl;
        break;
    case 1:
        erro = "ERROR: Posizione x non corretta, macchina fuori dal foglio di lavoro";
        cout << erro << endl;
        break;
    case 2:
        erro = "ERROR: Posizione y non corretta, macchina fuori dal foglio di lavoro";
        cout << erro << endl;
        break;
    case 3:
        erro = "ERROR: Cerchioni non disponibili";
        cout << erro << endl;
        break;
    case 4:
        erro = "ERROR: Assetto non disponibile";
        cout << erro << endl;
        break;
    case 5:
        erro = "ERROR: File non presente, devi prima scrivere o caricare un nuovo file per poterlo salvare";
        cout << erro << endl;
        break;
    case 6:
        erro = "ERROR: Dimensioni della macchina non compatibili";
        cout << erro << endl;
        break;
    case 7:
        erro = "ERROR: Non sono presenti parametri da poter modificare";
        cout << erro << endl;
        break;
    case 8:
        erro = "ERROR: File non presente, devi prima scrivere o caricare un nuovo file per poterlo leggere";
            cout << erro << endl;
            break;
    default:
        break;
    }
}

// funzioni che fanno un check sui prametri per vedere se rispettano i vincoli
int coca_check_car(coca_device* device){
    
    if(device->car.width/device->car.height < 3)
    {
        coca_error(6);
        return 1;
    } else {
        return 0;
    }
}
int coca_check_posizionex(coca_device* device){

    if((device->car.cx + device->car.width) > (device->dimensionex))
    {
        coca_error(1);
        return 1;
    } else {
        return 0;
    }

}
int coca_check_posizioney(coca_device* device){

    if((device->car.cy + device->car.height) > (device->dimensioney))
    {
        coca_error(2);
        return 1;
    } else {
        return 0;
    }

}
int coca_check_cerchioni(coca_device* device){
    
    if(device->diametro != 16 && device->diametro != 17 && device->diametro != 18)
    {
        coca_error(3);
        return 1;
    } else {
        return 0;
    }
}
int coca_check_assetto(coca_device* device){
        
    if(device->assetto != 1 && device->assetto != 2 && device->assetto != 3)
    {
        coca_error(4);
        return 1;
    } else {
        return 0;
    }
}

// Funzioni che settano i parametri della struct
coca_device* coca_myset_sfondo(coca_device* indev){
    
    indev->dimensionex = indev->dimensionex;
    indev->dimensioney = indev->dimensioney;
    
    return indev;
}
coca_device* coca_myset_carrozzeria(coca_device* indev){
    
    indev->car.width = indev->car.width;
    indev->car.height = indev->car.height;

    return indev;
}
coca_device* coca_myset_poscarrozzeria(coca_device* indev){

    indev->car.cx = indev->car.cx;
    indev->car.cy = indev->car.cy;

    return indev;
}
coca_device* coca_myset_ruote(coca_device* indev){

    switch (indev->diametro)
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
            break;
    }

    return indev;
}
coca_device* coca_myset_assetto(coca_device* indev){

    switch (indev->assetto){
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
            break;
        }

    return indev;
}
coca_device* coca_myset_finestrino(coca_device* indev){

    indev->fin.p1x = indev->car.cx + indev->car.width / 1.75;
    indev->fin.p1y = indev->car.cy - indev->car.height / 1.33333;

    indev->fin.p2x = indev->car.cx + indev->car.width / 1.25;
    indev->fin.p2y = indev->car.cy;

    indev->fin.p3x = indev->car.cx + indev->car.width / 1.75;
    indev->fin.p3y = indev->car.cy;

    return indev;

}
coca_device* coca_myset_spoiler(coca_device* indev){

    indev->spoil.heights = indev->car.height / (2.666667);
    indev->spoil.widths = indev->car.width / 17.5;
    indev->spoil.px = indev->car.cx + indev->car.width /35;
    indev->spoil.py = indev->car.cy - indev->spoil.heights;

    return indev;
}
coca_device* coca_myset_tetto(coca_device* indev){

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

// Funzione che setta i parametri della struct device
coca_device* coca_myset_device(coca_device* indev){
    
    if (indev == NULL){
        return NULL;
    }

    indev = coca_myset_sfondo(indev);
    indev = coca_myset_carrozzeria(indev);
    indev = coca_myset_poscarrozzeria(indev);
    indev = coca_myset_ruote(indev);
    indev = coca_myset_assetto(indev);
    indev = coca_myset_finestrino(indev);
    indev = coca_myset_spoiler(indev);
    indev = coca_myset_tetto(indev);

    return indev;
}

// Funzione che scrive le stringhe di Intestazione
string coca_intestazione(coca_device* macch){
    
    if (macch == NULL){
        return NULL;
    }

    string inte;
    inte = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n\n";
    inte += "<svg xmlns='http://www.w3.org/2000/svg' ";
    inte += "width='" + to_string(macch->dimensionex) + "' ";
    inte += "height='" + to_string(macch->dimensioney) + "'>\n\n";
    return inte;
}
string coca_sfondo(coca_device* macch){
    
    if (macch == NULL){
        return NULL;
    }

    string sfon;
    sfon = "\t<rect  x='0' y='0' ";
    sfon += "width='" + to_string(macch->dimensionex) + "' ";
    sfon += "height='" + to_string(macch->dimensioney) + "' ";
    sfon += "style='fill:rgb(255,255,255);stroke-width:3;stroke:rgb(0,0,0)'/>\n\n"; 
    return sfon;
}

// Funzione che scrive la stringa finale
string coca_fine(){
    string fin;
    fin = "</svg>\n";
    return fin;
    
}

// Funzione che scrive le stringhe device
string coca_strg_carrozzeria(coca_device* macch){
    
    if (macch == NULL){
        return NULL;
    }

    string carr;

    carr = "\t<rect x='" + to_string(macch->car.cx) + "' y='" + to_string(macch->car.cy) + "' rx='10' ry='10' width='" + to_string(macch->car.width) + "' height='" + to_string(macch->car.height) + "' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>\n\n"; 
    
    return carr;
}
string coca_strg_ruote(coca_device* macch){

    if (macch == NULL){
        return NULL;
    }

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
    
    if (macch == NULL){
        return NULL;
    }

    string fines;
    
    fines = "\t<polygon points='" + to_string(macch->fin.p1x) + "," + to_string(macch->fin.p1y) + " " + to_string(macch->fin.p2x) + "," + to_string(macch->fin.p2y) + " " + to_string(macch->fin.p3x) + "," + to_string(macch->fin.p3y) + "' style='fill:lightblue;stroke:black;stroke-width:5' />\n\n";
    
    return fines;
}
string coca_strg_spoiler(coca_device* macch){
    
    if (macch == NULL){
        return NULL;
    }

    string spoil;
    
    spoil = "\t<rect x='" + to_string(macch->spoil.px) + "' y='" + to_string(macch->spoil.py) + "' width='" + to_string(macch->spoil.widths) + "' height='" + to_string(macch->spoil.heights) + "' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>\n\n";
    
    return spoil;
}
string coca_strg_tetto(coca_device* macch){
    
    if (macch == NULL){
        return NULL;
    }

    string te;
    
    te = "\t<polygon points='" + to_string(macch->cap.x1) + "," + to_string(macch->cap.y1) + " " + to_string(macch->cap.x2) + "," + to_string(macch->cap.y2) + " " + to_string(macch->cap.x3) + "," + to_string(macch->cap.y3) + " " + to_string(macch->cap.x4) + "," + to_string(macch->cap.y4) + " " + to_string(macch->cap.x5) + "," + to_string(macch->cap.y5) + "' style='fill:red;stroke:black;stroke-width:5'/>\n\n";
    
    return te;
}

string coca_strg_device(coca_device* macch, int scelta, int quota){
    
    if (macch == NULL){
        return NULL;
    }

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

// Funzione che scrive la quotatura
string coca_quotatura(coca_device* macch){
    
    if (macch == NULL){
        return NULL;
    }

    string svg;

    //<!--Height-->
    svg += "\t<rect x='" + to_string(macch->car.cx - 50) + "' y='" + to_string(macch->car.cy) + "' width='3' height='" + to_string(macch->car.height) + "' style='stroke-width:0; stroke:' fill='black'/>\n";
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
int coca_write(string svg){

    if(svg == "") 
    {
        coca_error(5);
        return 1;
    }

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

    return 0;
}

// Funzione che legge un svg
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
coca_device* coca_parse_device(coca_device* macch, string svg){

    if(svg == "") 
    {
        coca_error(8);
        return NULL;
    }

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
    macch->sx.cerchione = coca_parse(svg,"r='",partenza,"'");

    macch->dx.centrox = coca_parse(svg,"cx='",partenza,"'");
    macch->dx.centroy = coca_parse(svg,"cy='",partenza,"'");
    macch->dx.ruota = coca_parse(svg,"r='",partenza,"'");

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

    return macch;
}