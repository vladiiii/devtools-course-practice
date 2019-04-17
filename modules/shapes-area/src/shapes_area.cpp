// Copyright 2019 Kurakin Mikhail
#define _USE_MATH_DEFINES
#include <cmath>
#include "include/shapes_area.h"

double ShapesArea::sphereArea(double radius) {
    return 4.0 * M_PI * pow(radius, 2.0);
}

double ShapesArea::cylinderArea(double radius, double height) {
    return 2.0 * M_PI * radius * (height + radius);
}

double ShapesArea::cubeArea(double a) {
    return 6.0 * pow(a, 2.0);
}

double ShapesArea::parallelepipedArea(double a, double b, double c) {
    return 2.0 * (a * b + b * c + a * c);
}

double ShapesArea::coneArea(double radius, double generator) {
    return M_PI * radius * (radius + generator);
}

double ShapesArea::tetrahedronArea(double a) {
    return sqrt(3.0) * pow(a, 2.0);
}

