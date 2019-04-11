// Copyright 2019 Shkerin Igor

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Shkerin_Igor_ComplexNumberTest, Can_Create_Negative_Complex) {
    // Arrange
    double re = -3.0;
    double im = -7.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Shkerin_Igor_ComplexNumberTest, Correct_Setter_And_Getter) {
    // Arrange
    double re1 = 1.0;
    double im1 = 2.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2;
    z2.setRe(z1.getRe());
    z2.setIm(z1.getIm());

    // Assert
    EXPECT_EQ(z1, z2);
}