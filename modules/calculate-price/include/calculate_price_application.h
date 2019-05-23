// Copyright 2019 Astafeva Irina

#ifndef MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_APPLICATION_H_
#define MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_APPLICATION_H_

#include <string>

class CalculatePriceApplication {
    public:
        CalculatePriceApplication() = default;
        std::string operator()(int argc, const char ** argv);
    private:
        void Help(const char *appname);
        bool ValidateNambersOfArguments(int argc, const char ** argv);
        bool IsArgumentsInteger(const char ** argv);
        std::string message_;
        typedef struct {
            int book_1;
            int book_2;
            int book_3;
            int book_4;
            int book_5;
        } Arguments;
};

#endif  // MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_APPLICATION_H_
