// Copyright 2019 Sadikov Artem

#include <gtest/gtest.h>

#include <cmath>

#include "include/complex_number.h"

TEST(Sadikov_Artem_ComplexNumberTest, Return_zero_if_multiplicate_with_zero) {
    // Arrange
    double re = 13.0;
    double im = 12.0;
    ComplexNumber z(re, im);
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber zr;

    // Act
    zr = z * z1;

    // Assert
    EXPECT_EQ(z1, zr);
}

TEST(Sadikov_Artem_ComplexNumberTest, Can_create_without_args) {
    // Arrange & Act
    ComplexNumber z(0.0, 0.0);
    ComplexNumber zr;

    // Assert
    EXPECT_EQ(z, zr);
}

TEST(Sadikov_Artem_ComplexNumberTest, Can_multiply_module) {
    // Arrange
    int ab1;
    int ab2;
    int abr;
    ComplexNumber z(13.0, 12.0);
    ComplexNumber z1(12.0, 13.0);

    // Act
    ab1 = fabs(z.getRe() + z.getIm());
    ab2 = fabs(z1.getRe() + z1.getIm());
    abr = ab1 * ab2;

    // Assert
    EXPECT_EQ(abr, ab1 * ab2);
}

TEST(Sadikov_Artem_ComplexNumberTest, Can_Multiply_Complex_with_zero) {
    // Arrange
    ComplexNumber z(12.0, 12.0);
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber zr;

    // Act
    zr = z * z1;

    // Assert
    EXPECT_EQ(zr, z1);
}

TEST(Sadikov_Artem_ComplexNumberTest, Can_assign_Complex) {
    // Arrange & Act
    ComplexNumber z(12.0, 12.0);
    ComplexNumber z1;

    // Assert
    ASSERT_NO_THROW(z1 = z);
}
