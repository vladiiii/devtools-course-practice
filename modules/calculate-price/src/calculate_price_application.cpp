// Copyright 2019 Astafeva Irina

#include <limits>
#include <sstream>
#include <stdexcept>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

#include "include/calculate_price.h"
#include "include/calculate_price_application.h"

std::string CalculatePriceApplication::operator()(int argc, const char ** argv) {
    Arguments args;
    char * e;
    std::ostringstream stream;
    
    if (!ValidateNambersOfArguments(argc, argv)) {
        return message_;
    }
    if (!IsArgumentsInteger(argv)) {
        return message_;
    }
    
    args.book_1 = strtol(argv[1], &e, 10);
    args.book_2 = strtol(argv[2], &e, 10);
    args.book_3 = strtol(argv[3], &e, 10);
    args.book_4 = strtol(argv[4], &e, 10);
    args.book_5 = strtol(argv[5], &e, 10);
    
    try {
        CalculatePrice price(args.book_1, args.book_2, args.book_3,
                             args.book_4, args.book_5);
        
        double sum = price.TotalSum();
        stream << "Total Sum = " << sum;
    }
    catch (std::string & s) {
        Help(argv[0]);
        message_ = "ERROR: " + s + ".\n\n" + message_;
        return message_;
    }
    
    message_ = stream.str();
    
    return message_;
}

void CalculatePriceApplication::Help(const char *appname) {
    message_ = "This is application for class calculate price.\n\n"
               "Usage:\n" "> " + std::string(appname) +
               " actions that described below.\n"
               "Actions:\n" +
               std::string(appname) + " <book_1> <book_2> "
               "<book_3> <book_4> <book_5>\n\n"
               "Where all arguments are not negative integer numbers.\n";
}

bool CalculatePriceApplication::ValidateNambersOfArguments(int argc, const char ** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    }
    else if (argc != 6) {
        Help(argv[0]);
        message_ = "ERROR: Should be 5 arguments.\n\n" + message_;
        return false;
    }
    return true;
}

bool CalculatePriceApplication::IsArgumentsInteger(const char ** argv) {
    for (int i = 1; i < 6; i++) {
        char * e;
        int64_t value = strtol(argv[i], &e, 10);
        if (e[0]) {
            Help(argv[0]);
            message_ = "ERROR: Wrong number format.\n\n" + message_;
            return false;
        }
        if (value <= static_cast<int64_t>(std::numeric_limits<int>::min()) ||
            value >= static_cast<int64_t>(std::numeric_limits<int>::max())) {
            Help(argv[0]);
            message_ = "ERROR: Number is out of bounds.\n\n" + message_;
            return false;
        }
    }
    return true;
}
