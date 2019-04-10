// Copyright 2019 Sitkin Dmitry

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Sitkin_Dmitry_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Sitkin_Dmitry_ComplexNumberTest, Can_Equate) {
    // Arrange
    double re1 = 5.0;
    double im1 = 3.0;

    double re2 = 4.0;
    double im2 = 2.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    z1 = z2;

    // Assert
    EXPECT_EQ(z1.getRe(), z2.getRe());
    EXPECT_EQ(z1.getIm(), z2.getIm());
}

TEST(Sitkin_Dmitry_ComplexNumberTest, Can_Add_Numbers) {
    // Arrange
    double re1 = 5.0;
    double im1 = 3.0;

    double re2 = 4.0;
    double im2 = 2.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3 = z1 + z2;

    // Assert
    ComplexNumber expected(9.0, 5.0);
    EXPECT_EQ(expected.getRe(), z3.getRe());
    EXPECT_EQ(expected.getIm(), z3.getIm());
}

TEST(Sitkin_Dmitry_ComplexNumberTest, Can_Difference_Numbers) {
    // Arrange
    double re1 = 5.0;
    double im1 = 3.0;

    double re2 = 4.0;
    double im2 = 2.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3 = z1 - z2;

    // Assert
    ComplexNumber expected(1.0, 1.0);
    EXPECT_EQ(expected.getRe(), z3.getRe());
    EXPECT_EQ(expected.getIm(), z3.getIm());
}

TEST(Sitkin_Dmitry_ComplexNumberTest, Division_Equals_Number_Is_One) {
    // Arrange
    double re = 5.0;
    double im = 3.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber division=z/z;

    // Assert
    double expected_re=1.0;
    double expected_im = 0.0;
    EXPECT_EQ(expected_re, division.getRe());
    EXPECT_EQ(expected_im, division.getIm());
}

TEST(Sitkin_Dmitry_ComplexNumberTest, Multiplication_Conjugate_Complex) {
    // Arrange
    double re1 = 5.0;
    double im1 = 3.0;

    double re2 = 5.0;
    double im2 = -3.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3 = z1 * z2;

    // Assert
    ComplexNumber expected(34.0, 0.0);
    EXPECT_EQ(expected.getRe(), z3.getRe());
    EXPECT_EQ(expected.getIm(), z3.getIm());
}