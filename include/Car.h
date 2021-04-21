#ifndef CAR_H
#define CAR_H
 
#include <string>

//std::void parametri(struct* device)
std::string coca_intestazione();
std::string coca_sfondo();
std::string coca_fine();
void coca_trycarrozzeria(coca_device* pcar);

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

struct tetto 
{
    int x1, y1; 
    int x2, y2;
    int x3, y3; 
    int x4, y4;
    int x5, y5;
};

struct finestrini
{
    int p1x, p1y; 
    int p2x, p2y;
    int p3x, p3y;
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