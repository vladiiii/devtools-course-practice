// Copyright 2019 Kurakin Mikhail

#include <gtest/gtest.h>

#include "include/TShapesArea3D.h"

TEST(Kurakin_Mikhail_TShapesArea3D, Can_Calculate_Area_Of_Sphere) {
    // Arrange
    double radius = 3.4;
    // Act
    double result = TShapesArea3D::sphereArea(radius);
    // Assert
    double exp_ans = 145.2672;
    EXPECT_NEAR(exp_ans, result, 4);
}

TEST(Kurakin_Mikhail_TShapesArea3D, Can_Calculate_Area_Of_Cylinder) {
    // Arrange
    double radius = 3.4;
    double height = 4.0;
    // Act
    double result = TShapesArea3D::cylinderArea(radius, height);
    // Assert
    double exp_ans = 158.0849;
    EXPECT_NEAR(exp_ans, result, 4);
}

TEST(Kurakin_Mikhail_TShapesArea3D, Can_Calculate_Area_Of_Cube) {
    // Arrange
    double a = 4.0;
    // Act
    double result = TShapesArea3D::cubeArea(a);
    // Assert
    double exp_ans = 96.0;
    EXPECT_NEAR(exp_ans, result, 4);
}

TEST(Kurakin_Mikhail_TShapesArea3D, Can_Calculate_Area_Of_Parallelepiped) {
    // Arrange
    double a = 4.0;
    double b = 3.0;
    double c = 2.0;
    // Act
    double result = TShapesArea3D::parallelepipedArea(a, b, c);
    // Assert
    double exp_ans = 52.0;
    EXPECT_NEAR(exp_ans, result, 4);
}

TEST(Kurakin_Mikhail_TShapesArea3D, Can_Calculate_Area_Of_Cone) {
    // Arrange
    double radius = 5.5;
    double generator = 3.2;
    // Act
    double result = TShapesArea3D::coneArea(radius, generator);
    // Assert
    double exp_ans = 150.3252;
    EXPECT_NEAR(exp_ans, result, 4);
}

TEST(Kurakin_Mikhail_TShapesArea3D, Can_Calculate_Area_Of_Tetrahedron) {
    // Arrange
    double a = 8.8;
    // Act
    double result = TShapesArea3D::tetrahedronArea(a);
    // Assert
    double exp_ans = 134.1300;
    EXPECT_NEAR(exp_ans, result, 4);
}
