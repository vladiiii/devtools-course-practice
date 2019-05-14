// Copyright 2019 Kudrin Matvey

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Kudrin_Matvey_ComplexNumberTest, Test_Multiply_Commutativity) {
    // Arrange
    int random_number = 576467547;
    double re1 = random_number / 1000.0;
    double im1 = random_number / 5000.0;
    double re2 = random_number / 1234.0;
    double im2 = random_number / 5234.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_EQ(z1 * z2, z2 * z1);
}

TEST(Kudrin_Matvey_ComplexNumberTest,
        Changes_To_Copied_Complex_Number_Dont_Affect_Original) {
    // Arrange
    ComplexNumber original(1.0, 2.0);
    ComplexNumber copied(original);
    ComplexNumber delta(4.5, 0.01);

    // Act
    copied = original + delta;
    // Assert
    EXPECT_TRUE(copied != original);
}

TEST(Kudrin_Matvey_ComplexNumberTest, Properly_Adds_Real_Numbers) {
    // Arrange
    ComplexNumber one(1.0, 0.0);
    ComplexNumber two(2.0, 0.0);
    ComplexNumber result;

    // Act
    result = one + two;

    // Assert
    EXPECT_TRUE(result.getRe() == 3.0 && result.getIm() == 0.0);
}

TEST(Kudrin_Matvey_ComplexNumberTest, Multiplied_By_Zero_Equals_To_Zero) {
    // Arrange
    double re = 13.0;
    double im = 50.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber zero(0.0, 0.0);
    ComplexNumber result;

    // Assert
    result = z * zero;
    ASSERT_EQ(result, zero);
}

TEST(Kudrin_Matvey_ComplexNumberTest, Multiplied_By_One_Equals_To_Itself) {
    // Arrange
    double re = 13.0;
    double im = 50.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber one(1.0, 0.0);
    ComplexNumber result;

    // Assert
    result = z * one;
    ASSERT_EQ(result, z);
}
