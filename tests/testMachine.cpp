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

    string svg = "<?xml version='1.0' encoding='UTF-8' standalone='no'?> <svg xmlns='http://www.w3.org/2000/svg' width='3836.000000' height='706.666626'>";
           svg += "<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='606.000000' height='213.333328' x='100.000000' y='150.000000' />";
           svg += "<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='303.000000' height='106.666664' x='100.000000' y='192.666656' />";
           svg += "<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='1818.000000' height='53.333332' x='100.000000' y='363.333313' />";
           svg += "<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='403.000000' cy='416.666656' rx='40.000000' ry='40.000000' />";
           svg += "<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='1615.000000' cy='416.666656' rx='40.000000' ry='40.000000' />";
           svg += "<!-- N° car: 4-->";
	       svg += "<rect x='709.000000' y='243.333313' rx='10' ry='10' width='300.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
	       svg += "<circle cx='769.000000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
	       svg += "<circle cx='769.000000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
	       svg += "<circle cx='949.000000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
	       svg += "<circle cx='949.000000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
	       svg += "<polygon points='760.428894,243.333313 794.714294,183.333160 880.428589,183.333160 880.428589,243.333313 760.428894,243.333313' style='fill:red;stroke:black;stroke-width:5'/>";
	       svg += "<polygon points='880.428589,183.333160 949.000000,243.333313 880.428589,243.333313' style='fill:lightblue;stroke:black;stroke-width:5' />";
	       svg += "<rect x='717.571411' y='213.333313' width='17.142857' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<!--0-->";
	       svg += "<rect x='1012.000000' y='243.333313' rx='10' ry='10' width='300.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
	       svg += "<circle cx='1072.000000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
	       svg += "<circle cx='1072.000000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
	       svg += "<circle cx='1252.000000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
	       svg += "<circle cx='1252.000000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
	       svg += "<polygon points='1063.428833,243.333313 1097.714233,183.333160 1183.428589,183.333160 1183.428589,243.333313 1063.428833,243.333313' style='fill:red;stroke:black;stroke-width:5'/>";
	       svg += "<polygon points='1183.428589,183.333160 1252.000000,243.333313 1183.428589,243.333313' style='fill:lightblue;stroke:black;stroke-width:5' />";
	       svg += "<rect x='1020.571411' y='213.333313' width='17.142857' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<!--1-->";
	       svg += "<rect x='1315.000000' y='243.333313' rx='10' ry='10' width='300.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
	       svg += "<circle cx='1375.000000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
	       svg += "<circle cx='1375.000000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
	       svg += "<circle cx='1555.000000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
	       svg += "<circle cx='1555.000000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
	       svg += "	<polygon points='1366.428833,243.333313 1400.714233,183.333160 1486.428589,183.333160 1486.428589,243.333313 1366.428833,243.333313' style='fill:red;stroke:black;stroke-width:5'/>";
	       svg += "<polygon points='1486.428589,183.333160 1555.000000,243.333313 1486.428589,243.333313' style='fill:lightblue;stroke:black;stroke-width:5' />";
	       svg += "<rect x='1323.571411' y='213.333313' width='17.142857' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<!--2-->";
	       svg += "<rect x='1618.000000' y='243.333313' rx='10' ry='10' width='300.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
	       svg += "<circle cx='1678.000000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
	       svg += "<circle cx='1678.000000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
	       svg += "<circle cx='1858.000000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
	       svg += "<circle cx='1858.000000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
	       svg += "<polygon points='1669.428833,243.333313 1703.714233,183.333160 1789.428589,183.333160 1789.428589,243.333313 1669.428833,243.333313' style='fill:red;stroke:black;stroke-width:5'/>";
	       svg += "<polygon points='1789.428589,183.333160 1858.000000,243.333313 1789.428589,243.333313' style='fill:lightblue;stroke:black;stroke-width:5' />";
	       svg += "<rect x='1626.571411' y='213.333313' width='17.142857' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<!--3-->";
           svg += "</svg>";

    coca_machine* macch = coca_parse_machine(svg);

    REQUIRE(macch->numero == 4);
    REQUIRE(macch->motrice->w == (float)3836.000000);
    REQUIRE(macch->motrice->h == (float)706.666626);
    REQUIRE(macch->motrice->cabina.w == (float)606.000000);
    REQUIRE(macch->motrice->cabina.h == (float)213.333328);
    REQUIRE(macch->motrice->cabina.x == (float)100.000000);
    REQUIRE(macch->motrice->cabina.y == (float)150.000000);
    REQUIRE(macch->motrice->ruotasx.x == (float)403.000000);
    REQUIRE(macch->motrice->ruotasx.y == (float)416.666656);
    REQUIRE(macch->motrice->ruotasx.r == (float)40.000000);
    REQUIRE(macch->motrice->ruotadx.x == (float)1615.000000);
    REQUIRE(macch->motrice->ruotadx.y == (float)416.666656);
    REQUIRE(macch->motrice->ruotadx.r == (float)40.000000);

    delete(macch);
}

// test sulla funzione coca_parse_machine
TEST_CASE("coca_parse_machine deve settare i device car", "[machine]") {

    string svg = "<?xml version='1.0' encoding='UTF-8' standalone='no'?> <svg xmlns='http://www.w3.org/2000/svg' width='3836.000000' height='706.666626'>";
           svg += "<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='606.000000' height='213.333328' x='100.000000' y='150.000000' />";
           svg += "<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='303.000000' height='106.666664' x='100.000000' y='192.666656' />";
           svg += "<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='1818.000000' height='53.333332' x='100.000000' y='363.333313' />";
           svg += "<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='403.000000' cy='416.666656' rx='40.000000' ry='40.000000' />";
           svg += "<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='1615.000000' cy='416.666656' rx='40.000000' ry='40.000000' />";
           svg += "<!-- N° car: 4-->";
	       svg += "<rect x='709.000000' y='243.333313' rx='10' ry='10' width='300.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
	       svg += "<circle cx='769.000000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
	       svg += "<circle cx='769.000000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
	       svg += "<circle cx='949.000000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
	       svg += "<circle cx='949.000000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
	       svg += "<polygon points='760.428894,243.333313 794.714294,183.333160 880.428589,183.333160 880.428589,243.333313 760.428894,243.333313' style='fill:red;stroke:black;stroke-width:5'/>";
	       svg += "<polygon points='880.428589,183.333160 949.000000,243.333313 880.428589,243.333313' style='fill:lightblue;stroke:black;stroke-width:5' />";
	       svg += "<rect x='717.571411' y='213.333313' width='17.142857' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<!--0-->";
	       svg += "<rect x='1012.000000' y='243.333313' rx='10' ry='10' width='300.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
	       svg += "<circle cx='1072.000000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
	       svg += "<circle cx='1072.000000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
	       svg += "<circle cx='1252.000000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
	       svg += "<circle cx='1252.000000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
	       svg += "<polygon points='1063.428833,243.333313 1097.714233,183.333160 1183.428589,183.333160 1183.428589,243.333313 1063.428833,243.333313' style='fill:red;stroke:black;stroke-width:5'/>";
	       svg += "<polygon points='1183.428589,183.333160 1252.000000,243.333313 1183.428589,243.333313' style='fill:lightblue;stroke:black;stroke-width:5' />";
	       svg += "<rect x='1020.571411' y='213.333313' width='17.142857' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<!--1-->";
	       svg += "<rect x='1315.000000' y='243.333313' rx='10' ry='10' width='300.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
	       svg += "<circle cx='1375.000000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
	       svg += "<circle cx='1375.000000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
	       svg += "<circle cx='1555.000000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
	       svg += "<circle cx='1555.000000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
	       svg += "	<polygon points='1366.428833,243.333313 1400.714233,183.333160 1486.428589,183.333160 1486.428589,243.333313 1366.428833,243.333313' style='fill:red;stroke:black;stroke-width:5'/>";
	       svg += "<polygon points='1486.428589,183.333160 1555.000000,243.333313 1486.428589,243.333313' style='fill:lightblue;stroke:black;stroke-width:5' />";
	       svg += "<rect x='1323.571411' y='213.333313' width='17.142857' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<!--2-->";
	       svg += "<rect x='1618.000000' y='243.333313' rx='10' ry='10' width='300.000000' height='80.000000' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
	       svg += "<circle cx='1678.000000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
	       svg += "<circle cx='1678.000000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
	       svg += "<circle cx='1858.000000' cy='323.333313' r='40.000000' stroke='black' stroke-width='3' fill='black'/>";
	       svg += "<circle cx='1858.000000' cy='323.333313' r='25.000000' stroke='black' stroke-width='3' fill='gray'/>";
	       svg += "<polygon points='1669.428833,243.333313 1703.714233,183.333160 1789.428589,183.333160 1789.428589,243.333313 1669.428833,243.333313' style='fill:red;stroke:black;stroke-width:5'/>";
	       svg += "<polygon points='1789.428589,183.333160 1858.000000,243.333313 1789.428589,243.333313' style='fill:lightblue;stroke:black;stroke-width:5' />";
	       svg += "<rect x='1626.571411' y='213.333313' width='17.142857' height='29.999996' style='stroke-width:3;stroke:rgb(0,0,0)' fill='red'/>";
           svg += "<!--3-->";
           svg += "</svg>";

    coca_machine* macch = coca_parse_machine(svg);

    REQUIRE(macch->car[0]->car.width == (float)300.000000);
    REQUIRE(macch->car[0]->car.height == (float)80.000000);
    REQUIRE(macch->car[0]->car.cx == (float)709.000000);


    REQUIRE(macch->car[1]->car.width == (float)300.000000);
    REQUIRE(macch->car[1]->car.height == (float)80.000000);
    REQUIRE(macch->car[1]->car.cx == (float)1012.000000);


    REQUIRE(macch->car[2]->car.width == (float)300.000000);
    REQUIRE(macch->car[2]->car.height == (float)80.000000);
    REQUIRE(macch->car[2]->car.cx == (float)1315.000000);

    REQUIRE(macch->car[3]->car.width == (float)300.000000);
    REQUIRE(macch->car[3]->car.height == (float)80.000000);
    REQUIRE(macch->car[3]->car.cx == (float)1618.000000);

    delete(macch);
}