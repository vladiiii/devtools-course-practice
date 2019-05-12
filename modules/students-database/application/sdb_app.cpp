// Copyright 2019 Kudrin Matvey

#include <stdlib.h>
#include <iostream>
#include <string>

#include "include/sdb_app.h"

int main(int argc, const char** argv) {
    SdbApp app;
    try {
        std::cout << app(argc, argv) << std::endl;
    } catch (std::string& str) {
        std::cout << "Error: " << str << std::endl
        << app.Help(argv[0]) << std::endl;
    }


    return 0;
}
