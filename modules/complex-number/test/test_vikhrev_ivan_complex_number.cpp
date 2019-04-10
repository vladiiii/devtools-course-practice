// Copyright 2017 Vikhrev Ivan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Vikhrev_Ivan_ComplexNumberTest, diff_two_equals_equal_zero) {
    // Arrange
    double re = 1.0;
    double im = 1.0;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, im);
    ComplexNumber diff = z1-z2;
    // Assert
    EXPECT_EQ(re, diff.getRe());
	EXPECT_EQ(im, diff.getIm());
}

TEST(Vikhrev_Ivan_ComplexNumberTest, diff_two_equals_equal_zero) {
    // Arrange
    double re = 1.0;
    double im = 1.0;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, im);
    ComplexNumber diff = z1-z2;
    // Assert
    EXPECT_EQ(re, diff.getRe());
	EXPECT_EQ(im, diff.getIm());
}

TEST(Vikhrev_Ivan_ComplexNumberTest, diff_two_equals_equal_zero) {
    // Arrange
    double re = 1.0;
    double im = 1.0;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, im);
    ComplexNumber diff = z1-z2;
    // Assert
    EXPECT_EQ(re, diff.getRe());
	EXPECT_EQ(im, diff.getIm());
}

TEST(Vikhrev_Ivan_ComplexNumberTest, diff_two_equalszero) {
    // Arrange
    double re = 1.0;
    double im = 1.0;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, im);
    ComplexNumber diff = z1-z2;
    // Assert
    EXPECT_EQ(re, diff.getRe());
	EXPECT_EQ(im, diff.getIm());
}

TEST(Vikhrev_Ivan_ComplexNumberTest, diff_two_equals_is_zero) {
    // Arrange
    double re = 1.0;
    double im = 1.0;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, im);
    ComplexNumber diff = z1-z2;
    // Assert
    EXPECT_EQ(re, diff.getRe());
	EXPECT_EQ(im, diff.getIm());
}