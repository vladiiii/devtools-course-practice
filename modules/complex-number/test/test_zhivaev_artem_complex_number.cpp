// Copyright 2019 Zhivaev Artem

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Zhivaev_Artem_ComplexNumberTest, Can_Create_Negative_Real) {
    // Arrange
    double re = -9.45;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Zhivaev_Artem_ComplexNumberTest, Can_Create_Negative_Imagine) {
    // Arrange
    double re = 0.0;
    double im = -9.45;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Zhivaev_Artem_ComplexNumberTest, Can_Copy) {
    // Arrange
    double re = 123.123;
    double im = 321.321;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(z1);

    // Assert
    EXPECT_EQ(re, z2.getRe());
    EXPECT_EQ(im, z2.getIm());
}

TEST(Zhivaev_Artem_ComplexNumberTest, Can_SetRe) {
    // Arrange
    double re = -123.123;

    // Act
    ComplexNumber z;
    z.setRe(re);

    // Assert
    EXPECT_EQ(re, z.getRe());
}

TEST(Zhivaev_Artem_ComplexNumberTest, Can_SetIm) {
    // Arrange
    double im = -123.123;

    // Act
    ComplexNumber z;
    z.setIm(im);

    // Assert
    EXPECT_EQ(im, z.getIm());
}

