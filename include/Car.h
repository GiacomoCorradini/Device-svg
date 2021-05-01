#ifndef CAR_H
#define CAR_H
 
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>

#define SFONDOX 800
#define SFONDOY 600

// parametri da passare alla funzione per inizializzarla
struct parametri
{
    float inheight; // altezza del veicolo
    float inwidth; // larghezza del veicolo
    float inpx; // posizione x del veicolo
    float inpy; // posizione y del veicolo
    int indiam; // diametro dei cerchioni (16, 17, 18)
    int inass; // assetto della macchina (1, 2, 3)
};


// parametri carrozzeria
struct coca_carrozzeria
{
    float cx, cy;
    float width, height;
};

// parametri ruota
struct coca_ruota
{
    float ruota, cerchione;
    float centrox, centroy;
};

// parametri tetto
struct coca_tetto 
{
    float x1, y1; 
    float x2, y2;
    float x3, y3; 
    float x4, y4;
    float x5, y5;
};

// parametri finestrini
struct coca_finestrini
{
    float p1x, p1y; 
    float p2x, p2y;
    float p3x, p3y;
};

// parametri spoiler
struct coca_spoiler
{
    float px, py;
    float widths, heights;
};

// parametri dell'intero device
struct coca_device
{
    coca_carrozzeria car;
    coca_ruota sx;
    coca_ruota dx;
    coca_finestrini fin;
    coca_spoiler spoil;
    coca_tetto cap;
    float dimensionex;
    float dimensioney;
};

// funzione che inizzializza il device passando dei parametri
coca_device* coca_init_device(parametri par);

// FUNZIONI DEVICE 
// My init parametri da terminale
void coca_cin_carrozzeria(coca_device* macch);
void coca_cin_posizione(coca_device* macch, int* scelta);
void coca_cin_ruote(coca_device* macch, int* diametro);
void coca_cin_assetto(coca_device* macch, int* x);
void coca_cin_device(coca_device* macch, int* scelta, int* diametro, int* x);

// Funzioni che calcolano i parametri della macchina
void coca_try_posizione(coca_device* macch, int scelta);
void coca_try_ruote(coca_device* macch, int diametro);
void coca_try_assetto(coca_device* macch, int x);
void coca_try_finestrini(coca_device* macch);
void coca_try_spoiler(coca_device* macch);
void coca_try_tetto(coca_device* macch);
void coca_try_device(coca_device* macch, int scelta, int diametro, int x);

// STRINGHE DEVICE
std::string coca_intestazione();
std::string coca_sfondo();
std::string coca_fine();

// stringhe device
std::string coca_strg_carrozzeria(coca_device* macch);
std::string coca_strg_ruote(coca_device* macch);
std::string coca_strg_finestrini(coca_device* macch);
std::string coca_strg_spoiler(coca_device* macch);
std::string coca_strg_tetto(coca_device* macch);
std::string coca_strg_device(coca_device* macch, int scelta, int quota);

// quotatura
string coca_quotatura(coca_device* macch);

// funzione scrive su file
void coca_write(string svg);

// funzione legge da file
std::string coca_read();
float coca_parse(string svg, string parse, int & partenza, string fine);
void coca_parse_device(coca_device* macch);

// Funzione che modifica i parametri della macchina
int coca_set_menu();

void coca_set_param(coca_device* macch, string svg, int* pscelta ,int* pdiametro, int* px);

#endif //CAR_H