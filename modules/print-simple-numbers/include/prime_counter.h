// Copyright 2019 Gaydaychuk Yury

#ifndef MODULES_PRIME_PRINTER_INCLUDE_PRIME_PRINTER_H_
#define MODULES_PRIME_PRINTER_INCLUDE_PRIME_PRINTER_H_

#include <string>

class PrimeCounter {
 public:
    PrimeCounter();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int left_boundary;
        int right_boundary;
    } Arguments;
};

#endif  // MODULES_PRIME_PRINTER_INCLUDE_PRIME_PRINTER_H_
