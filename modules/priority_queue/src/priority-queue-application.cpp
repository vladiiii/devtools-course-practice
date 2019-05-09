// Copyright 2019 Bykovskaya Alina

#include "include/priority_queue.h"
#include "include/priority-queue-application.h"

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>

void PriorityApp::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a priority queue application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        " $ " + appname + " <actions> " +
        "Where <actions> are operations (push/pop/top):\n"
        "push <priority> <value> - insert in queue\n"
        "pop - extract from queue\n"
        "top - show top element\n";
}

std::string PriorityApp::operator()(int argc, const char **argv) {
    if (!ValidateNumberOfArguments(argc, argv)) {
        Help(*argv);
        throw std::string("Wrong number of arguments.");
    }
    for (int i = 1; i < argc; ) {
            int offset = ParseOperation(argv + i);
            i += offset;
    }
    return "success";
}

bool PriorityApp::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    }
    return true;
}

int PriorityApp::ParseOperation(const char** argv) {
    if (std::strcmp(*argv, "push") == 0) {
        q.Push(std::atoi(*(argv + 1)), std::atoi(*(argv + 2)));
        return 3;
    }
    if (std::strcmp(*argv, "pop")) {
        q.Pop();
        return 1;
    }
    if (std::strcmp(*argv, "top")) {
        std::cout << std::string("top element: ") << q.Top() << std::endl;
        return 1;
    }
    throw std::string("Unknown operator ") + std::string(*argv);
}
