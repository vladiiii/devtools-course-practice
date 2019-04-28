// Copyright 2019 Timakin Nikita

#include "include/sorter.h"

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "include/heap.h"

std::string Sorter::help_message(const char* appname) {
    return std::string("") + "This is an application which allows you " +
           "to sort numbers in reverse order\n" +
           "Please provide arguments in the following format:\n" +
           "  $ " + appname + " num_1 num_2 ... num_n\n";
}

bool Sorter::check_arguments(int argc, const char** argv) {
    if (argc == 1 || std::string(argv[1]) == "help") {
        std::cout << help_message(argv[0]);
        return false;
    }

    try {
        for (int i = 1; i < argc; ++i)
            args_.emplace_back(std::stof(argv[i]));
    }
    catch (std::exception&) {
        std::cout << "Input error\n\n" + help_message(argv[0]);
        return false;
    }

    return true;
}

std::string Sorter::operator()(int argc, const char** argv) {
    if (!check_arguments(argc, argv))
        return "";

    Heap<float> heap;
    std::ostringstream result;

    for (float value : heap.HeapSort(args_))
        result << value << " ";
    result << "\n";

    return result.str();
}
