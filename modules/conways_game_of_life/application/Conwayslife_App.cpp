// Copyright 2019 Logvinenko Alexandra

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/conways_game_of_life_application.h"

int main(int argc, const char** argv) {
    Conwayslife_App app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
