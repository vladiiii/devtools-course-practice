// Copyright 2019 Prytov Denis

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Prytov_Denis_ComplexNumberTest, Can_Sum_Complex_Numbers) {
    // Arrange
    ComplexNumber a(1.2, 4.3);
    ComplexNumber b(4.3, 1.2);
    ComplexNumber c;

    // Act
    c = a + b;

    // Assert
    EXPECT_EQ(5.5, c.getRe());
    EXPECT_EQ(5.5, c.getIm());
}

TEST(Prytov_Denis_ComplexNumberTest, Can_Subtract_Complex_Numbers) {
    // Arrange
    ComplexNumber a(1.2, 4.3);
    ComplexNumber b(4.3, 1.2);
    ComplexNumber c;

    // Act
    c = a - b;

    // Assert
    EXPECT_NEAR(-3.1, c.getRe(), 0.01);
    EXPECT_NEAR(3.1, c.getIm(), 0.01);
}

TEST(Prytov_Denis_ComplexNumberTest, Are_Equal_Complex_Numbers) {
    // Arrange
    ComplexNumber a(1.2, 4.3);
    ComplexNumber b(1.2, 4.3);
    bool result;

    // Act
    result = a == b;

    // Assert
    ASSERT_TRUE(result);
}

TEST(Prytov_Denis_ComplexNumberTest, Are_Not_Equal_Complex_Numbers) {
    // Arrange
    ComplexNumber a(1.2, 4.3);
    ComplexNumber b(1.1, 4.3);
    bool result;

    // Act
    result = a != b;

    // Assert
    ASSERT_TRUE(result);
}