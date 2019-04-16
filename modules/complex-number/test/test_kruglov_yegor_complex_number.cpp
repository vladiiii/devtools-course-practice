// Copyright 2019 Kruglov Yegor

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kruglov_Yegor_ComplexNumberTest, Can_Create_Real_Part) {
    // Arrange
    double re = 1.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
}

TEST(Kruglov_Yegor_ComplexNumberTest, Can_Create_Imaginary_Part) {
    // Arrange
    double re = 0.0;
    double im = 1.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(im, z.getIm());
}

TEST(Kruglov_Yegor_ComplexNumberTest, Can_Copy_Complex_Number) {
    // Arrange
    double re = 1.0;
    double im = 1.0;
    ComplexNumber z(re, im);

    // Act
    ComplexNumber z1(z);

    // Assert
    EXPECT_EQ(z.getRe(), z1.getRe());
    EXPECT_EQ(z.getIm(), z1.getIm());
}

TEST(Kruglov_Yegor_ComplexNumberTest, Can_Assign_Other_Number) {
    // Arrange
    ComplexNumber z(10.0, 10.0);
    ComplexNumber z1;

    // Act
    z1 = z;

    // Assert
    EXPECT_EQ(z, z1);
}

TEST(Kruglov_Yegor_ComplexNumberTest, Can_Multiply_By_Num_Without_Im) {
    // Arrange
    ComplexNumber z1(10.0, 10.0);
    ComplexNumber z2(20.0, 20.0);
    ComplexNumber z3(2.0, 0.0);

    // Act
    z1 = z1 * z3;

    // Assert
    EXPECT_EQ(z2, z1);
}

TEST(Kruglov_Yegor_ComplexNumberTest, Can_Multiply_By_Num_Without_Re) {
    // Arrange
    ComplexNumber z1(10.0, 10.0);
    ComplexNumber z2(-20.0, 20.0);
    ComplexNumber z3(0.0, 2.0);

    // Act
    z1 = z1 * z3;

    // Assert
    EXPECT_EQ(z2, z1);
}

TEST(Kruglov_Yegor_ComplexNumberTest, Can_Multiply_By_Complex_Num) {
    // Arrange
    ComplexNumber z1(10.0, 10.0);
    ComplexNumber z2(0.0, 200.0);

    // Act
    z1 = z1 * z1;

    // Assert
    EXPECT_EQ(z2, z1);
}

TEST(Kruglov_Yegor_ComplexNumberTest, Can_Divide_By_Num_Without_Im) {
    // Arrange
    ComplexNumber z1(10.0, 10.0);
    ComplexNumber z2(5.0, 5.0);
    ComplexNumber z3(2.0, 0.0);

    // Act
    z1 = z1 / z3;

    // Assert
    EXPECT_EQ(z2, z1);
}

TEST(Kruglov_Yegor_ComplexNumberTest, Can_Divide_By_Num_Without_Re) {
    // Arrange
    ComplexNumber z1(10.0, 10.0);
    ComplexNumber z2(5.0, -5.0);
    ComplexNumber z3(0.0, 2.0);

    // Act
    z1 = z1 / z3;

    // Assert
    EXPECT_EQ(z2, z1);
}


