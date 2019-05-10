// Copyright 2019 Vikhrev Ivan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Vikhrev_Ivan_ComplexNumberTest, diff_two_equals_is_zero) {
    // Arrange
    double re = 1.0;
    double im = 1.0;
    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, im);
    ComplexNumber diff = z1-z2;
    // Assert
    EXPECT_DOUBLE_EQ(0.0, diff.getRe());
    EXPECT_DOUBLE_EQ(0.0, diff.getIm());
}

TEST(Vikhrev_Ivan_ComplexNumberTest, copied_has_its_own_memory) {
    // Arrange
    double re = 1.0;
    double im = 1.0;
    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(z1);
    // Assert
    EXPECT_NE(&z1, &z2);
}

TEST(Vikhrev_Ivan_ComplexNumberTest, mult_of_conjugate_numbers_is_correct) {
    // Arrange
    double re1 = 1.0;
    double im1 = 1.0;
    double re2 = 1.0;
    double im2 = -1.0;
    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber res = z1 * z2;
    // Assert
    EXPECT_DOUBLE_EQ(re1*re1+im1*im1, res.getRe());
    EXPECT_DOUBLE_EQ(0.0, res.getIm());
}
