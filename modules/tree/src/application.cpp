// Copyright 2019 Obolenskiy Arseniy
#include <cstring>
#include <limits>
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
    try {
        for (int i = 1; i < argc; ) {
            int offset = ParseOperation(argv + i);
            if (offset == 0)
                break;
            i += offset;
        }
        return out_.str();
    } catch (std::runtime_error &re) {
        return re.what();
    }
}

int64_t TreeApplication::ParseNumber(const char *s) {
    int64_t result = strtol(s, nullptr, 10);
    if (result <= static_cast<int64_t>(std::numeric_limits<int>::min()) ||
        result >= static_cast<int64_t>(std::numeric_limits<int>::max())) {
        throw std::runtime_error("Number is out of bounds");
    }
    return static_cast<int64_t>(result);
}

int TreeApplication::ParseOperation(const char **argv) {
    if (strcmp(*argv, "add") == 0) {
        int64_t value = ParseNumber(*(argv + 1));
        t_.Add(value);
        return 2;
    }
    if (strcmp(*argv, "del") == 0) {
        int64_t value = ParseNumber(*(argv + 1));
        t_.Del(value);
        return 2;
    }
    if (strcmp(*argv, "search") == 0) {
        int64_t value = ParseNumber(*(argv + 1));
        int verdict = t_.Search(value);
        out_ << verdict << " ";
        return 2;
    }
    if (strcmp(*argv, "clear") == 0) {
        t_.Clear();
        out_ << "Tree is now clear\n";
        return 1;
    }
    throw std::runtime_error(std::string("Unknown operation: ") +
                             std::string(*argv));
    return 0;
}
