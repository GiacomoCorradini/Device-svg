#include "catch2/catch2.hpp"
#include "Car.h"

// test sulla funzione coca_init
TEST_CASE("coca_init dovrebbe ritornare un puntatore a un device != NULL", "[car]") {
        
    coca_device* macch = coca_init();

    REQUIRE(macch != NULL);

    delete(macch);    
}

// test sulla funzione coca_check_car
TEST_CASE("coca_check_car dovrebbe ritornare 1 se non è rispettato il rapporto width/height < 3", "[car]") {
    
    coca_device* macch = coca_init();
    
    macch->car.width = 300;
    macch->car.height = 150;

    REQUIRE(coca_check_car(macch) == 1);

    delete(macch);    
}

TEST_CASE("coca_check_car dovrebbe ritornare 0 se è rispettato il rapporto width/height < 3", "[car]") {
        
    coca_device* macch = coca_init();

    macch->car.width = 350;
    macch->car.height = 80;

    REQUIRE(coca_check_car(macch) == 0);

    delete(macch);    
}

// test sulla funzione coca_check_posizionex
TEST_CASE("coca_check_posizionex dovrebbe ritornare 1 se non è rispettata l'impaginazione nella coordinata x", "[car]") {
    
    coca_device* macch = coca_init();

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
    
    coca_device* macch = coca_init();

    macch->dimensionex = SFONDOX;
    macch->dimensioney = SFONDOY;

    macch->car.width = 350;
    macch->car.height = 80;

    macch->car.cx = (macch->dimensionex/2) - (macch->car.width/2);
    macch->car.cy = (macch->dimensioney/2) - (macch->car.height/2);

    REQUIRE(coca_check_posizionex(macch) == 0);

    delete(macch);    
}

// test sulla funzione coca_check_posizioney
TEST_CASE("coca_check_posizioney dovrebbe ritornare 1 se non è rispettata l'impaginazione nella coordinata y", "[car]") {
    
    coca_device* macch = coca_init();

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
    
    coca_device* macch = coca_init();

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
    
    int diametro;
    int* pdiametro = &diametro;
    coca_device* macch = coca_init();

    (*pdiametro) = 20;

    REQUIRE(coca_check_cerchioni(macch, pdiametro) == 1);

    delete(macch);    
}

TEST_CASE("coca_check_cerchioni dovrebbe ritornare 0 se è disponibile il diametro scelto", "[car]") {
    
    int diametro;
    int* pdiametro = &diametro;
    coca_device* macch = coca_init();

    (*pdiametro) = 17;

    REQUIRE(coca_check_cerchioni(macch, pdiametro) == 0);

    delete(macch);    
}

// test sulla funzione coca_check_assetto
TEST_CASE("coca_check_assetto dovrebbe ritornare 1 se non è disponibile l'assetto scelto", "[car]") {
    
    int x;
    int* px = &x;
    coca_device* macch = coca_init();

    (*px) = 4;

    REQUIRE(coca_check_assetto(macch, px) == 1);

    delete(macch);    
}

TEST_CASE("coca_check_assetto dovrebbe ritornare 0 se è disponibile l'assetto scelto", "[car]") {
    
    int x;
    int* px = &x;
    coca_device* macch = coca_init();

    (*px) = 2;

    REQUIRE(coca_check_assetto(macch, px) == 0);

    delete(macch);    
}

// test sulla funzione coca_riset
TEST_CASE("coca_riset dovrebbe ritornare un puntatore a un device != NULL", "[car]") {
    
    int scelta, diametro, x, icheck;
    int* pscelta = &scelta;
    int* pdiametro = &diametro;
    int* px = &x;
    int* check = &icheck;

    coca_device* macch = coca_init();

    macch = coca_riset(macch, pscelta, pdiametro, px, check);

    REQUIRE(macch != NULL);

    delete(macch);    
}

// test sulla funzione coca_cin_carrozzeria
TEST_CASE("coca_cin_carrozzeria dovrebbe inizializzare a 1 la variabile check se non sono rispettati i vincoli sulla carrozzeria", "[car]") {
    
    int icheck;
    int* check = &icheck;
    coca_device* macch = coca_init();
    std::cout << "REQUIRE: IMMETTERE I SEGUENTI VALORI:" << std::endl;
    std::cout << "LUNGHEZZA: 350" << std::endl;
    std::cout << "ALTEZZA: 150" << std::endl;
    macch = coca_cin_carrozzeria(macch, check);

    REQUIRE(icheck == 1);

    delete(macch);    
}

// test sulla funzione coca_cin_posizione
TEST_CASE("coca_cin_posizione dovrebbe inizializzare a 2 la variabile check se non sono rispettati i vincoli sulla posizione x", "[car]") {
    
    int icheck, scelta;
    int* check = &icheck;
    int* pscelta = &scelta;
    coca_device* macch = coca_init();
    macch->dimensionex = SFONDOX;
    macch->dimensioney = SFONDOY;
    macch->car.width = 350;
    macch->car.height = 80;
    std::cout << "REQUIRE: IMMETTERE I SEGUENTI VALORI:" << std::endl;
    std::cout << "SCELTA: 1" << std::endl;
    std::cout << "POSIZIONE X: 700" << std::endl;
    std::cout << "POSIZIONE Y: 260" << std::endl;
    macch = coca_cin_posizione(macch, pscelta, check);

    REQUIRE(icheck == 2);

    delete(macch);    
}

TEST_CASE("coca_cin_posizione dovrebbe inizializzare a 2 la variabile check se non sono rispettati i vincoli sulla posizione y", "[car]") {
    
    int icheck, scelta;
    int* check = &icheck;
    int* pscelta = &scelta;
    coca_device* macch = coca_init();
    macch->dimensionex = SFONDOX;
    macch->dimensioney = SFONDOY;
    macch->car.width = 350;
    macch->car.height = 80;
    std::cout << "REQUIRE: IMMETTERE I SEGUENTI VALORI:" << std::endl;
    std::cout << "SCELTA: 1" << std::endl;
    std::cout << "POSIZIONE X: 225" << std::endl;
    std::cout << "POSIZIONE Y: 550" << std::endl;
    macch = coca_cin_posizione(macch, pscelta, check);

    REQUIRE(icheck == 2);

    delete(macch);    
}

// test sulla funzione coca_cin_ruote
TEST_CASE("coca_cin_ruote dovrebbe inizializzare a 3 la variabile check se non sono rispettati i vincoli sui cerchioni", "[car]") {
    
    int icheck, diametro;
    int* check = &icheck;
    int* pdiametro = &diametro;
    coca_device* macch = coca_init();
    std::cout << "REQUIRE: IMMETTERE I SEGUENTI VALORI:" << std::endl;
    std::cout << "CERCHIONI: 20" << std::endl;
    macch = coca_cin_ruote(macch, pdiametro, check);

    REQUIRE(icheck == 3);

    delete(macch);    
}

// test sulla funzione coca_cin_assetto
TEST_CASE("coca_cin_assetto dovrebbe inizializzare a 4 la variabile check se non sono rispettati i vincoli sull'assetto", "[car]") {
    
    int icheck, x;
    int* check = &icheck;
    int* px = &x;
    coca_device* macch = coca_init();
    std::cout << "REQUIRE: IMMETTERE I SEGUENTI VALORI:" << std::endl;
    std::cout << "ASSETTO: 5" << std::endl;
    macch = coca_cin_assetto(macch, px, check);

    REQUIRE(icheck == 4);

    delete(macch);    
}

// test sulla funzione coca_cin_device
TEST_CASE("coca_cin_device dovrebbe ritornare un puntatore a un device = NULL se viene passato un puntatore a NULL", "[car]") {
    
    int scelta, diametro, x, check;
    int* pscelta = &scelta;
    int* pdiametro = &diametro;
    int* px = &x;
    int* icheck = &check;
    coca_device* macch = NULL;

    macch = coca_cin_device(macch, pscelta, pdiametro, px, icheck);

    REQUIRE(macch == NULL);

    delete(macch);    
}

// test sulla funzione coca_try_ruote
TEST_CASE("coca_try_ruote dovrebbe ritornare un puntatore a un device != NULL", "[car]") {
    
    int diametro;
    coca_device* macch = coca_init();

    macch = coca_try_ruote(macch, diametro);

    REQUIRE(macch != NULL);

    delete(macch);    
}

// test sulla funzione coca_try_assetto
TEST_CASE("coca_try_assetto dovrebbe ritornare un puntatore a un device != NULL", "[car]") {
    
    int x;
    coca_device* macch = coca_init();

    macch = coca_try_assetto(macch, x);

    REQUIRE(macch != NULL);

    delete(macch);    
}

// test sulla funzione coca_try_finestrini
TEST_CASE("coca_try_finestrini dovrebbe ritornare un puntatore a un device != NULL", "[car]") {
    
    coca_device* macch = coca_init();

    macch = coca_try_finestrini(macch);

    REQUIRE(macch != NULL);

    delete(macch);    
}

// test sulla funzione coca_try_spoiler
TEST_CASE("coca_try_spoiler dovrebbe ritornare un puntatore a un device != NULL", "[car]") {
    
    coca_device* macch = coca_init();

    macch = coca_try_spoiler(macch);

    REQUIRE(macch != NULL);

    delete(macch);    
}

// test sulla funzione coca_try_tetto
TEST_CASE("coca_try_tetto dovrebbe ritornare un puntatore a un device != NULL", "[car]") {
    
    coca_device* macch = coca_init();

    macch = coca_try_tetto(macch);

    REQUIRE(macch != NULL);

    delete(macch);    
}

// test sulla funzione coca_try_device
TEST_CASE("coca_try_device dovrebbe ritornare un puntatore a un device != NULL", "[car]") {
    
    int scelta, diametro, x;
    coca_device* macch = coca_init();

    macch = coca_try_device(macch, scelta, diametro, x);

    REQUIRE(macch != NULL);

    delete(macch);    
}

// test sulla funzione coca_intestazione
TEST_CASE("coca_intestazione dovrebbe ritornare una stringa != "" ", "[car]") {
    
    std::string svg;
    coca_device* macch = coca_init();

    svg = coca_intestazione(macch);

    REQUIRE(svg != "");

    delete(macch);    
}

// test sulla funzione coca_sfondo
TEST_CASE("coca_sfondo dovrebbe ritornare una stringa != "" ", "[car]") {
    
    std::string svg;
    coca_device* macch = coca_init();

    svg = coca_sfondo(macch);

    REQUIRE(svg != "");

    delete(macch);    
}

// test sulla funzione coca_fine
TEST_CASE("coca_fine dovrebbe ritornare una stringa != "" ", "[car]") {
    
    std::string svg;
    coca_device* macch = coca_init();

    svg = coca_fine();

    REQUIRE(svg != "");

    delete(macch);    
}

// test sulla funzione coca_strg_carrozzeria
TEST_CASE("coca_strg_carrozzeria dovrebbe ritornare una stringa != "" ", "[car]") {
    
    std::string svg;
    coca_device* macch = coca_init();

    svg = coca_strg_carrozzeria(macch);

    REQUIRE(svg != "");

    delete(macch);    
}

// test sulla funzione coca_strg_ruote
TEST_CASE("coca_strg_ruote dovrebbe ritornare una stringa != "" ", "[car]") {
    
    std::string svg;
    coca_device* macch = coca_init();

    svg = coca_strg_ruote(macch);

    REQUIRE(svg != "");

    delete(macch);    
}

// test sulla funzione coca_strg_finestrini
TEST_CASE("coca_strg_finestrini dovrebbe ritornare una stringa != "" ", "[car]") {
    
    std::string svg;
    coca_device* macch = coca_init();

    svg = coca_strg_finestrini(macch);

    REQUIRE(svg != "");

    delete(macch);    
}

// test sulla funzione coca_strg_spoiler
TEST_CASE("coca_strg_spoiler dovrebbe ritornare una stringa != "" ", "[car]") {
    
    std::string svg;
    coca_device* macch = coca_init();

    svg = coca_strg_spoiler(macch);

    REQUIRE(svg != "");

    delete(macch);    
}

// test sulla funzione coca_strg_tetto
TEST_CASE("coca_strg_tetto dovrebbe ritornare una stringa != "" ", "[car]") {
    
    std::string svg;
    coca_device* macch = coca_init();

    svg = coca_strg_tetto(macch);

    REQUIRE(svg != "");

    delete(macch);    
}

// test sulla funzione coca_strg_device
TEST_CASE("coca_strg_device dovrebbe ritornare una stringa != "" ", "[car]") {
    
    std::string svg;
    int scelta, quota;
    coca_device* macch = coca_init();

    svg = coca_strg_device(macch, scelta, quota);

    REQUIRE(svg != "");

    delete(macch);    
}

// test sulla funzione coca_quotatura
TEST_CASE("coca_quotatura dovrebbe ritornare una stringa != "" ", "[car]") {
    
    std::string svg;
    coca_device* macch = coca_init();

    svg = coca_quotatura(macch);

    REQUIRE(svg != "");

    delete(macch);    
}

// test sulla funzione coca_write
TEST_CASE("coca_write dovrebbe ritornare 1 se la stringa vuota ", "[car]") {
    
    std::string svg;

    REQUIRE(coca_write(svg) == 1);
 
}