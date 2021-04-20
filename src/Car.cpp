using namespace std;

#include <iostream>
#include <string>

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

struct device
{
    carrozzeria car;
    ruota sx;
    ruota dx;
    finestrini fin;
    spoiler spoil;
};

//void parametri(struct* device)
//{
//
//}

string coca_intestazione(){
    string inte;
    inte = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n";
    inte += "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">\n";
    return inte;
}

string coca_sfondo(){
    string sfon;
    sfon = "<rect  x=\"0\" y=\"0\" width=\"800\" height=\"600\" style=\"fill:rgb(255,255,255);stroke-width:3;stroke:rgb(0,0,0)\"/>\n"; 
    return sfon;
}

string coca_fine(){
    string fin;
    fin = "</svg>\n";
    return fin;
}

//void coca_carrozzeria(carrozzeria* pcar){
//    cout << "Inserire la lunghezza della macchina" << endl;
//    cin >> pcar->car.width;
//    pcar->height = 4.375 * pcar->width;
//};

//int coca_cerchioni();

//int coca_cerchioni(ruote cerchioni){
//    cout << "Indicare la dimensione dei cerchioni " << endl;
//    cin >> cerchioni.cerchione;
//    cerchioni.ruota = cerchioni.cerchione * 1.6;
//}

//void svg(){
//
//}