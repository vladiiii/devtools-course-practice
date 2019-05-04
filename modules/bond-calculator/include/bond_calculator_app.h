// Copyright 2019 Kutovoi Vadim

#ifndef MODULES_BOND_CALCULATOR_INCLUDE_BOND_CALCULATOR_APP_H_
#define MODULES_BOND_CALCULATOR_INCLUDE_BOND_CALCULATOR_APP_H_

#include <string>
#include <vector>

class BondCalculatorApp {
 public:
    BondCalculatorApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double price;
        double nominal_price;
        std::vector<int> months;
        int year;
        double percentage;
        int current_year;
        int current_month;
    } Arguments;
};

#endif  // MODULES_BOND_CALCULATOR_INCLUDE_BOND_CALCULATOR_APP_H_
