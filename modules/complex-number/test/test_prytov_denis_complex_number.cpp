// Copyright 2019 Prytov Denis

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Prytov_Denis_ComplexNumberTest, Can_Calc_Expr_Sum) {
    // Arrange
    ComplexNumber a(1.1, 4.4);
    ComplexNumber b(2.2, 3.3);
    ComplexNumber c(3.3, 2.2);
    ComplexNumber d(4.4, 1.1);
    ComplexNumber answer;

    // Act
    answer = a + b + c + d;

    // Assert
    EXPECT_EQ(11.0, answer.getRe());
    EXPECT_EQ(11.0, answer.getIm());
}

TEST(Prytov_Denis_ComplexNumberTest, Can_Calc_Expr_Sub) {
    // Arrange
    ComplexNumber a(11.0, 11.0);
    ComplexNumber b(1.1, 3.3);
    ComplexNumber c(2.2, 2.2);
    ComplexNumber d(3.3, 1.1);
    ComplexNumber answer;

    // Act
    answer = a - b - c - d;

    // Assert
    EXPECT_EQ(4.4, answer.getRe());
    EXPECT_EQ(4.4, answer.getIm());
}

TEST(Prytov_Denis_ComplexNumberTest, Can_Calc_Expr_Mult) {
    // Arrange
    ComplexNumber a(1.1, 1.1);
    ComplexNumber b(2.2, 2.2);
    ComplexNumber c(3.3, 3.3);
    ComplexNumber d(4.4, 4.4);
    ComplexNumber answer;

    // Act
    answer = a * b * c * d;

    // Assert
    EXPECT_NEAR(-140.553, answer.getRe(), 0.01);
    EXPECT_NEAR(0.0, answer.getIm(), 0.01);
}

TEST(Prytov_Denis_ComplexNumberTest, Are_Equal_Complex_Numbers) {
    // Arrange
    ComplexNumber a(1.1, 4.4);
    ComplexNumber b(1.1, 4.4);
    bool result;

    // Act
    result = a == b;

    // Assert
    ASSERT_TRUE(result);
}

TEST(Prytov_Denis_ComplexNumberTest, Are_Not_Equal_Complex_Numbers) {
    // Arrange
    ComplexNumber a(1.1, 4.4);
    ComplexNumber b(2.2, 3.3);
    bool result;

    // Act
    result = a != b;

    // Assert
    ASSERT_TRUE(result);
}
