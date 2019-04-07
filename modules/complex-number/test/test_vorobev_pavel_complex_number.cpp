// Copyright 2019 Vorobev Pavel

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Vorobev_Pavel_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Vorobev_Pavel_ComplexNumberTest, Can_Add_Two_Numbers) {
    // Arrange
    double re = 1.0;
    double im = 2.0;

    double re1 = 3.0;
    double im1 = 5.0;
    // Act
    ComplexNumber x(re, im);
    ComplexNumber y(re1, im1);
    ComplexNumber z = x + y;

    // Assert
    EXPECT_EQ(re + re1, z.getRe());
    EXPECT_EQ(im + im1, z.getIm());
}

TEST(Vorobev_Pavel_ComplexNumberTest, Can_Substract_Two_Numbers) {
    // Arrange
    double re = 11.0;
    double im = 12.0;

    double re1 = 3.0;
    double im1 = 5.0;
    // Act
    ComplexNumber x(re, im);
    ComplexNumber y(re1, im1);
    ComplexNumber z = x - y;

    // Assert
    EXPECT_EQ(re - re1, z.getRe());
    EXPECT_EQ(im - im1, z.getIm());
}

TEST(Vorobev_Pavel_ComplexNumberTest, Can_Check_Inequality) {
    // Arrange
    double re = 1.0;
    double im = 12.0;

    double re1 = 4.0;
    double im1 = 7.0;
    // Act
    ComplexNumber x(re, im);
    ComplexNumber y(re1, im1);

    // Assert
    EXPECT_EQ(true, x != y);
}

TEST(Vorobev_Pavel_ComplexNumberTest, Can_Multiply_Two_Numbers) {
    // Arrange
    double re = 1.0;
    double im = 1.0;

    double re1 = 3.0;
    double im1 = 5.0;
    // Act
    ComplexNumber x(re, im);
    ComplexNumber y(re1, im1);
    ComplexNumber z = x * y;

    // Assert
    EXPECT_EQ(-2, z.getRe());
    EXPECT_EQ(8, z.getIm());
}
