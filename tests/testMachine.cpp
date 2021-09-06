#include "catch2/catch2.hpp"
#include "machine.h"

// test sulla funzione coca_init_machine
TEST_CASE("coca_init_machine dovrebbe ritornare un puntatore a un machine != NULL", "[machine]") {

    coca_machine* machine = new coca_machine;
    machine->numero = 3;
    machine = coca_init_machine(machine);

    REQUIRE(machine != NULL);
    REQUIRE(machine->car[0] != NULL);
    REQUIRE(machine->car[1] != NULL);
    REQUIRE(machine->car[2] != NULL);
    REQUIRE(machine->numero == 3);

    delete(machine);
}

// test sulla funzione coca_strg_machine
TEST_CASE("coca_init_strg dovrebbe ritornare una stringa != "" ", "[machine]") {

    coca_machine* machine = new coca_machine;
    machine = coca_init_machine(machine);

    string svg = coca_strg_machine(machine, 1);
    
    REQUIRE(svg != "");

    delete(machine);
}

// test sulla funzione coca_myset_machine
TEST_CASE("coca_myset_machine dovrebbe settare dist_machine pari a 3", "[machine]") {

    coca_machine* machine = new coca_machine;
    machine->numero = 3;
    machine = coca_init_machine(machine);

    machine->car[0]->car.width = 300;

    machine = coca_myset_machine(machine);

    REQUIRE(machine->dist_macchine == 3);

    delete(machine);
}

// test sulla funzione coca_myset_machine
TEST_CASE("coca_myset_machine dovrebbe settare le ruote della motrice uguali a quelle della macchina", "[machine]") {

    coca_machine* machine = new coca_machine;
    machine->numero = 3;
    machine = coca_init_machine(machine);

    machine->car[0]->dx.ruota = 40;
    machine->car[0]->sx.ruota = 40;

    machine = coca_myset_machine(machine);

    REQUIRE(machine->car[0]->dx.ruota == 40);
    REQUIRE(machine->car[1]->dx.ruota == 40);
    REQUIRE(machine->car[2]->dx.ruota == 40);
    
    REQUIRE(machine->car[0]->sx.ruota == 40);
    REQUIRE(machine->car[1]->sx.ruota == 40);
    REQUIRE(machine->car[2]->sx.ruota == 40);
    REQUIRE(machine->car[3]->sx.ruota != 40);

    REQUIRE(machine->motrice->ruotadx.r == 40);
    REQUIRE(machine->motrice->ruotasx.r == 40);


    delete(machine);
}

// test sulla funzione coca_myset_poscar
TEST_CASE("coca_myset_poscar dovrebbe settare la posizione della macchina sul carro attrezzi", "[machine]") {

    coca_machine* machine = new coca_machine;
    machine->numero = 3;
    machine = coca_init_machine(machine);

    machine->car[0]->car.width = 300;
    machine->car[0]->car.height = 80;
    machine->car[0]->diametro = 17;
    machine->car[0]->assetto = 3;

    machine = coca_myset_machine(machine);

    float a = machine->motrice->cabina.x + machine->motrice->cabina.w + machine->dist_macchine;
    float b = machine->motrice->pianale.y - machine->car[0]->car.height - machine->car[0]->dx.ruota;

    REQUIRE(machine->car[0]->car.cx == a);
    REQUIRE(machine->car[0]->car.cy == b);


    delete(machine);
}