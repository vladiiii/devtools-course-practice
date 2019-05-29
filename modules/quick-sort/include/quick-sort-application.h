// Copyright 2019 by Zolotareva Olesya

#ifndef MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_APPLICATION_H_
#define MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_APPLICATION_H_

#include <string>

#include "include/quick-sort.h"

class QuickSortApplication {
 private:
    std::string message_;
    int size;
    int *array;
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
 public:
    QuickSortApplication();
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_APPLICATION_H_
