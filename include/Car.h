#ifndef CAR_H
#define CAR_H
 
#include <string>

//std::void parametri(struct* device)
std::string coca_intestazione();
std::string coca_sfondo();
std::string coca_fine();
void coca_trycarrozzeria(device* pcar);

struct carrozzeria
{
    int cx, cy;
    int width, height;
};

struct ruota
{
    int ruota, cerchione;
    int centrox, centroy;
};

struct finestrini
{

};

struct spoiler
{
    int px, py;
    int widths, heights;
};

struct coca_device
{
    carrozzeria car;
    ruota sx;
    ruota dx;
    finestrini fin;
    spoiler spoil;
};

#endif //CAR_H