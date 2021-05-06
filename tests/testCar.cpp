#include "catch2/catch2.hpp"
#include "Car.h"

// test sulla funzione coca_init
TEST_CASE("coca_init dovrebbe ritornare un puntatore a un device != NULL", "[car]") {
        
    coca_device* macch = coca_init();

    REQUIRE(macch != NULL);

    delete(macch);    
}

// test sulla funzione coca_cin_carrozzeria
TEST_CASE("se il puntatore a device è NULL coca_cin_carrozzeria dovrebbe ritornare un puntatore a device = NULL", "[car]") {

    coca_device* macch = NULL;
    macch = coca_cin_carrozzeria(macch);

    REQUIRE(macch == NULL);

    delete(macch);  
}


TEST_CASE("coca_cin_carrozzeria dovrebbe ritornare un puntatore a device != NULL", "[car]") {

    coca_device* macch = coca_init();
    macch = coca_cin_carrozzeria(macch);

    REQUIRE(macch != NULL);

    delete(macch);  
}

// test sulla funzione coca_cin_posizione
TEST_CASE("se il puntatore a device è NULL coca_cin_posizione dovrebbe ritornare un puntatore a device = NULL", "[car]") {

    int scelta;
    int* pscelta = &scelta;
    coca_device* macch = NULL;
    macch = coca_cin_posizione(macch, pscelta);

    REQUIRE(macch == NULL);

    delete(macch);  
}


TEST_CASE("coca_cin_posizione dovrebbe ritornare un puntatore a device != NULL", "[car]") {

    int scelta;
    int* pscelta = &scelta;
    coca_device* macch = coca_init();
    macch = coca_cin_posizione(macch, pscelta);

    REQUIRE(macch != NULL);

    delete(macch);  
}

// test sulla funzione coca_cin_ruote
TEST_CASE("se il puntatore a device è NULL coca_cin_ruote dovrebbe ritornare un puntatore a device = NULL", "[car]") {

    int diametro;
    int* pdiametro = &diametro;
    coca_device* macch = NULL;
    macch = coca_cin_ruote(macch, pdiametro);

    REQUIRE(macch == NULL);

    delete(macch);  
}


TEST_CASE("coca_cin_ruote dovrebbe ritornare un puntatore a device != NULL", "[car]") {

    int diametro;
    int* pdiametro = &diametro;
    coca_device* macch = coca_init();
    macch = coca_cin_ruote(macch, pdiametro);

    REQUIRE(macch != NULL);

    delete(macch);  
}

// test sulla funzione coca_cin_assetto
TEST_CASE("se il puntatore a device è NULL coca_cin_assetto dovrebbe ritornare un puntatore a device = NULL", "[car]") {

    int x;
    int* px = &x;
    coca_device* macch = NULL;
    macch = coca_cin_assetto(macch, px);

    REQUIRE(macch == NULL);

    delete(macch);  
}


TEST_CASE("coca_cin_assetto dovrebbe ritornare un puntatore a device != NULL", "[car]") {

    int x;
    int* px = &x;
    coca_device* macch = coca_init();
    macch = coca_cin_assetto(macch, px);

    REQUIRE(macch != NULL);

    delete(macch);  
}

// test sulla funzione coca_cin_device
TEST_CASE("se il puntatore a device è NULL coca_cin_device dovrebbe ritornare un puntatore a device = NULL", "[car]") {

    int scelta, diametro, x;
    int* pscelta = &scelta;
    int* pdiametro = &diametro;
    int* px = &x;
    coca_device* macch = NULL;
    macch = coca_cin_device(macch, pscelta, pdiametro, px);

    REQUIRE(macch == NULL);

    delete(macch);  
}


TEST_CASE("coca_cin_device dovrebbe ritornare un puntatore a device != NULL", "[car]") {

    int scelta, diametro, x;
    int* pscelta = &scelta;
    int* pdiametro = &diametro;
    int* px = &x;
    coca_device* macch = coca_init();
    macch = coca_cin_device(macch, pscelta, pdiametro, px);

    REQUIRE(macch != NULL);

    delete(macch);  
}

// test sulla funzione coca_intestazione
TEST_CASE("coca_intestazione dovrebbe ritornare una stringa non vuota", "[car]") {

    coca_device* macch = coca_init();
    std::string svg;
    svg = coca_intestazione(macch);

    REQUIRE(svg != "");

    delete(macch);
}

// test sulla funzione coca_sfondo
TEST_CASE("coca_intestazione dovrebbe ritornare una stringa non vuota", "[car]") {

    coca_device* macch = coca_init();
    std::string svg;
    svg = coca_sfondo(macch);

    REQUIRE(svg != "");
    
    delete(macch);
}