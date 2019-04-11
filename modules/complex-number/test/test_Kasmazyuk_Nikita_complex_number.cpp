// Copyright 2019 Kasmazyuk Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Can_Create_Zero) {
// Arrange
    double re = 0.0;
    double im = 0.0;
// Act
    ComplexNumber z(re, im);
// Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Can_Sum_Complex_Number) {
// Arrange
    ComplexNumber z1(15.0, 15.0);
    ComplexNumber z2(5.0, 10.0);
    ComplexNumber z = z1 + z2;
// Act
    ComplexNumber expected_z(20.0, 25.0);
// Assert
    EXPECT_EQ(expected_z, z);
}

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Can_Sum_Complex_Number) {
// Arrange
    ComplexNumber z1(15.0, 15.0);
    ComplexNumber z2(5.0, 10.0);
    ComplexNumber z = z1 - z2;
// Act
    ComplexNumber expected_z(10.0, 5.0);
// Assert
    EXPECT_EQ(expected_z, z);
}

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Can_Multiplication_Complex_Number) {
// Arrange
    ComplexNumber z1(15.0, 15.0);
    ComplexNumber z2(5.0, 10.0);
    ComplexNumber z = z1 * z2;
// Act
    ComplexNumber expected_z(75.0, 150.0);
// Assert
    EXPECT_EQ(expected_z, z);
}

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Equal_Numbers_Are_Equal) {
// Arrange
    ComplexNumber z1(15.0, 15.0);
    ComplexNumber z2(15.0, 15.0);
// Act & Assert
    EXPECT_EQ(z1, z2);
}

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Not_Equal_Numbers_Not_Equal) {
// Arrange
    ComplexNumber z1(15.0, 15.0);
    ComplexNumber z2(5.0, 10.0);
// Act & Assert
    EXPECT_TRUE(z1 != z2);
}
