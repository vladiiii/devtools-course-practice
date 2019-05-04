// Copyright 2019 Kutovoi Vadim

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/bond_calculator_app.h"

int main(int argc, const char** argv) {
    BondCalculatorApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
