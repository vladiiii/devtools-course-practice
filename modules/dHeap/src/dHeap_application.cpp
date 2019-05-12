// Copyright 2019 Tolstikov Maksim

#include "include/dHeap.h"
#include "include/dHeap_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>

DHeapApp::DHeapApp() : message_("") {}

void DHeapApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is dHeap application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <d> <size> <weight_vector> " +
          "<operation>\n\n" +

          "Where all arguments are int-precision numbers, " +
          "and <operation> is one of 'sort', 'max', 'min'.\n";
}

int parseInt(const char* arg) {
    char* end;
    int value = static_cast<int>(strtod(arg, &end));

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}


bool DHeapApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    return true;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "sort") == 0) {
        op = 's';
    } else if (strcmp(arg, "min") == 0) {
        op = 'm';
    } else if (strcmp(arg, "max") == 0) {
        op = 'M';
    }  else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string DHeapApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.d_ = parseInt(argv[1]);
        for (int i = 3; i < parseInt(argv[2]) + 3; ++i) {
            args.weight_.push_back(parseInt(argv[i]));
        }
        args.operation = parseOperation(argv[parseInt(argv[2]) + 3]);
    }
    catch(std::string& str) {
        return str;
    }

    DHeap dh(args.d_, args.weight_);
    int k = dh.get_size();
    int max = 0;
    std::vector<int> v;
    std::ostringstream stream;
    switch (args.operation) {
     case 's':
        for (int i = 0; i < k; ++i) {
             v.push_back(dh.Delete_min());
        }
        stream << "Weight = ";
        for (int i = 0; i < dh.get_size(); ++i) {
            stream << v[i] << " ";
        }
        break;
     case 'M':
         for (int i = 0; i < k; ++i) {
             max = dh.Delete_min();
         }
        stream << "Max = " << max;
        break;
     case 'm':
        stream << "Min = " << dh.Delete_min();
        break;
    }

    message_ = stream.str();

    return message_;
}
