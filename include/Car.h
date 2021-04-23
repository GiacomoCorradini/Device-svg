#ifndef CAR_H
#define CAR_H
 
#include <string>
#define SFONDOX 800
#define SFONDOY 600

struct coca_carrozzeria
{
    float cx, cy;
    float width, height;
};

struct coca_ruota
{
    float ruota, cerchione;
    float centrox, centroy;
};

struct coca_tetto 
{
    float x1, y1; 
    float x2, y2;
    float x3, y3; 
    float x4, y4;
    float x5, y5;
};

struct coca_finestrini
{
    float p1x, p1y; 
    float p2x, p2y;
    float p3x, p3y;
};

struct coca_spoiler
{
    float px, py;
    float widths, heights;
};

struct coca_device
{
    coca_carrozzeria car;
    coca_ruota sx;
    coca_ruota dx;
    coca_finestrini fin;
    coca_spoiler spoil;
    coca_tetto cap;
};

std::string coca_intestazione();
std::string coca_sfondo();
std::string coca_fine();

void coca_try_carrozzeria(coca_device* macch);
std::string coca_strg_carrozzeria(coca_device* macch);

void coca_try_ruote(coca_device* macch);
void coca_try_assetto(coca_device* macch);
std::string coca_strg_ruote(coca_device* macch);

void coca_try_finestrini(coca_device* macch);
std::string coca_strg_finestrini(coca_device* macch);

void coca_try_spoiler(coca_device* macch);
std::string coca_strg_spoiler(coca_device* macch);

void coca_try_tetto(coca_device* macch);
std::string coca_strg_tetto(coca_device* macch);


#endif //CAR_H