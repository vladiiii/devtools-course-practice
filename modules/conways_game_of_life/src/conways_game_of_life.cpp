// Copyright 2019 Logvinenko Alexandra
#include "include/conways_game_of_life.h"
#include <string>

Conways_life::Conways_life(const int w, const int h) {
	if (w <= 0 || h <= 0) {
		throw std::string("Wrong input.");
	}
	else {
		sizeh = h;
		sizew = w;
		*field = new char[w];
		*check = new bool[w];
		for (int i = 0; i < w; i++) {
			field[i] = new char[h];
			check[i] = new bool[h];
			for (int j = 0; j < h; j++) {
				field[i][j] = '.';
				check[i][j] = false;
			}
		}
	}
}
void Conways_life::putStart(const int wi, const int hi) {
	if (wi < 0 || hi < 0 || wi >= sizew || hi >= sizeh) {
		throw std::string("Wrong point.");
	}
	else {
		field[wi][hi] = '+';
	}
}
int Conways_life::getH() { return sizeh; }
int Conways_life::getW() { return sizew; }
void Conways_life::redraw() {
	for (int i = 0; i < sizew; i++) {
		for (int j = 0; j > sizeh; j++) {
			if (check[i][j]) field[i][j] = '+';
			else field[i][j] = '.';

			check[i][j] = false;
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
void Conways_life::aliveNextStep(const int wi, const int hi) {
	int alive_neigh;
	alive_neigh = countNeighbors(wi, hi);

	if (field[wi][hi] == '.') {
		if (alive_neigh == 3)
			check[wi][hi] = true;
	}
	if (field[wi][hi] == '+') {
		if (alive_neigh == 2 || alive_neigh == 3)
			check[wi][hi] = true;
		else
			check[wi][hi] = false;

	}
}
int Conways_life::countNeighbors(const int wi, const int hi) {
	int count = 0;
	if ((wi != 0) && (wi != sizew - 1) && (hi != 0) && (hi != sizeh - 1)) {
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (field[wi + i][hi + j] == '+')
					count++;
			}
		}
		if (field[wi][hi] == '+') count--;
	}
	else {
		if (wi == 0 && hi == 0) {
			if (field[0][1] == '+') count++;
			if (field[0][sizeh - 1] == '+') count++;
			if (field[1][0] == '+') count++;
			if (field[1][1] == '+') count++;
			if (field[1][sizeh - 1] == '+') count++;
			if (field[sizew - 1][0] == '+') count++;
			if (field[sizew - 1][1] == '+') count++;
			if (field[sizew - 1][sizeh - 1] == '+') count++;
		}
		else if (wi == 0 && hi == sizeh - 1) {
			if (field[0][hi - 1] == '+') count++;
			if (field[0][0] == '+') count++;
			if (field[1][hi] == '+') count++;
			if (field[1][hi - 1] == '+') count++;
			if (field[1][0] == '+') count++;
			if (field[sizew - 1][hi] == '+') count++;
			if (field[sizew - 1][hi - 1] == '+') count++;
			if (field[sizew - 1][0] == '+') count++;
		}
		else if (wi == sizew - 1 && hi == 0) {
			if (field[wi - 1][0] == '+') count++;
			if (field[wi - 1][1] == '+') count++;
			if (field[wi - 1][sizeh - 1] == '+') count++;
			if (field[0][0] == '+') count++;
			if (field[0][1] == '+') count++;
			if (field[0][sizeh - 1] == '+') count++;
			if (field[wi][1] == '+') count++;
			if (field[wi][sizeh - 1] == '+') count++;
		}
		else if (wi == sizew - 1 && hi == sizeh - 1) {
			if (field[wi - 1][hi] == '+') count++;
			if (field[wi - 1][hi - 1] == '+') count++;
			if (field[wi - 1][0] == '+') count++;
			if (field[0][hi] == '+') count++;
			if (field[0][hi - 1] == '+') count++;
			if (field[0][0] == '+') count++;
			if (field[wi][0] == '+') count++;
			if (field[wi][hi - 1] == '+') count++;
		}
		else if (wi == 0) {
			if (field[1][hi - 1] == '+') count++;
			if (field[1][hi] == '+') count++;
			if (field[1][hi + 1] == '+') count++;
			if (field[sizew - 1][hi - 1] == '+') count++;
			if (field[sizew - 1][hi] == '+') count++;
			if (field[sizew - 1][hi + 1] == '+') count++;
			if (field[0][hi + 1] == '+') count++;
			if (field[0][hi - 1] == '+') count++;

		}
		else if (hi == 0) {
			if (field[wi - 1][1] == '+') count++;
			if (field[wi][1] == '+') count++;
			if (field[wi + 1][1] == '+') count++;
			if (field[wi - 1][sizeh - 1] == '+') count++;
			if (field[wi][sizeh - 1] == '+') count++;
			if (field[wi + 1][sizeh - 1] == '+') count++;
			if (field[wi + 1][0] == '+') count++;
			if (field[wi - 1][0] == '+') count++;
		}
		else if (wi == sizew - 1) {
			if (field[wi - 1][hi - 1] == '+') count++;
			if (field[wi - 1][hi] == '+') count++;
			if (field[wi - 1][hi + 1] == '+') count++;
			if (field[0][hi - 1] == '+') count++;
			if (field[0][hi] == '+') count++;
			if (field[0][hi + 1] == '+') count++;
			if (field[wi][hi + 1] == '+') count++;
			if (field[wi][hi - 1] == '+') count++;
		}
		else if (hi == sizeh - 1) {
			if (field[wi - 1][hi - 1] == '+') count++;
			if (field[wi][hi - 1] == '+') count++;
			if (field[wi + 1][hi - 1] == '+') count++;
			if (field[wi - 1][0] == '+') count++;
			if (field[wi][0] == '+') count++;
			if (field[wi + 1][0] == '+') count++;
			if (field[wi + 1][hi] == '+') count++;
			if (field[wi - 1][hi] == '+') count++;
		}
	}

	return count;
}

bool Conways_life::isSystemAlive() {
	bool res = false;
	for (int i = 0; i < sizew; i++) {
		for (int j = 0; j < sizeh; j++) {
			if (check[i][j])
				return true;
		}
	}
	return res;
}

void Conways_life::Start() {

	while (isSystemAlive()) {
		checkNextStep();
		redraw();
	}
}