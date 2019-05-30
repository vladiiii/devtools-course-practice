// Copyright 2019 Kondrina Tatyana

#include <string>
#include <cstring>
#include <vector>
#include "include/BatcherSort_app.h"

void BatcherSortApp::Info(const char* appname, const char* message) {
    message_ = std::string(message) +
        "This is a Batcher Sort application. \n\n" +
        "Please, enter array elements in the following format: \n\n"
        " $ " + appname + " { v[1], v[2], ..., v[i] }, \n\n" +
        "Where all arguments are integer numbers. ";
}

bool BatcherSortApp::CheckArguments(int argc, const char** argv) {
    if (argc == 1) {
        Info(argv[0]);
        return false;
    }
    if (((argc - 1) & ((argc - 1) - 1)) != 0) {
        Info(argv[0], "The number of elements must be a degree of 2 "
            "in the format v[i]. \n\n");
        return false;
    }
    for (int i = 1; i < argc; i++) {
        if ((atoi(argv[i]) == 0) && (strcmp(argv[i], "0") != 0)) {
            Info(argv[0], "ERROR : All arguments must be integers. \n\n");
            return false;
        }
    }
    return true;
}

std::string BatcherSortApp::operator()(int argc, const char** argv) {
    std::vector<int> argument;

    if (!CheckArguments(argc, argv)) {
        return message_;
    }
    for (int i = 1; i < argc; i++) {
        argument.push_back(std::atoi(argv[i]));
    }

    BatcherSort v(argument);
    v.BatcherMergeSort(0, v.GetSize() - 1);
    std::vector<int> tmp = v.GetVec();
    message_ = "Sort = ";
    for (int i = 0; i < argc - 1; i++) {
        message_ += std::to_string(tmp[i]);
        message_ += " ";
    }
    return message_;
}
