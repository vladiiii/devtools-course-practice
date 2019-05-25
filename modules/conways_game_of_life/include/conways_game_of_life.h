// Copyright 2019 Logvinenko Alexandra
#pragma once
#ifndef MODULES_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_H_
#define MODULES_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_H_

class Conways_life {
 private:
    int sizeh, sizew;
    char* field;
    bool* check;

    void checkNextStep(); 
    void redraw();

 public:
    Conways_life(const int w, const int h);
    int getW();
    int getH();
    char getPoint(const int wi, const int hi);
    void putStart(const int wi, const int hi);

    int countNeighbors(const int wi, const int hi);
    void stepNextField();
    bool isSystemAlive(); 
    bool aliveNextStep(const int wi, const int hi);

    void Start();
};

#endif  // MODULES_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_H_
