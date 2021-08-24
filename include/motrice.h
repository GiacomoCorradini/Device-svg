#ifndef MOTRICE_H
#define MOTRICE_H
#include <string>

using namespace std;

struct MeniniPianale {
    float x;
    float y;
    float w;
    float h;
};

struct MeniniCabina {
    float x;
    float y;
    float w;
    float h;
};

struct MeniniRuota {
    float x;
    float y;
    float r;
};

struct MeniniVetro {
    float x;
    float y;
    float w;
    float h;
};

struct MeniniDevice{
    MeniniPianale pianale;
    MeniniCabina cabina;
    MeniniVetro vetro;
    MeniniRuota ruotasx;
    MeniniRuota ruotadx;
    float w;
    float h;
    float margineds = 30;
    float marginess = 30;
};


MeniniDevice* menini_init();

MeniniDevice* menini_reset(MeniniDevice*);

MeniniDevice* menini_set(MeniniDevice*);

int menini_check_pianale_w(MeniniDevice*, float);

int menini_set_pianale_w(MeniniDevice*, float);

int menini_check_pianale_h(MeniniDevice*, float);

int menini_set_pianale_h(MeniniDevice*, float);

int menini_check_raggi(MeniniDevice*, float);

int menini_set_raggi(MeniniDevice*, float);

int menini_check_ruotasx(MeniniDevice*, float);

int menini_set_ruotasx(MeniniDevice*, float);

int menini_check_ruotadx(MeniniDevice*, float);

int menini_set_ruotadx(MeniniDevice*, float);

string menini_to_svg (MeniniDevice*, int);

void menini_write_file(string,string);

string menini_read_file(string);

float menini_cerca(string, string, int *, string);

MeniniDevice* menini_parse(string);


#endif 
