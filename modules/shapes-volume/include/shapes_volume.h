// Copyright 2019 Evdokimov Artem

#ifndef MODULES_SHAPES_VOLUME_INCLUDE_SHAPES_VOLUME_H_
#define MODULES_SHAPES_VOLUME_INCLUDE_SHAPES_VOLUME_H_

class ShapesVolume {
 public:
    static double SphereVolume(double radius);
    static double CylinderVolume(double radius , double height);
    static double CubeVolume(double a);
    static double ParallelepipedVolume(double a , double b , double c);
    static double ConeVolume(double radius , double height);
    static double TetrahedronVolume(double a);
};

#endif // MODULES_SHAPES_VOLUME_INCLUDE_SHAPES_VOLUME_H_
