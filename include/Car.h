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
    int scelta_sfondo; // scelta se indicare o meno la dimensione del foglio di lavoro
    int check; // parametro di controllo
    float dimensionex; // dimensione x del foglio di lavoro
    float dimensioney; // dimensione y del foglio di lavoro
    int diametro; // diametro dei cerchioni (16, 17, 18)
    int assetto; // assetto della macchina (1, 2, 3)
    int scelta_posizione; // scelta se indicare o meno la posizione
};

// funzione che inizializza struct device e parametri
coca_device* coca_init_device();

// funzione errore
void coca_error(int err);

// funzioni check 
int coca_check_car(coca_device* device);
int coca_check_posizionex(coca_device* device);
int coca_check_posizioney(coca_device* device);
int coca_check_cerchioni(coca_device* device);
int coca_check_assetto(coca_device* device);

// funzione che setta i parametri della struct device
coca_device* coca_myset_sfondo(coca_device* indev);
coca_device* coca_myset_carrozzeria(coca_device* indev);
coca_device* coca_myset_poscarrozzeria(coca_device* indev);
coca_device* coca_myset_ruote(coca_device* indev);
coca_device* coca_myset_assetto(coca_device* indev);
coca_device* coca_myset_finestrino(coca_device* indev);
coca_device* coca_myset_spoiler(coca_device* indev);
coca_device* coca_myset_tetto(coca_device* indev);

coca_device* coca_myset_device(coca_device* indev);

// Funzione che scrive le stringhe di Intestazione
std::string coca_intestazione(coca_device* macch);
std::string coca_sfondo(coca_device* macch);
std::string coca_fine();

// Funzione che scrive le stringhe device
std::string coca_strg_carrozzeria(coca_device* macch);
std::string coca_strg_ruote(coca_device* macch);
std::string coca_strg_finestrini(coca_device* macch);
std::string coca_strg_spoiler(coca_device* macch);
std::string coca_strg_tetto(coca_device* macch);

std::string coca_strg_device(coca_device* macch, int scelta, int quota);

// Funzione che scrive la quotatura
std::string coca_quotatura(coca_device* macch);

// funzione scrive su file
int coca_write(std::string svg);

// funzione legge da file
float coca_parse(std::string svg, std::string parse, int & partenza, std::string fine);
coca_device* coca_parse_device(coca_device* macch, std::string svg, int foglio);

#endif //CAR_H