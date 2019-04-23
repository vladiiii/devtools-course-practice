// Copyright 2019 Obolenskiy Arseniy
#include <iostream>
#include "include/application.h"

int main(int argc, char const *argv[]) {
    TreeApplication application;
    std::cout << application(argc, argv);
    return 0;
}
