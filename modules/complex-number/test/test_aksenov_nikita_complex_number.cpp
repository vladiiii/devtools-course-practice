// Copyright 2019 Aksenov Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Aksenov_Nikita_ComplexNumberTest,
    Can_Not_Divide_By_Zero) {
    // Arrange
    double re1 = 3.0;
    double im1 = 7.0;
    double re2 = 0.0;
    double im2 = 0.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_ANY_THROW(z1 / z2);
}

TEST(Aksenov_Nikita_ComplexNumberTest,
    Two_Reverse_Numbers_Are_Not_Equal) {
    // Arrange
    double re1 = 3.0;
    double im1 = 7.0;
    double re2 = 7.0;
    double im2 = 3.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_NE(z1, z2);
}

TEST(Aksenov_Nikita_ComplexNumberTest,
    The_Same_Result_After_Multiplication_By_Certain_Number) {
    // Arrange
    double re1 = 3.0;
    double im1 = 7.0;
    double re2 = 1.0;
    double im2 = 0.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3 = z1 * z2;

    // Assert
    EXPECT_EQ(z1, z3);
}

TEST(Aksenov_Nikita_ComplexNumberTest,
    Check_The_Associativity_Of_Addition) {
    // Arrange
    ComplexNumber z1(3.3, 3.3);
    ComplexNumber z2(7.7, 7.7);
    ComplexNumber z3(3.7, 3.7);

    // Act
    ComplexNumber sum1 = (z1 + z2) + z3;
    ComplexNumber sum2 = (z2 + z3) + z1;

    // Assert
    EXPECT_EQ(sum1, sum2);
}

TEST(Aksenov_Nikita_ComplexNumberTest,
    Can_Subtract_Two_Negative_Numbers) {
    // Arrange
    double re1 = -3.0;
    double im1 = -7.0;
    double re2 = -3.0;
    double im2 = -7.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber result = z1 - z2;

    // Assert
    ComplexNumber expected_result(0.0, 0.0);
    EXPECT_EQ(expected_result, result);
}
