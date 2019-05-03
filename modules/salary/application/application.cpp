// Copyright 2019 Ryabova Alyona

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/salary_application.h"

int main(int argc, const char** argv) {
    SalaryApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
