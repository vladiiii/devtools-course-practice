// Copyright 2019 Shemetov Philipp

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Shemetov_Philipp_ComplexNumberTest, Addition_Real_Numbers) {
    // Arrange
    ComplexNumber first(4.0, 0.0);
    ComplexNumber second(6.0, 0.0);
    ComplexNumber result;

    // Act
    result = first + second;

    // Assert
    EXPECT_TRUE(result.getRe() == 10.0 && result.getIm() == 0.0);
}

TEST(Shemetov_Philipp_ComplexNumberTest, Multiply_On_Zero) {
    // Arrange
    ComplexNumber zero(0, 0);
    ComplexNumber second(10.0, 12.0);

    // Act
    ComplexNumber res = zero * second;

    // Assert
    EXPECT_FLOAT_EQ(0, res.getRe());
    EXPECT_FLOAT_EQ(0, res.getIm());
}

TEST(Shemetov_Philipp_ComplexNumberTest, Equate_Complexnumber) {
    // Arrange
    ComplexNumber first(10.2345, 15.0);
    ComplexNumber second(275.92, 34.35);
    ComplexNumber third(10567.79, 103456.38);

    // Act
    first = second = third;

    // Assert
    EXPECT_TRUE(third == first && second == first);
}

TEST(Shemetov_Philipp_ComplexNumberTest, Sum_Two_Opposite_Equals_Zero) {
    // Arrange
    ComplexNumber one(10, -8);
    ComplexNumber second(-10, 8);
    ComplexNumber third(0, 0);

    // Act
    ComplexNumber res = one + second;

    // Assert
    EXPECT_EQ(third, res);
}
