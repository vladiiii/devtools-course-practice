// Copyright 2019 Shkerin Igor

#ifndef MODULES_TRIANGLES_INCLUDE_TRIANGLES_H_
#define MODULES_TRIANGLES_INCLUDE_TRIANGLES_H_

#include <iostream>
#include <vector>

struct Point {
    double x, y;

    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {};
};

class Triangle {
public:
    Triangle();
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
    Triangle(std::pair<double, double> _a, std::pair<double, double> _b, std::pair<double, double> _c);
    Triangle(Point _a, Point _b, Point _c);
    Triangle(double* array);
    Triangle(std::vector<double> array);

    bool IsTriangleExist(std::vector<double> array);

private:
    Point a, b, c;

};

#endif  // MODULES_TRIANGLES_INCLUDE_TRIANGLES_H_
