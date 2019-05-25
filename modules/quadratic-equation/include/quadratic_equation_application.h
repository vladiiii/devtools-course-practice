// Copyright 2019 Gribanov Mihail

#ifndef MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_APPLICATION_H_
#define MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_APPLICATION_H_

#include <string>
#include <include/quadratic_equation.h>

class QuadraticEquationApplication {

public:
     QuadraticEquationApplication() = default;
     std::string operator()(int argc, const char** argv);

 private:
     std::string message_;
     int coef[3];
     void Help(const char* appname, const char* message = "");
     bool CheckArguments(int argc, const char** argv);
};
#endif  // MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_APPLICATION_H_
