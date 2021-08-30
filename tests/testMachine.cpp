#include "catch2/catch2.hpp"
#include "machine.h"

// test sulla funzione coca_init_machine
TEST_CASE("coca_init_machine dovrebbe ritornare un puntatore a un machine != NULL", "[machine]") {
    
    int n = 5;
    coca_device* car = coca_init_device();

    coca_machine* machine_ = coca_init_machine(n);

    REQUIRE(machine_ != NULL);
    REQUIRE(machine_->numero == 5);

    delete(machine_);
}