// Copyright 2019 Blagin Ivan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Blagin_Ivan_ComplexNumberTest, Can_Addition_Of_Complex_Numbers) {
    // Arrange
    ComplexNumber a(1.0, 2.0);
    ComplexNumber b(2.0, 1.0);
    ComplexNumber expRes(3.0, 3.0);
    ComplexNumber actRes;

    // Act
    actRes = a + b;

    // Assert
    EXPECT_EQ(expRes, actRes);
}

TEST(Blagin_Ivan_ComplexNumberTest, Can_Multiplication_By_Zero) {
    // Arrange
    ComplexNumber a(1.0, 1.0);
    ComplexNumber zero(0.0, 0.0);
    ComplexNumber res;

    // Act
    res = a * zero;

    // Assert
    EXPECT_EQ(res, zero);
}

TEST(Blagin_Ivan_ComplexNumberTest, Can_Divide_By_Minus_One) {
    // Arrange
    ComplexNumber x(5.0, 5.0);
    ComplexNumber minOne(-1.0, 0.0);
    ComplexNumber res;

    // Act
    res = x / minOne;

    // Assert
    EXPECT_EQ(res.getRe(), -5.0);
    EXPECT_EQ(res.getIm(), -5.0);
}

TEST(Blagin_Ivan_ComplexNumberTest, Can_compare_equals_complex_numbers) {
    // Arrange
    double re = 9;
    double im = 3;

    // Act
    ComplexNumber x(re, im);
    ComplexNumber y(re, im);

    // Assert
    EXPECT_EQ(x.getRe(), y.getRe());
    EXPECT_EQ(x.getIm(), y.getIm());
}

TEST(Blagin_Ivan_ComplexNumberTest,
    The_result_of_div_and_mult_by_the_same_numb_shouldnt_diff_from_the_origin) {
    // Arrange
    ComplexNumber x(5.0, 6.0);
    ComplexNumber y(3.0, 2.0);
    ComplexNumber res(5.0, 6.0);

    // Act
    x = x / y * y;

    // Assert
    EXPECT_EQ(x, res);
}
