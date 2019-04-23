// Copyright 2019 Obolenskiy Arseniy
#include <cstring>
#include <climits>
#include <iostream>
#include <stdexcept>
#include <string>
#include "include/application.h"

std::string TreeApplication::Help(const char *appname) {
    return "Usage:\n"
           "> " + std::string(appname) + " actions that described below\n"
           "Actions:\n"
           "add <value> - add value to the tree\n"
           "del <value> - delete value from the tree\n"
           "search <value> - find the value in the tree\n"
           "clear - delete the whole tree\n";
}

std::string TreeApplication::operator()(int argc, const char** argv) {
    for (int i = 0; i < argc; ) {
        int offset = ParseOperation(argv + i);
        if (offset == 0)
            break;
        i += offset;
    }
    return out_.str();
}

long TreeApplication::ParseNumber(const char *s) {
    long result = strtol(s, nullptr, 10);
    if (result <= static_cast<long>(INT_MIN) ||
        result >= static_cast<long>(INT_MAX))
        out_ << "Number is out of bounds" << "\n";
    return static_cast<long>(INT_MAX);
}

int TreeApplication::ParseOperation(const char **argv) {
    if (strcmp(*argv, "add") == 0) {
        long value = ParseNumber(*(argv + 1));
        t_.Add(value);
        out_ << "Number " << value << " is added to the tree\n";
        return 2;
    }
    if (strcmp(*argv, "del") == 0) {
        long value = ParseNumber(*(argv + 1));
        t_.Del(value);
        out_ << "Number " << value << " is deleted from the tree\n";
        return 2;
    }
    if (strcmp(*argv, "search") == 0) {
        long value = ParseNumber(*(argv + 1));
        int verdict = t_.Search(value);
        if (verdict) {
            out_ << "Number " << value << " is found in the tree\n";
        } else {
            out_ << "Number " << value << " is not found in the tree\n";
        }
        return 2;
    }
    if (strcmp(*argv, "clear") == 0) {
        t_.Clear();
        out_ << "Tree is now clear\n";
        return 1;
    }
    out_ << "Unknown operation: " << *argv << "\n";
    return 0;
}