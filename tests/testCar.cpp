#include "catch2/catch2.hpp"
#include "Car.h"

// test sulla funzione coca_init_device
TEST_CASE("coca_init dovrebbe ritornare un puntatore a un device != NULL", "[car]") {
        
    coca_device* macch = coca_init_device();

    REQUIRE(macch != NULL);

    delete(macch);    
}

// test sulla funzione coca_check_car
TEST_CASE("coca_check_car dovrebbe ritornare 1 se non è rispettato il rapporto width/height < 3", "[car]") {
    
    coca_device* macch = coca_init_device();
    
    macch->car.width = 300;
    macch->car.height = 150;

    REQUIRE(coca_check_car(macch) == 1);

    delete(macch);    
}

TEST_CASE("coca_check_car dovrebbe ritornare 0 se è rispettato il rapporto width/height < 3", "[car]") {
        
    coca_device* macch = coca_init_device();

    macch->car.width = 350;
    macch->car.height = 80;

    REQUIRE(coca_check_car(macch) == 0);

    delete(macch);    
}

// test sulla funzione coca_check_posizione x
TEST_CASE("coca_check_posizionex dovrebbe ritornare 1 se non è rispettata l'impaginazione nella coordinata x", "[car]") {
    
    coca_device* macch = coca_init_device();

    macch->dimensionex = SFONDOX;
    macch->dimensioney = SFONDOY;

    macch->car.width = 350;
    macch->car.height = 80;

    macch->car.cx = 600;
    macch->car.cy = (macch->dimensioney/2) - (macch->car.height/2);

    REQUIRE(coca_check_posizionex(macch) == 1);

    delete(macch);    
}

TEST_CASE("coca_check_posizionex dovrebbe ritornare 0 se è rispettata l'impaginazione nella coordinata x", "[car]") {
    
    coca_device* macch = coca_init_device();

    macch->dimensionex = SFONDOX;
    macch->dimensioney = SFONDOY;

    macch->car.width = 350;
    macch->car.height = 80;

    macch->car.cx = (macch->dimensionex/2) - (macch->car.width/2);
    macch->car.cy = (macch->dimensioney/2) - (macch->car.height/2);

    REQUIRE(coca_check_posizionex(macch) == 0);

    delete(macch);    
}

// test sulla funzione coca_check_posizione y
TEST_CASE("coca_check_posizioney dovrebbe ritornare 1 se non è rispettata l'impaginazione nella coordinata y", "[car]") {
    
    coca_device* macch = coca_init_device();

    macch->dimensionex = SFONDOX;
    macch->dimensioney = SFONDOY;

    macch->car.width = 350;
    macch->car.height = 80;

    macch->car.cx = (macch->dimensionex/2) - (macch->car.width/2);
    macch->car.cy = 550;

    REQUIRE(coca_check_posizioney(macch) == 1);

    delete(macch);    
}

TEST_CASE("coca_check_posizioney dovrebbe ritornare 0 se è rispettata l'impaginazione nella coordinata y", "[car]") {
    
    coca_device* macch = coca_init_device();

    macch->dimensionex = SFONDOX;
    macch->dimensioney = SFONDOY;

    macch->car.width = 350;
    macch->car.height = 80;

    macch->car.cx = (macch->dimensionex/2) - (macch->car.width/2);
    macch->car.cy = (macch->dimensioney/2) - (macch->car.height/2);

    REQUIRE(coca_check_posizioney(macch) == 0);

    delete(macch);    
}

// test sulla funzione coca_check_cerchioni
TEST_CASE("coca_check_cerchioni dovrebbe ritornare 1 se non è disponibile il diametro scelto", "[car]") {
    
    coca_device* macch = coca_init_device();

    macch->diametro = 20;

    REQUIRE(coca_check_cerchioni(macch) == 1);

    delete(macch);    
}

TEST_CASE("coca_check_cerchioni dovrebbe ritornare 0 se è disponibile il diametro scelto", "[car]") {
    
    coca_device* macch = coca_init_device();

    macch->diametro = 17;

    REQUIRE(coca_check_cerchioni(macch) == 0);

    delete(macch);    
}

// test sulla funzione coca_check_assetto
TEST_CASE("coca_check_assetto dovrebbe ritornare 1 se non è disponibile l'assetto scelto", "[car]") {

    coca_device* macch = coca_init_device();

    macch->assetto = 4;

    REQUIRE(coca_check_assetto(macch) == 1);

    delete(macch);    
}

TEST_CASE("coca_check_assetto dovrebbe ritornare 0 se è disponibile l'assetto scelto", "[car]") {

    coca_device* macch = coca_init_device();

    macch->assetto = 2;

    REQUIRE(coca_check_assetto(macch) == 0);

    delete(macch);    
}

// test sulla funzione coca_myset_device
TEST_CASE("coca_myset_device dovrebbe ritornare un puntatore a un device != NULL", "[car]") {

    coca_device* macch = coca_init_device();

    macch = coca_myset_device(macch);

    REQUIRE(macch != NULL);

    delete(macch);    
}

// test sulla funzione coca_intestazione
TEST_CASE("coca_intestazione dovrebbe ritornare una stringa != "" ", "[car]") {
    
    std::string svg;
    coca_device* macch = coca_init_device();

    svg = coca_intestazione(macch);

    REQUIRE(svg != "");

    delete(macch);    
}

// test sulla funzione coca_sfondo
TEST_CASE("coca_sfondo dovrebbe ritornare una stringa != "" ", "[car]") {
    
    std::string svg;
    coca_device* macch = coca_init_device();

    svg = coca_sfondo(macch);

    REQUIRE(svg != "");

    delete(macch);    
}

// test sulla funzione coca_fine
TEST_CASE("coca_fine dovrebbe ritornare una stringa != "" ", "[car]") {
    
    std::string svg;
    coca_device* macch = coca_init_device();

    svg = coca_fine();

    REQUIRE(svg != "");

    delete(macch);    
}

// test sulla funzione coca_strg_device
TEST_CASE("coca_strg_device dovrebbe ritornare una stringa != "" ", "[car]") {
    
    std::string svg;
    coca_device* macch = coca_init_device();

    svg = coca_strg_device(macch, 1, 1);

    REQUIRE(svg != "");

    delete(macch);    
}
 
// test sulla funzione coca_quotatura
TEST_CASE("coca_quotatura dovrebbe ritornare una stringa != "" ", "[car]") {
    
    std::string svg;
    coca_device* macch = coca_init_device();

    svg = coca_quotatura(macch);

    REQUIRE(svg != "");

    delete(macch);    
}

// test sulla funzione coca_write
TEST_CASE("coca_write dovrebbe ritornare 1 se la stringa vuota ", "[car]") {
    
    std::string svg;

    REQUIRE(coca_write(svg) == 1);
 
}

// test sulla funzione coca_parse_device
TEST_CASE("coca_parse_device dovrebbe ritornare un puntatore a un device == NULL se il file letto è vuoto", "[car]") {
    
    std::string svg = "";

    coca_device* macch = coca_init_device();

    macch = coca_parse_device(macch, svg);

    REQUIRE(macch == NULL);

    delete(macch); 
}

TEST_CASE("coca_parse_device dovrebbe ritornare la dimensione del foglio dalla stringa letta", "[car]") {

    std::string svg = "<?xml version='1.0' encoding='UTF-8' standalone='no'?> <svg xmlns='http://www.w3.org/2000/svg' width='800.000000' height='600.000000'> <rect  x='0' y='0' width='800.000000' height='600.000000' style='fill:rgb(255,255,255);stroke-width:3;stroke:rgb(0,0,0)'/> <rect x='225.000000' y='260.000000' rx='10' ry='10' width='350.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/> <circle cx='295.000000' cy='340.000000' r='39.500000' stroke='black' stroke-width='3' fill='black'/> <circle cx='295.000000' cy='340.000000' r='24.687500' stroke='black' stroke-width='3' fill='gray'/> <circle cx='505.000000' cy='340.000000' r='39.500000' stroke='black' stroke-width='3' fill='black'/> <circle cx='505.000000' cy='340.000000' r='24.687500' stroke='black' stroke-width='3' fill='gray'/> <polygon points='285.000336,260.000000 325.000000,199.999847 425.000000,199.999847 425.000000,260.000000 285.000336,260.000000' style='fill:red;stroke:black;stroke-width:5'/> <polygon points='425.000000,199.999847 505.000000,260.000000 425.000000,260.000000' style='fill:lightblue;stroke:black;stroke-width:5' /> <rect x='235.000000' y='230.000000' width='20.000000' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/> </svg>";
    
    coca_device* macch = coca_init_device();
    macch = coca_parse_device(macch, svg);

    REQUIRE(macch->dimensionex == (float)800);
    REQUIRE(macch->dimensioney == (float)600);   

    delete(macch);
}

TEST_CASE("coca_parse_device dovrebbe ritornare la dimensione della carrozzeria dalla stringa letta", "[car]") {

    std::string svg = "<?xml version='1.0' encoding='UTF-8' standalone='no'?> <svg xmlns='http://www.w3.org/2000/svg' width='800.000000' height='600.000000'> <rect  x='0' y='0' width='800.000000' height='600.000000' style='fill:rgb(255,255,255);stroke-width:3;stroke:rgb(0,0,0)'/> <rect x='225.000000' y='260.000000' rx='10' ry='10' width='350.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/> <circle cx='295.000000' cy='340.000000' r='39.500000' stroke='black' stroke-width='3' fill='black'/> <circle cx='295.000000' cy='340.000000' r='24.687500' stroke='black' stroke-width='3' fill='gray'/> <circle cx='505.000000' cy='340.000000' r='39.500000' stroke='black' stroke-width='3' fill='black'/> <circle cx='505.000000' cy='340.000000' r='24.687500' stroke='black' stroke-width='3' fill='gray'/> <polygon points='285.000336,260.000000 325.000000,199.999847 425.000000,199.999847 425.000000,260.000000 285.000336,260.000000' style='fill:red;stroke:black;stroke-width:5'/> <polygon points='425.000000,199.999847 505.000000,260.000000 425.000000,260.000000' style='fill:lightblue;stroke:black;stroke-width:5' /> <rect x='235.000000' y='230.000000' width='20.000000' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/> </svg>";
    
    coca_device* macch = coca_init_device();
    macch = coca_parse_device(macch, svg);
    
    REQUIRE(macch->car.cx == (float)225);
    REQUIRE(macch->car.cy == (float)260);
    REQUIRE(macch->car.width == (float)350);
    REQUIRE(macch->car.height == (float)80);

    delete(macch);
}

TEST_CASE("coca_parse_device dovrebbe ritornare la dimensione delle ruote dalla stringa letta", "[car]") {

    std::string svg = "<?xml version='1.0' encoding='UTF-8' standalone='no'?> <svg xmlns='http://www.w3.org/2000/svg' width='800.000000' height='600.000000'> <rect  x='0' y='0' width='800.000000' height='600.000000' style='fill:rgb(255,255,255);stroke-width:3;stroke:rgb(0,0,0)'/> <rect x='225.000000' y='260.000000' rx='10' ry='10' width='350.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/> <circle cx='295.000000' cy='340.000000' r='39.500000' stroke='black' stroke-width='3' fill='black'/> <circle cx='295.000000' cy='340.000000' r='24.687500' stroke='black' stroke-width='3' fill='gray'/> <circle cx='505.000000' cy='340.000000' r='39.500000' stroke='black' stroke-width='3' fill='black'/> <circle cx='505.000000' cy='340.000000' r='24.687500' stroke='black' stroke-width='3' fill='gray'/> <polygon points='285.000336,260.000000 325.000000,199.999847 425.000000,199.999847 425.000000,260.000000 285.000336,260.000000' style='fill:red;stroke:black;stroke-width:5'/> <polygon points='425.000000,199.999847 505.000000,260.000000 425.000000,260.000000' style='fill:lightblue;stroke:black;stroke-width:5' /> <rect x='235.000000' y='230.000000' width='20.000000' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/> </svg>";
    
    coca_device* macch = coca_init_device();
    macch = coca_parse_device(macch, svg);
    
    REQUIRE(macch->sx.centrox == (float)295);
    REQUIRE(macch->sx.centroy == (float)340);
    REQUIRE(macch->sx.ruota == (float)39.5);
    REQUIRE(macch->sx.cerchione == (float)24.687500);
    REQUIRE(macch->dx.centrox == (float)505);
    REQUIRE(macch->dx.centroy == (float)340);
    REQUIRE(macch->dx.ruota == (float)39.5);
    REQUIRE(macch->dx.cerchione == (float)24.687500);

    delete(macch);
}

TEST_CASE("coca_parse_device dovrebbe ritornare la dimensione del tetto dalla stringa letta", "[car]") {

    std::string svg = "<?xml version='1.0' encoding='UTF-8' standalone='no'?> <svg xmlns='http://www.w3.org/2000/svg' width='800.000000' height='600.000000'> <rect  x='0' y='0' width='800.000000' height='600.000000' style='fill:rgb(255,255,255);stroke-width:3;stroke:rgb(0,0,0)'/> <rect x='225.000000' y='260.000000' rx='10' ry='10' width='350.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/> <circle cx='295.000000' cy='340.000000' r='39.500000' stroke='black' stroke-width='3' fill='black'/> <circle cx='295.000000' cy='340.000000' r='24.687500' stroke='black' stroke-width='3' fill='gray'/> <circle cx='505.000000' cy='340.000000' r='39.500000' stroke='black' stroke-width='3' fill='black'/> <circle cx='505.000000' cy='340.000000' r='24.687500' stroke='black' stroke-width='3' fill='gray'/> <polygon points='285.000336,260.000000 325.000000,199.999847 425.000000,199.999847 425.000000,260.000000 285.000336,260.000000' style='fill:red;stroke:black;stroke-width:5'/> <polygon points='425.000000,199.999847 505.000000,260.000000 425.000000,260.000000' style='fill:lightblue;stroke:black;stroke-width:5' /> <rect x='235.000000' y='230.000000' width='20.000000' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/> </svg>";
    
    coca_device* macch = coca_init_device();
    macch = coca_parse_device(macch, svg);
    
    REQUIRE(macch->cap.x1 == (float)285.000336);
    REQUIRE(macch->cap.y1 == (float)260);

    REQUIRE(macch->cap.x2 == (float)325);
    REQUIRE(macch->cap.y2 == (float)199.999847);

    REQUIRE(macch->cap.x3 == (float)425);
    REQUIRE(macch->cap.y3 == (float)199.999847);

    REQUIRE(macch->cap.x4 == (float)425);
    REQUIRE(macch->cap.y4 == (float)260);

    REQUIRE(macch->cap.x5 == (float)285.000336);
    REQUIRE(macch->cap.y5 == (float)260);

    delete(macch);
}

TEST_CASE("coca_parse_device dovrebbe ritornare la dimensione dei finestrini dalla stringa letta", "[car]") {

    std::string svg = "<?xml version='1.0' encoding='UTF-8' standalone='no'?> <svg xmlns='http://www.w3.org/2000/svg' width='800.000000' height='600.000000'> <rect  x='0' y='0' width='800.000000' height='600.000000' style='fill:rgb(255,255,255);stroke-width:3;stroke:rgb(0,0,0)'/> <rect x='225.000000' y='260.000000' rx='10' ry='10' width='350.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/> <circle cx='295.000000' cy='340.000000' r='39.500000' stroke='black' stroke-width='3' fill='black'/> <circle cx='295.000000' cy='340.000000' r='24.687500' stroke='black' stroke-width='3' fill='gray'/> <circle cx='505.000000' cy='340.000000' r='39.500000' stroke='black' stroke-width='3' fill='black'/> <circle cx='505.000000' cy='340.000000' r='24.687500' stroke='black' stroke-width='3' fill='gray'/> <polygon points='285.000336,260.000000 325.000000,199.999847 425.000000,199.999847 425.000000,260.000000 285.000336,260.000000' style='fill:red;stroke:black;stroke-width:5'/> <polygon points='425.000000,199.999847 505.000000,260.000000 425.000000,260.000000' style='fill:lightblue;stroke:black;stroke-width:5' /> <rect x='235.000000' y='230.000000' width='20.000000' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/> </svg>";
    
    coca_device* macch = coca_init_device();
    macch = coca_parse_device(macch, svg);
    
    REQUIRE(macch->fin.p1x == (float)425);
    REQUIRE(macch->fin.p1y == (float)199.999847);

    REQUIRE(macch->fin.p2x == (float)505);
    REQUIRE(macch->fin.p2y == (float)260);

    REQUIRE(macch->fin.p3x == (float)425);
    REQUIRE(macch->fin.p3y == (float)260);

    delete(macch);
}

TEST_CASE("coca_parse_device dovrebbe ritornare la dimensione dello spoiler dalla stringa letta", "[car]") {

    std::string svg = "<?xml version='1.0' encoding='UTF-8' standalone='no'?> <svg xmlns='http://www.w3.org/2000/svg' width='800.000000' height='600.000000'> <rect  x='0' y='0' width='800.000000' height='600.000000' style='fill:rgb(255,255,255);stroke-width:3;stroke:rgb(0,0,0)'/> <rect x='225.000000' y='260.000000' rx='10' ry='10' width='350.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/> <circle cx='295.000000' cy='340.000000' r='39.500000' stroke='black' stroke-width='3' fill='black'/> <circle cx='295.000000' cy='340.000000' r='24.687500' stroke='black' stroke-width='3' fill='gray'/> <circle cx='505.000000' cy='340.000000' r='39.500000' stroke='black' stroke-width='3' fill='black'/> <circle cx='505.000000' cy='340.000000' r='24.687500' stroke='black' stroke-width='3' fill='gray'/> <polygon points='285.000336,260.000000 325.000000,199.999847 425.000000,199.999847 425.000000,260.000000 285.000336,260.000000' style='fill:red;stroke:black;stroke-width:5'/> <polygon points='425.000000,199.999847 505.000000,260.000000 425.000000,260.000000' style='fill:lightblue;stroke:black;stroke-width:5' /> <rect x='235.000000' y='230.000000' width='20.000000' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/> </svg>";
    
    coca_device* macch = coca_init_device();
    macch = coca_parse_device(macch, svg);
    
    REQUIRE(macch->spoil.px == (float)235);
    REQUIRE(macch->spoil.py == (float)230);
    REQUIRE(macch->spoil.widths == (float)20);
    REQUIRE(macch->spoil.heights == (float)29.999996);

    delete(macch);
}