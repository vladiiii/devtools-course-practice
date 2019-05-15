// Copyright 2019 Malkin Danil

#include "include\polynoms_calculator.h"

#include <iostream>

int main(int argc, const char** argv){
    PolynomsCalculator cal;
    std::cout << cal(argc,&argv[1]);
    return 0;
}