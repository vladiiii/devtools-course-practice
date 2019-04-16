// Copyright 2019 Kurakin Mikhail
#ifndef MODULES_CALCULATE_AREAD3DSHAPES_INCLUDE_TSHAPESAREA3D_H_
#define MODULES_CALCULATE_AREAD3DSHAPES_INCLUDE_TSHAPESAREA3D_H_

class TShapesArea3D {
    public:
    static double sphereArea(double radius);
    static double cylinderArea(double radius, double height);
    static double cubeArea(double a);
    static double parallelepipedArea(double a, double b, double c);
    static double coneArea(double radius, double generator);
    static double tetrahedronArea(double a);
};

#endif // MODULES_CALCULATE_AREAD3DSHAPES_INCLUDE_TSHAPESAREA3D_H_