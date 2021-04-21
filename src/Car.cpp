using namespace std;

#include <iostream>
#include <string>
#include "Car.h"

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

void coca_trycarrozzeria(coca_device* macch){
    cout << "Inserire la lunghezza della macchina" << endl;
    cin >> macch->car.width;
    cout << "Inserire l'altezza della macchina" << endl;
    cin >> macch->car.height;
}

string coca_carrozzeria(coca_device* macch){
    string carr;
    carr = "<rect  x=\"100\" y=\"430\" rx=\"10\" ry=\"10\"";
    carr += " width=\"" + to_string(macch->car.width) + "\"";
    carr += " height=\"" + to_string(macch->car.height) + "\"";
    carr += " style=\"stroke-width:3;stroke:rgb(0,0,0)\" fill=\"red\"/>\n"; 
    return carr;
}