using namespace std;

#include <iostream>
#include <string>
#include "Car.h"
 
int main(){

    string svg;
    coca_device* macch;
    coca_device dev;
    macch = &dev;

    coca_try_carrozzeria(macch);
    coca_try_ruote(macch);
    coca_try_assetto(macch);
    coca_try_finestrini(macch);
    coca_try_spoiler(macch);
    coca_try_tetto(macch);


    svg = coca_intestazione();
    svg += coca_sfondo();
    svg += coca_strg_carrozzeria(macch);
    svg += coca_strg_ruote(macch);
    svg += coca_strg_finestrini(macch);
    svg += coca_strg_spoiler(macch);
    svg += coca_strg_tetto(macch);
    svg += coca_fine();
    
    cout << "Il codice svg creato è:" << endl;
    cout << svg;

    return 0;
 
} 