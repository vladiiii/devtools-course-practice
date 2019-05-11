// Copyright 2017 Korniakov Kirill

#ifndef MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_CALCULATOR_H_
#define MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_CALCULATOR_H_

#include <string>

class BigIntCalculator {
 public:
    BigIntCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::string operand_1;
        std::string operand_2;
        char operation;
    } Arguments;
};

#endif  // MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_CALCULATOR_H_
