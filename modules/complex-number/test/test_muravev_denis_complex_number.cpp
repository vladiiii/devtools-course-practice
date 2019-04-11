// Copyright 2019 Muravev Denis

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Muravev_Denis_ComplexNumberTest, Can_Create_Re) {
    // Arrange
    double re = 1.2;

    // Act
    ComplexNumber a(re, 0.0);

    // Assert
    EXPECT_EQ(re, a.getRe());
}

TEST(Muravev_Denis_ComplexNumberTest, Can_Create_Im) {
    // Arrange
    double im = 2.1;

    // Act
    ComplexNumber a(0.0, im);

    // Assert
    EXPECT_EQ(im, a.getIm());
}

TEST(Muravev_Denis_ComplexNumberTest, Sum_Complex_Numbers) {
    // Arrange
    ComplexNumber a(1.0, 7.0);
    ComplexNumber b(2.0, -5.0);
    ComplexNumber c;

    // Act
    c = a + b;

    // Assert
    EXPECT_EQ(3.0, c.getRe());
    EXPECT_EQ(2.0, c.getIm());
}

TEST(Muravev_Denis_ComplexNumberTest, Subtraction_Complex_Numbers) {
    // Arrange
    ComplexNumber a(8.5, 8.0);
    ComplexNumber b(4.0, 16.5);
    ComplexNumber c;

    // Act
    c = a - b;

    // Assert
    EXPECT_EQ(4.5, c.getRe());
    EXPECT_EQ(-8.5, c.getIm());
}

TEST(Muravev_Denis_ComplexNumberTest, Multiplication_Im_Parts) {
    // Arrange
    ComplexNumber a(0.0, 1.0);
    ComplexNumber b(0.0, 1.0);
    ComplexNumber c;

    // Act
    c = a * b;

    // Assert
    EXPECT_EQ(-1.0, c.getRe());
    EXPECT_EQ(0.0, c.getIm());
}

TEST(Muravev_Denis_ComplexNumberTest, Copying_Complex_Numbers) {
    // Arrange
    ComplexNumber a(1.7, 2.5);
    ComplexNumber b;

    // Act
    b = a;

    // Assert
    EXPECT_EQ(1.7, b.getRe());
    EXPECT_EQ(2.5, b.getIm());
}
