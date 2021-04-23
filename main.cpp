using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>

#include "Car.h"
 
int main(){

    string svg;
    coca_device* macch;
    coca_device dev;
    macch = &dev;

    // Calcolo dei parametri necessari
    coca_try_device(macch);

    // Stampa stringa con i parametri passati
    svg = coca_strg_device(macch);

    // Create and open a text file
    ofstream MyFile("coca_macchine.svg");

    string string_to_write = svg;

    // Write to the file
    MyFile << string_to_write;

    // Close the file
    MyFile.close();

    return 0;
} 