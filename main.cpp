using namespace std;

#include <iostream>
#include <string>
#include "Car.h"
 
int main(){

    string svg;
    coca_device* device;
    coca_device dev;
    device = &dev;

    coca_trycarrozzeria(device);
    //string svg;
    //string* ps;

    //string* ps = new string;  

    //carrozzeria car;
    //carrozzeria* pcar;

    //dev->car.width;

    //device = &car;
    //ps = &svg;
    
    svg = coca_intestazione();
    svg += coca_sfondo();
    
    svg += coca_fine();
    
    cout << svg;

}