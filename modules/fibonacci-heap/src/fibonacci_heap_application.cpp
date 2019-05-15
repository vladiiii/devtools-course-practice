// Copyright 2019 Karasev Anton

#include "include/fibonacci_heap_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>

FibonacciHeapApplication::FibonacciHeapApplication() : message_("") {}

void FibonacciHeapApplication::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a fibonacci heap application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + "<operation> <find_elem> <val1> ...\n\n" +

          "Where all arguments are int numbers, " +
          "and <operation> is one of 'min', 'find', 'merge', and find_elem - number for operation find.\n";
}

bool FibonacciHeapApplication::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc < 4) {
        Help(argv[0], "ERROR: There must be at least 4 arguments.\n\n");
        return false;
    }
    return true;
}

char ParseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "min") == 0) {
        op = 'm';
    } else if (strcmp(arg, "find") == 0) {
        op = 'f';
    } else if (strcmp(arg, "merge") == 0) {
        op = 'M';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string FibonacciHeapApplication::operator()(int argc, const char** argv) {
    Arguments args;
    int find_el;

    if (!validateNumberOfArguments(argc, argv)) {
        return this->message_;
    }
    try {
        args.operation_ = ParseOperation(argv[1]);
        find_elem = argv[2];
        for (int i = 3; i < argc; i++)
            args.weights_.push_back(atoi(argv[i]));
    }
    catch(std::string& str) {
        return str;
    }

    FibonacciHeap h1, h2;
    Node *tmp = nullptr;
    
    std::ostringstream stream;
    
    switch (args.operation_) {
     case 'm':
        for (int i = 0; i < args.weights_.size(); ++i) {
             h1.Insert(args.weights_[i]);
        }
        stream << "Min = " << h.GetMinimum();
        break;
     case 'f':
         for (int i = 0; i < args.weights_.size(); ++i) {
             h1.Insert(args.weights_[i]);
        }
        tmp = h.Find(find_elem);
        if (tmp != nullptr) {
        stream << find_elem << "is found in heap";
        } else {
        stream << find_elem << "not found in heap";
        }
        break;
     case 'M':
        for (int i = 0; i < args.weights_.size(); ++i) {
             h2.Insert(args.weights_[i]);
        }
        h1.Merge(h2);
        if (!h1.IsEmpty()) {
        stream << "Merge successfully";
        }
        break;
    }

    this->message_ = stream.str();

    return this->message_;
}