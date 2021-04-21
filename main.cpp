using namespace std;

#include <iostream>
#include <string>
#include "Car.h"
 
int main(){

    string svg;
    coca_device* macch;
    coca_device dev;
    macch = &dev;

    coca_trycarrozzeria(macch);
    coca_tryruote(macch);
    coca_tryassetto(macch);

    svg = coca_intestazione();
    svg += coca_sfondo();
    svg += coca_carrozzeria(macch);
    svg += coca_ruote(macch);
    
    svg += coca_fine();
    
    cout << "Il codice svg creato è:" << endl;
    cout << svg;

    return 0;
 
}