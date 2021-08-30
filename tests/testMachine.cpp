#include "catch2/catch2.hpp"
#include "machine.h"

// test sulla funzione coca_init_machine
TEST_CASE("coca_init_machine dovrebbe ritornare un puntatore a un machine != NULL", "[machine]") {

    coca_machine* machine_ = coca_init_machine();

    REQUIRE(machine_ != NULL);

    delete(machine_);
}