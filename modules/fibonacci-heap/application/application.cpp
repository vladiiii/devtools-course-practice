// Copyright 2019 Karasev Anton

#include <iostream>

#include <include/fibonacci_heap_application.h"

int main(int argc, char const *argv[]) {
    FibonacciHeapApplication application;
    std::cout << application(argc, argv);
    return 0;
}