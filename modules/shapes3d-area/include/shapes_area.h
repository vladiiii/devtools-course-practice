// Copyright 2019 Kurakin Mikhail
#ifndef MODULES_SHAPES_AREA_INCLUDE_SHAPES_AREA_H_
#define MODULES_SHAPES_AREA_INCLUDE_SHAPES_AREA_H_

class ShapesArea {
 public:
    static double sphereArea(double radius);
    static double cylinderArea(double radius, double height);
    static double cubeArea(double a);
    static double parallelepipedArea(double a, double b, double c);
    static double coneArea(double radius, double generator);
    static double tetrahedronArea(double a);
};

#endif  // MODULES_SHAPES_AREA_INCLUDE_SHAPES_AREA_H_




