// Copyright 2017 Holobko Vladimir

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Holobko_Vladimir_ComplexNumberTest, Numbers_Is_Equal_After_Multiply) {
    // Arrange
    ComplexNumber a(6.0, 3.0);
    ComplexNumber b(6.0, 3.0);

    // Act
    ComplexNumber c = a * b;

    // Assert
    ComplexNumber exp_ans(27.0, 36.0);
    EXPECT_EQ(exp_ans, c);
}

TEST(Holobko_Vladimir_ComplexNumberTest, Numbers_Is_Equal_After_Division) {
    // Arrange
    ComplexNumber a(50.0, 20.0);
    ComplexNumber b(2.0, 4.0);

    // Act
    ComplexNumber c = a / b;

    // Assert
    ComplexNumber exp_ans(9, -8.0);
    EXPECT_EQ(exp_ans, c);
}

TEST(Holobko_Vladimir_ComplexNumberTest, Can_CC_CV) {
    // Arrange
    double re = 77.7;
    double im = 55.5;

    // Act
    ComplexNumber a(re, im);
    ComplexNumber c(a);

    // Assert
    EXPECT_EQ(a.getRe(), c.getRe());
    EXPECT_EQ(a.getIm(), c.getIm());
}

TEST(Holobko_Vladimir_ComplexNumberTest, Can_Assign_To_Itself_Complex_Numbers) {
    // Act
    ComplexNumber a(5.0, 7.7);

    // Assert
    ASSERT_NO_THROW(a = a);
}

TEST(Holobko_Vladimir_ComplexNumberTest, Can_Difference_More_Than_Two_Complex_Numbers) {
    // Act
    ComplexNumber a(10., 10.);
    ComplexNumber b(1., 1.);
    ComplexNumber expect(7., 7.);
    ComplexNumber c = a - b - b - b;

    // Assert
    EXPECT_EQ(expect.getRe(), c.getRe());
    EXPECT_EQ(expect.getIm(), c.getIm());
}