// Copyright 2019 Logvinenko Alexandra

#include "include/conways_game_of_life.h"
#include <string>

Conways_life::Conways_life(const int w, const int h) {
    if (w <= 0 || h <= 0) {
        throw std::string("Wrong input.");
    } else {
        sizeh = h;
        sizew = w;
        field = new char[w*h];
        check = new bool[w*h];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                field[i*sizew + j] = '.';
                check[i*sizew + j] = false;
           }
        }
    }
}
void Conways_life::putStart(const int wi, const int hi) {
    if (wi < 0 || hi < 0 || wi >= sizew || hi >= sizeh) {
        throw std::string("Wrong point.");
    } else {
        field[hi*sizew+wi] = '+';
    }
}
int Conways_life::getH() { return sizeh; }
int Conways_life::getW() { return sizew; }
char Conways_life::getPoint(const int wi, const int hi) { return field[hi*sizew + wi]; }
void Conways_life::redraw() {
    for (int i = 0; i < sizeh; i++) {
        for (int j = 0; j < sizew; j++) {
            if (check[i*sizew + j]) field[i*sizew + j] = '+';
            else 
                field[i*sizew + j] = '.';

            check[i*sizew + j] = false;
        }
    }
}
void Conways_life::checkNextStep() {
    for (int i = 0; i < sizew; i++) {
        for (int j = 0; j < sizeh; j++) {
            aliveNextStep(i, j);
        }
    }
}
bool Conways_life::aliveNextStep(const int wi, const int hi) {
    int alive_neigh;
    bool res = true;
    alive_neigh = countNeighbors(wi, hi);

    if (field[hi*sizew + wi] == '.') {
        if (alive_neigh == 3)
            check[hi*sizew + wi] = true;
    }
    if (field[hi*sizew + wi] == '+') {
        if (alive_neigh == 2 || alive_neigh == 3)
            check[hi*sizew + wi] = true;
        else {
            check[hi*sizew + wi] = false;
            res = false;
        }
    }
    return res;
}
int Conways_life::countNeighbors(const int wi, const int hi) {
    int count = 0;
    if ((wi != 0) && (wi != sizew - 1) && (hi != 0) && (hi != sizeh - 1)) {
        if (field[hi*sizew + wi + 1] == '+') count++;
        if (field[hi*sizew + wi - 1] == '+') count++;
        if (field[(hi + 1)*sizew + wi - 1] == '+') count++;
        if (field[(hi + 1)*sizew + wi + 1] == '+') count++;
        if (field[(hi + 1)*sizew + wi] == '+') count++;
        if (field[(hi - 1)*sizew + wi - 1] == '+') count++;
        if (field[(hi - 1)*sizew + wi + 1] == '+') count++;
        if (field[(hi - 1)*sizew + wi] == '+') count++;
    } else {
        if (wi == 0 && hi == 0) {
            if (field[1] == '+') count++;
            if (field[sizew-1] == '+') count++;
            if (field[sizew] == '+') count++;
            if (field[sizew + 1] == '+') count++;
            if (field[sizew + sizew - 1] == '+') count++;
            if (field[(sizeh - 1)*sizew] == '+') count++;
            if (field[(sizeh - 1)*sizew + 1] == '+') count++;
            if (field[(sizeh - 1)*sizew + sizew - 1] == '+') count++;
        } else if (wi == 0 && hi == sizeh - 1) {
            if (field[(hi - 1)*sizew] == '+') count++;
            if (field[(hi - 1)*sizew + 1] == '+') count++;
            if (field[(hi - 1)*sizew + sizew - 1] == '+') count++;
            if (field[hi*sizew + 1] == '+') count++;
            if (field[hi*sizew + sizew - 1] == '+') count++;
            if (field[sizew - 1] == '+') count++;
            if (field[0] == '+') count++;
            if (field[1] == '+') count++;
        } else if (wi == sizew - 1 && hi == 0) {
            if (field[(sizeh - 1)*sizew + wi - 1] == '+') count++;
            if (field[(sizeh - 1)*sizew + wi] == '+') count++;
            if (field[(sizeh - 1)*sizew] == '+') count++;
            if (field[wi - 1] == '+') count++;
            if (field[0] == '+') count++;
            if (field[sizew + wi - 1] == '+') count++;
            if (field[sizew + wi] == '+') count++;
            if (field[sizew] == '+') count++;
        } else if (wi == sizew - 1 && hi == sizeh - 1) {
            if (field[(hi - 1)*sizew + wi] == '+') count++;
            if (field[(hi - 1)*sizew + wi - 1] == '+') count++;
            if (field[(hi - 1)*sizew] == '+') count++;
            if (field[hi*sizew + wi - 1] == '+') count++;
            if (field[hi*sizew] == '+') count++;
            if (field[wi - 1] == '+') count++;
            if (field[wi] == '+') count++;
            if (field[0] == '+') count++;
        } else if (wi == 0) {
            if (field[(hi - 1)*sizew] == '+') count++;
            if (field[(hi + 1)*sizew] == '+') count++;
            if (field[(hi - 1)*sizew + 1] == '+') count++;
            if (field[hi*sizew + 1] == '+') count++;
            if (field[(hi + 1)*sizew + 1] == '+') count++;
            if (field[(hi - 1)*sizew + sizew - 1] == '+') count++;
            if (field[hi*sizew + sizew - 1] == '+') count++;
            if (field[(hi + 1)*sizew + sizew -1] == '+') count++;
        } else if (hi == 0) {
            if (field[wi - 1] == '+') count++;
            if (field[wi + 1] == '+') count++;
            if (field[sizew + wi - 1] == '+') count++;
            if (field[sizew + wi] == '+') count++;
            if (field[sizew + wi + 1] == '+') count++;
            if (field[(sizeh - 1)*sizew + wi - 1] == '+') count++;
            if (field[(sizeh - 1)*sizew + wi] == '+') count++;
            if (field[(sizeh - 1)*sizew + wi + 1] == '+') count++;
        } else if (wi == sizew - 1) {
            if (field[(hi - 1)*sizew + wi - 1] == '+') count++;
            if (field[hi*sizew + wi - 1] == '+') count++;
            if (field[(hi + 1)*sizew + wi] == '+') count++;
            if (field[(hi - 1)*sizew] == '+') count++;
            if (field[hi*sizew] == '+') count++;
            if (field[(hi - 1)*sizew] == '+') count++;
            if (field[(hi - 1)*sizew + wi] == '+') count++;
            if (field[(hi + 1)*sizew + wi] == '+') count++;
        } else if (hi == sizeh - 1) {
            if (field[(hi - 1)*sizew + wi - 1] == '+') count++;
            if (field[(hi - 1)*sizew + wi] == '+') count++;
            if (field[(hi - 1)*sizew + wi + 1] == '+') count++;
            if (field[wi - 1] == '+') count++;
            if (field[wi] == '+') count++;
            if (field[wi + 1] == '+') count++;
            if (field[hi*sizew + wi - 1] == '+') count++;
            if (field[hi*sizew + wi + 1] == '+') count++;
        }
    }

    return count;
}

bool Conways_life::isSystemAlive() {
    bool res = false;
    for (int i = 0; i < sizeh; i++) {
        for (int j = 0; j < sizew; j++) {
            if (check[i*sizew + j])
                return true;
        }
    }
    return res;
}

void Conways_life::stepNextField() {
    checkNextStep();
    redraw();
    checkNextStep();
}
void Conways_life::Start() {
    checkNextStep();
    while (isSystemAlive()) {
        stepNextField();
    }
}
