// Copyright 2019 Malkin Danil

#ifndef MODULES_POLYNOMS_INCLUDE_POLYNOMS_CALCULATOR_H_
#define MODULES_POLYNOMS_INCLUDE_POLYNOMS_CALCULATOR_H_

#include "monom.h"

#include <string>
#include <vector>

class PolynomsCalculator {
 public:
     PolynomsCalculator() {
     };
    std::string operator()(int argc, const char** argv);
    std::string calculate(std::string& arg1, std::string& arg2, std::string& op);
 private:
    std::string Info();
    bool checkCorrectPolynoms(std::string& str);
    bool checkOperation(std::string& str);
    std::string preprocessing(std::string& str);
    Monom createMonom(std::string& str);
    std::vector<Monom> parsePolynom(const std::string& str);
    typedef struct {
        std::string operation;
        std::string arg1;
        std::string arg2;
    } Arguments;
};

#endif  // MODULES_POLYNOMS_INCLUDE_POLYNOMS_CALCULATOR_H_
