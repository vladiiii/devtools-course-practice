// Copyright 2019 Tolstikov Maksim

#include <gtest/gtest.h>
#include <limits.h>
#include "include/complex_number.h"

TEST(Tolstikov_Maksim_ComplexNumberTest, Can_Create_int_Comlex_Number) {
    // Arrange
    ComplexNumber z;
    int re = 1;
    int im = 10;
    // Act
    z.setRe(re);
    z.setIm(im);
    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Tolstikov_Maksim_ComplexNumberTest, Can_Create_Big_Complex_Number) {
    // Arrange
    ComplexNumber z;
    int re = UINT_MAX;
    int im = UINT_MAX;
    // Act
    z.setRe(re);
    z.setIm(im);
    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Tolstikov_Maksim_ComplexNumberTest, Can_Exponentiation) {
    // Arrange
    ComplexNumber z(4.0, 3.0);
    ComplexNumber z1;
    // Act
    z1 = z * z;
    // Assert
    EXPECT_EQ(7.0, z1.getRe());
    EXPECT_EQ(24.0, z1.getIm());
}

TEST(Tolstikov_Maksim_ComplexNumberTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(26.0, 14.0);
    // Act & Assert
    ASSERT_ANY_THROW(z2 / z1);
}

TEST(Tolstikov_Maksim_ComplexNumberTest, Can_Complex_Number_Divide_By_Real) {
    // Arrange
    ComplexNumber z1(2.0, 0.0);
    ComplexNumber z2(26.0, 14.0);
    // Act
    ComplexNumber z3 = z2 / z1;
    // Assert
    EXPECT_EQ(13.0, z3.getRe());
    EXPECT_EQ(7.0, z3.getIm());
}
