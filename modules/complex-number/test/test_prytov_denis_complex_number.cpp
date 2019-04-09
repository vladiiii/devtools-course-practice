// Copyright 2019 Prytov Denis

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Prytov_Denis_ComplexNumberTest, Can_Сalculate_Сomplex_Expressions_With_Sum) {
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

TEST(Prytov_Denis_ComplexNumberTest, Can_Сalculate_Сomplex_Expressions_With_Sub) {
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

TEST(Prytov_Denis_ComplexNumberTest, Are_Equal_Complex_Numbers) {
    // Arrange
    ComplexNumber a(1.1, 4.4);
    ComplexNumber b(1.1, 4.4);
    ComplexNumber c(2.25, 3.36);
    ComplexNumber d(2.25, 3.36);
    bool result;

    // Act
    result = a == b && c == d;

    // Assert
    ASSERT_TRUE(result);
}

TEST(Prytov_Denis_ComplexNumberTest, Are_Not_Equal_Complex_Numbers) {
    // Arrange
    ComplexNumber a(1.1, 4.4);
    ComplexNumber b(2.2, 3.3);
    ComplexNumber c(3.35, 2.26);
    ComplexNumber d(4.45, 1.16);
    bool result;

    // Act
    result = a != b && c != d;

    // Assert
    ASSERT_TRUE(result);
}
