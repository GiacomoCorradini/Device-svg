#ifndef CAR_H
#define CAR_H
 
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>

// dimensioni di default del foglio di lavoro
#define SFONDOX 800
#define SFONDOY 600

// parametri da passare alla funzione per inizializzarla
struct parametri
{
    float inheight; // altezza del veicolo
    float inwidth; // larghezza del veicolo
    int scpos; // scelta se indicare o meno la posizione
    float inpx; // posizione x del veicolo
    float inpy; // posizione y del veicolo
    int indiam; // diametro dei cerchioni (16, 17, 18)
    int inass; // assetto della macchina (1, 2, 3)
    int sceltasfondo; // scelta se indicare o meno la dimensione del foglio di lavoro
    float indimx; // dimensione x foglio di lavoro
    float indimy; // dimensione y foglio di lavoro
    int check; // parametro di controllo
};

// parametri carrozzeria
struct coca_carrozzeria
{
    float cx, cy; // posizioni x, y della carrozzeria
    float width; // lunghezza della carrozzeria
    float height; // altezza della carrozzeria 
};

// parametri ruota
struct coca_ruota
{
    float ruota, cerchione; // dimensioni delle ruote
    float centrox, centroy; // posizioni x, y delle ruote
};

// parametri tetto
struct coca_tetto 
{
    float x1, y1; // coordinata x,y del punto 1
    float x2, y2; // coordinata x,y del punto 2
    float x3, y3; // coordinata x,y del punto 3
    float x4, y4; // coordinata x,y del punto 4
    float x5, y5; // coordinata x,y del punto 5
};

// parametri finestrini
struct coca_finestrini
{
    float p1x, p1y; // coordinata x,y del punto 1
    float p2x, p2y; // coordinata x,y del punto 2
    float p3x, p3y; // coordinata x,y del punto 3
};

// parametri spoiler
struct coca_spoiler
{
    float px, py; // posizioni x, y dello spoiler
    float widths; // lunghezza dello spoiler
    float heights; // altezza dello spoiler
};

// parametri dell'intero device
struct coca_device
{
    coca_carrozzeria car; // parametri carrozzeria
    coca_ruota sx; // parametri ruota sx
    coca_ruota dx; // parametri ruota dx
    coca_finestrini fin; // parametri finestrini
    coca_spoiler spoil; // parametri spoiler
    coca_tetto cap; // parametri tetto
    float dimensionex; // dimensione x del foglio di lavoro
    float dimensioney; // dimensione y del foglio di lavoro
};

// funzione che inizializza struct device e parametri
coca_device* coca_init_device();
parametri* coca_init_parametri();

// funzione errore
void coca_error(int err);

// funzioni check 
int coca_check_car(parametri* par);
int coca_check_posizionex(parametri* par);
int coca_check_posizioney(parametri* par);
int coca_check_cerchioni(parametri* par);
int coca_check_assetto(parametri* par);

coca_device* coca_riset(coca_device* macch, int* pscelta, int* pdiametro, int* px, int* check);

// funzione che inizzializza il device passando dei parametri
coca_device* coca_myset_device(parametri* par, coca_device* indev);

// FUNZIONI DEVICE 
// My init parametri da terminale
coca_device* coca_cin_carrozzeria(coca_device* macch, int* check);
coca_device* coca_cin_posizione(coca_device* macch, int* scelta, int* check);
coca_device* coca_cin_ruote(coca_device* macch, int* diametro, int* check);
coca_device* coca_cin_assetto(coca_device* macch, int* x, int* check);
coca_device* coca_cin_device(coca_device* macch, int* scelta, int* diametro, int* x, int* check);

// Funzioni che calcolano i parametri della macchina
coca_device* coca_try_ruote(coca_device* macch, int diametro);
coca_device* coca_try_assetto(coca_device* macch, int x);
coca_device* coca_try_finestrini(coca_device* macch);
coca_device* coca_try_spoiler(coca_device* macch);
coca_device* coca_try_tetto(coca_device* macch);
coca_device* coca_try_device(coca_device* macch, int scelta, int diametro, int x);

// STRINGHE DEVICE
std::string coca_intestazione(coca_device* macch);
std::string coca_sfondo(coca_device* macch);
std::string coca_fine();

// stringhe device
std::string coca_strg_carrozzeria(coca_device* macch);
std::string coca_strg_ruote(coca_device* macch);
std::string coca_strg_finestrini(coca_device* macch);
std::string coca_strg_spoiler(coca_device* macch);
std::string coca_strg_tetto(coca_device* macch);
std::string coca_strg_device(coca_device* macch, int scelta, int quota);

// quotatura
std::string coca_quotatura(coca_device* macch);

// funzione scrive su file
int coca_write(std::string svg);

// funzione legge da file
std::string coca_read();
float coca_parse(std::string svg, std::string parse, int & partenza, std::string fine);
void coca_parse_device(coca_device* macch, string svg);

// Funzione che modifica i parametri della macchina
coca_device* coca_set_param(coca_device* macch, std::string svg, int* pscelta ,int* pdiametro, int* px, int* check);

#endif //CAR_H