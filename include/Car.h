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

// funzione che setta i parametri della struct device
coca_device* coca_myset_sfondo(parametri* par, coca_device* indev);
coca_device* coca_myset_carrozzeria(parametri* par, coca_device* indev);
coca_device* coca_myset_poscarrozzeria(parametri* par, coca_device* indev);
coca_device* coca_myset_ruote(parametri* par, coca_device* indev);
coca_device* coca_myset_assetto(parametri* par, coca_device* indev);
coca_device* coca_myset_finestrino(parametri* par, coca_device* indev);
coca_device* coca_myset_spoiler(parametri* par, coca_device* indev);
coca_device* coca_myset_tetto(parametri* par, coca_device* indev);

coca_device* coca_myset_device(parametri* par, coca_device* indev);

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
std::string coca_read();
float coca_parse(std::string svg, std::string parse, int & partenza, std::string fine);
void coca_parse_device(coca_device* macch, string svg);

#endif //CAR_H