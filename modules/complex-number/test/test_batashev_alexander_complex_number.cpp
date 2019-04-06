// Copyright 2019 Alexander Batashev

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Batashev_Alexander_ComplexNumberTest, Can_Add_Three_Numbers) {
    // Arrange
    ComplexNumber a(1.0, 2.0);
    ComplexNumber b(3.0, 4.0);
    ComplexNumber c(5.0, 6.0);

    // Act
    ComplexNumber res = a + b + c;

    // Assert
    EXPECT_FLOAT_EQ(9.0, res.getRe());
    EXPECT_FLOAT_EQ(12.0, res.getIm());
}

TEST(Batashev_Alexander_ComplexNumberTest, Ops_Priority_Is_Correct) {
    // Arrange
    ComplexNumber a(1.0, 2.0);
    ComplexNumber b(3.0, 4.0);
    ComplexNumber c(5.0, 6.0);

    // Act
    ComplexNumber res = a * b + c;

    // Assert
    EXPECT_FLOAT_EQ(0, res.getRe());
    EXPECT_FLOAT_EQ(16, res.getIm());
}

TEST(Batashev_Alexander_ComplexNumberTest, Multiply_By_Zero) {
    // Arrange
    ComplexNumber zero(0, 0);
    ComplexNumber a(1.0, 2.0);

    // Act
    ComplexNumber res = zero * a;

    // Assert
    EXPECT_FLOAT_EQ(0, res.getRe());
    EXPECT_FLOAT_EQ(0, res.getIm());
}

TEST(Batashev_Alexander_ComplexNumberTest, Imaginary_Unit_Square) {
    // Arrange
    ComplexNumber i(0, 1);

    // Act
    ComplexNumber res = i * i;

    // Assert
    EXPECT_FLOAT_EQ(-1, res.getRe());
    EXPECT_FLOAT_EQ(0, res.getIm());
}

TEST(Batashev_Alexander_ComplexNumberTest, Imaginary_Unit_Cube) {
    // Arrange
    ComplexNumber i(0, 1);

    // Act
    ComplexNumber res = i * i * i;

    // Assert
    EXPECT_FLOAT_EQ(0, res.getRe());
    EXPECT_FLOAT_EQ(-1, res.getIm());
}
