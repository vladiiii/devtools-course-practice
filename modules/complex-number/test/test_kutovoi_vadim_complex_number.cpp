// Copyright 2019 Kutovoi Vadim

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kutovoi_Vadim_ComplexNumberTest, Can_add_two_complex_numbers) {
    // Arrange
    double re1 = 10;
    double im1 = 5;

    double re2 = 5;
    double im2 = 10;

    // Act
    ComplexNumber x(re1, im1);
    ComplexNumber y(re2, im2);
    ComplexNumber z = x + y;

    // Assert
    EXPECT_EQ(re1 + re2, z.getRe());
    EXPECT_EQ(im1 + im2, z.getIm());
}

TEST(Kutovoi_Vadim_ComplexNumberTest, Can_subtr_two_complex_numbers) {
    // Arrange
    double re1 = 10;
    double im1 = 5;

    double re2 = 5;
    double im2 = 10;

    // Act
    ComplexNumber x(re1, im1);
    ComplexNumber y(re2, im2);
    ComplexNumber z = x - y;

    // Assert
    EXPECT_EQ(re1 - re2, z.getRe());
    EXPECT_EQ(im1 - im2, z.getIm());
}

TEST(Kutovoi_Vadim_ComplexNumberTest, Can_multiply_complex_numbers) {
    // Arrange
    double re1 = 2;
    double im1 = 3;

    double re2 = -1;
    double im2 = 1;

    // Act
    ComplexNumber x(re1, im1);
    ComplexNumber y(re2, im2);
    ComplexNumber z = x * y;

    // Assert
    EXPECT_EQ(-5, z.getRe());
    EXPECT_EQ(-1, z.getIm());
}

TEST(Kutovoi_Vadim_ComplexNumberTest, Can_compare_equals_complex_numbers) {
    // Arrange
    double re = 2;
    double im = 3;

    // Act
    ComplexNumber x(re, im);
    ComplexNumber y(re, im);

    // Assert
    EXPECT_EQ(x.getRe(), y.getRe());
    EXPECT_EQ(x.getIm(), y.getIm());
}

TEST(Kutovoi_Vadim_ComplexNumberTest, Can_diff_not_equals_complex_numbers) {
    // Arrange
    double re = 2;
    double im = 3;

    // Act
    ComplexNumber x(re, im);
    ComplexNumber y(re + 1, im + 1);

    // Assert
    EXPECT_NE(x.getRe(), y.getRe());
    EXPECT_NE(x.getIm(), y.getIm());
}
