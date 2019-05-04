// Copyright 2019 Kutovoi Vadim

#include "include/bond_calculator.h"
#include "include/bond_calculator_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

BondCalculatorApp::BondCalculatorApp() : message_("") {}

void BondCalculatorApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a bond calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <price> <nominal_price> " +
          "<months> <year> <percentage> <current_year> <current_month>\n\n";
}

bool BondCalculatorApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 7) {
        help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

double parseInt(const char* arg) {
    char* end;
    int value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string BondCalculatorApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.price      = parseDouble(argv[1]);
        args.nominal_price = parseDouble(argv[2]);
        args.year = parseInt(argv[3]);
        args.percentage    = parseDouble(argv[4]);
        args.current_year = parseInt(argv[5]);
        args.current_month = parseInt(argv[6]);
    }
    catch(std::string& str) {
        return str;
    }

    BondCalculator bcalc;
    bond bond_;
    std::vector<int> mnths = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    bond_.price = args.price;
    bond_.nominal_price = args.nominal_price;
    bond_.year = args.year;
    bond_.percentage = args.percentage;
    bond_.months = mnths;


    std::ostringstream stream;
    std::vector<payment> payments = bcalc.CalculatePayments(bond_, args.current_month, args.current_year);
    payment totalIncome = bcalc.CalculateTotalIncome(bond_, args.current_month, args.current_year);

    stream << "Payments : " << std::endl;
    for (auto i : payments) {
        stream << "\tYear : " << i.year << \
        " Month : " << i.month << \
        " Value : " << i.value << std::endl;
    }

    stream << "Relative income : " << std::endl << \
    "\t" << bcalc.CalculateRelativeIncome(bond_, args.current_month, args.current_year) << std::endl;

    stream << "Total Income : " << std::endl << \
    "\tYear : " << totalIncome.year << std::endl << \
    "\tMonth : " << totalIncome.month << std::endl << \
    "\tValue : " << totalIncome.value << std::endl;

    stream << "Yearly internal income :" << std::endl << \
    "\t" << bcalc.CalculateYearlyInternalIncome(bond_, args.current_year) << std::endl;
    message_ = stream.str();

    return message_;
}
