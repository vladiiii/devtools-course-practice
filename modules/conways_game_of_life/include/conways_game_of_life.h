// Copyright 2019 Logvinenko Alexandra
#pragma once
#ifndef MODULES_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_H_
#define MODULES_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_H_

class Conways_life {
 private:
    int sizeh, sizew;
    char* field;
    bool* check;

    int countNeighbors(const int wi, const int hi);
    void checkNextStep();
    void aliveNextStep(const int wi, const int hi);
    void redraw();
    bool isSystemAlive();

 public:
    Conways_life(const int w, const int h);
    int getW();
    int getH();
    void putStart(const int wi, const int hi);

    void Start();
};

#endif  // MODULES_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_H_
