// Copyright 2019 Kurakin Mikhail
#include <cmath>
#include "include/TShapesArea3D.h"

double TShapesArea3D::sphereArea(double radius) {
    return 4.0 * M_PI * pow(radius, 2.0);
}

double TShapesArea3D::cylinderArea(double radius, double height) {
    return 2.0 * M_PI * radius * (height + radius);
}

double TShapesArea3D::cubeArea(double a) {
    return 6.0 * pow(a, 2.0);
}

double TShapesArea3D::parallelepipedArea(double a, double b, double c) {
    return 2.0 * (a * b + b * c + a * c);
}

double TShapesArea3D::coneArea(double radius, double generator) {
    return M_PI * radius * (radius + generator);
}

double TShapesArea3D::tetrahedronArea(double a) {
    return sqrt(3.0) * pow(a, 2.0);
}