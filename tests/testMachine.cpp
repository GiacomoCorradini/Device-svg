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

    machine->car[0]->car.width = 300;
    machine->car[0]->car.height = 80;
    machine->car[0]->diametro = 17;
    machine->car[0]->assetto = 3;

    machine->car[0] = coca_myset_device(machine->car[0]);

    machine = coca_myset_machine(machine);

    REQUIRE(machine->car[0]->dx.ruota == 40);
    REQUIRE(machine->car[1]->dx.ruota == 40);
    REQUIRE(machine->car[2]->dx.ruota == 40);
    
    REQUIRE(machine->car[0]->sx.ruota == 40);
    REQUIRE(machine->car[1]->sx.ruota == 40);
    REQUIRE(machine->car[2]->sx.ruota == 40);

    REQUIRE(machine->motrice->ruotadx.r == 40);
    REQUIRE(machine->motrice->ruotasx.r == 40);

    delete(machine);
}

// test sulla funzione coca_myset_machine, coca_myset_poscar
TEST_CASE("coca_myset_machine dovrebbe settare i parametri della prima macchina nel caso ci sia solo una macchina sul carroattrezzi", "[machine]") {

    coca_machine* machine = new coca_machine;
    machine->numero = 1;
    machine = coca_init_machine(machine);

    machine->car[0]->car.width = 300;
    machine->car[0]->car.height = 80;
    machine->car[0]->diametro = 17;
    machine->car[0]->assetto = 3;

    machine = coca_myset_machine(machine);
    
    float a = machine->motrice->cabina.x + machine->motrice->cabina.w + machine->dist_macchine;
    
    REQUIRE(machine->car[0]->car.cx == a);

    delete(machine);
}

// test sulla funzione coca_parse_machine
TEST_CASE("coca_parse_machine deve settare il device motrice", "[machine]") {

    string svg = "<?xml version='1.0' encoding='UTF-8' standalone='no'?> <svg xmlns='http://www.w3.org/2000/svg' width='3377.000000' height='706.666626'>";
           svg += "<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='529.500000' height='213.333328' x='100.000000' y='150.000000' />";
           svg += "<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='264.750000' height='106.666664' x='100.000000' y='192.666656' />";
           svg += "<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='1588.500000' height='53.333332' x='100.000000' y='363.333313' />";
           svg += "<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='364.750000' cy='416.666656' rx='40.000000' ry='40.000000' />";
           svg += "<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='1423.750000' cy='416.666656' rx='40.000000' ry='40.000000' />";
           svg += "<!-- N° car: 3-->";
           svg += "<rect x='632.500000' y='243.333313' rx='10' ry='10' width='350.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<circle cx='702.500000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
           svg += "<circle cx='702.500000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
           svg += "<circle cx='912.500000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
           svg += "<circle cx='912.500000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
           svg += "<polygon points='692.500366,243.333313 732.500000,183.333160 832.500000,183.333160 832.500000,243.333313 692.500366,243.333313' style='fill:red;stroke:black;stroke-width:5'/>";
           svg += "<polygon points='832.500000,183.333160 912.500000,243.333313 832.500000,243.333313' style='fill:lightblue;stroke:black;stroke-width:5' />";
           svg += "<rect x='642.500000' y='213.333313' width='20.000000' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<rect x='985.500000' y='243.333313' rx='10' ry='10' width='350.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<circle cx='1055.500000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
           svg += "<circle cx='1055.500000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
           svg += "<circle cx='1265.500000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
           svg += "<circle cx='1265.500000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
           svg += "<polygon points='1045.500366,243.333313 1085.500000,183.333160 1185.500000,183.333160 1185.500000,243.333313 1045.500366,243.333313' style='fill:red;stroke:black;stroke-width:5'/>";
           svg += "<polygon points='1185.500000,183.333160 1265.500000,243.333313 1185.500000,243.333313' style='fill:lightblue;stroke:black;stroke-width:5' />";
           svg += "<rect x='995.500000' y='213.333313' width='20.000000' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<rect x='1338.500000' y='243.333313' rx='10' ry='10' width='350.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<circle cx='1408.500000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
           svg += "<circle cx='1408.500000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
           svg += "<circle cx='1618.500000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
           svg += "<circle cx='1618.500000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
           svg += "<polygon points='1398.500366,243.333313 1438.500000,183.333160 1538.500000,183.333160 1538.500000,243.333313 1398.500366,243.333313' style='fill:red;stroke:black;stroke-width:5'/>";
           svg += "<polygon points='1538.500000,183.333160 1618.500000,243.333313 1538.500000,243.333313' style='fill:lightblue;stroke:black;stroke-width:5' />";
           svg += "<rect x='1348.500000' y='213.333313' width='20.000000' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/> </svg>";

    coca_machine* macch = coca_parse_machine(svg);

    REQUIRE(macch->numero == 3);
    REQUIRE(macch->motrice->w == (float)3377.000000);
    REQUIRE(macch->motrice->h == (float)706.666626);
    REQUIRE(macch->motrice->cabina.w == (float)529.500000);
    REQUIRE(macch->motrice->cabina.h == (float)213.333328);
    REQUIRE(macch->motrice->cabina.x == (float)100.000000);
    REQUIRE(macch->motrice->cabina.y == (float)150.000000);
    REQUIRE(macch->motrice->ruotasx.x == (float)364.750000);
    REQUIRE(macch->motrice->ruotasx.y == (float)416.666656);
    REQUIRE(macch->motrice->ruotasx.r == (float)40.000000);
    REQUIRE(macch->motrice->ruotadx.x == (float)1423.750000);
    REQUIRE(macch->motrice->ruotadx.y == (float)416.666656);
    REQUIRE(macch->motrice->ruotadx.r == (float)40.000000);

    delete(macch);
}

// test sulla funzione coca_parse_machine
TEST_CASE("coca_parse_machine deve settare i device car", "[machine]") {

    string svg = "<?xml version='1.0' encoding='UTF-8' standalone='no'?> <svg xmlns='http://www.w3.org/2000/svg' width='3377.000000' height='706.666626'>";
           svg += "<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='529.500000' height='213.333328' x='100.000000' y='150.000000' />";
           svg += "<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='264.750000' height='106.666664' x='100.000000' y='192.666656' />";
           svg += "<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='1588.500000' height='53.333332' x='100.000000' y='363.333313' />";
           svg += "<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='364.750000' cy='416.666656' rx='40.000000' ry='40.000000' />";
           svg += "<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='1423.750000' cy='416.666656' rx='40.000000' ry='40.000000' />";
           svg += "<!-- N° car: 3-->";
           svg += "<rect x='632.500000' y='243.333313' rx='10' ry='10' width='350.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<circle cx='702.500000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
           svg += "<circle cx='702.500000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
           svg += "<circle cx='912.500000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
           svg += "<circle cx='912.500000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
           svg += "<polygon points='692.500366,243.333313 732.500000,183.333160 832.500000,183.333160 832.500000,243.333313 692.500366,243.333313' style='fill:red;stroke:black;stroke-width:5'/>";
           svg += "<polygon points='832.500000,183.333160 912.500000,243.333313 832.500000,243.333313' style='fill:lightblue;stroke:black;stroke-width:5' />";
           svg += "<rect x='642.500000' y='213.333313' width='20.000000' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<rect x='985.500000' y='243.333313' rx='10' ry='10' width='350.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<circle cx='1055.500000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
           svg += "<circle cx='1055.500000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
           svg += "<circle cx='1265.500000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
           svg += "<circle cx='1265.500000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
           svg += "<polygon points='1045.500366,243.333313 1085.500000,183.333160 1185.500000,183.333160 1185.500000,243.333313 1045.500366,243.333313' style='fill:red;stroke:black;stroke-width:5'/>";
           svg += "<polygon points='1185.500000,183.333160 1265.500000,243.333313 1185.500000,243.333313' style='fill:lightblue;stroke:black;stroke-width:5' />";
           svg += "<rect x='995.500000' y='213.333313' width='20.000000' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<rect x='1338.500000' y='243.333313' rx='10' ry='10' width='350.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<circle cx='1408.500000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
           svg += "<circle cx='1408.500000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
           svg += "<circle cx='1618.500000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
           svg += "<circle cx='1618.500000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
           svg += "<polygon points='1398.500366,243.333313 1438.500000,183.333160 1538.500000,183.333160 1538.500000,243.333313 1398.500366,243.333313' style='fill:red;stroke:black;stroke-width:5'/>";
           svg += "<polygon points='1538.500000,183.333160 1618.500000,243.333313 1538.500000,243.333313' style='fill:lightblue;stroke:black;stroke-width:5' />";
           svg += "<rect x='1348.500000' y='213.333313' width='20.000000' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/> </svg>";

    coca_machine* macch = coca_parse_machine(svg);

    REQUIRE(macch->car[0]->car.width == (float)350.000000);
    REQUIRE(macch->car[0]->car.height == (float)80.000000);
    REQUIRE(macch->car[1]->car.width == (float)350.000000);
    REQUIRE(macch->car[1]->car.height == (float)80.000000);
    REQUIRE(macch->car[2]->car.width == (float)350.000000);
    REQUIRE(macch->car[2]->car.height == (float)80.000000);
    
    delete(macch);
}