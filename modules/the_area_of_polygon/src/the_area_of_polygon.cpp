// Copyright 2019 Kondrina Tatyana

#include <string>
#include <iostream>
#include "include/the_area_of_polygon.h"

AreaOfPolygon::AreaOfPolygon(std::vector<std::vector<int>> p):points_(p) {}

AreaOfPolygon::~AreaOfPolygon() {
    for (int i = 0; i < points_.size(); i++)
        points_[i].clear();
    points_.clear();
}

double AreaOfPolygon::Area() {
    int sum = 0;
    int i = 0;
    for (int i = 0; i < points_.size() - 1; i++) {
        sum += abs((points_[i][0] + points_[i + 1][0]) *
                   (points_[i + 1][1] - points_[i][1]));
    }
    sum += abs((points_[0][0] + points_[i][0]) *
               (points_[0][1] - points_[i][1]));
    return sum / 2;
}

void AreaOfPolygon::SetPoint(int n, std::vector<int> p) {
    if (n < 0) throw - 1;
    points_[n] = p;
}