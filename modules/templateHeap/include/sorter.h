// Copyright 2019 Timakin Nikita

#ifndef MODULES_TEMPLATEHEAP_INCLUDE_SORTER_H_
#define MODULES_TEMPLATEHEAP_INCLUDE_SORTER_H_

#include <string>
#include <vector>

class Sorter {
    std::vector<float> args_;

    std::string help_message(const char* appname);
    bool check_arguments(int argc, const char** argv);

 public:
    Sorter() = default;
    Sorter(const Sorter&) = default;

    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_TEMPLATEHEAP_INCLUDE_SORTER_H_
