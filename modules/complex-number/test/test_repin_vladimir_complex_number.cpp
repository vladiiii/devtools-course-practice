// Copyright 2019 Repin Vladimir

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Repin_Vladimir_ComplexNumberTest, throws_on_division_by_zero) {
    // Arrange
    double re1 = 0.0;
    double im1 = 0.0;
    double re2 = 1.0;
    double im2 = 1.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);


    // Assert

    ASSERT_ANY_THROW(z2 / z1);
}

TEST(Repin_Vladimir_ComplexNumberTest, comparing_with_itself_is_correct) {
    // Arrange
    double re = 3.0;
    double im = 7.0;


    // Act
    ComplexNumber z(re, im);


    // Assert

    EXPECT_EQ(true, z == z);
}

TEST(Repin_Vladimir_ComplexNumberTest, multiplying_is_correct) {
    // Arrange
    double re1 = 3.0;
    double im1 = 7.0;

    double re2 = 7.0;
    double im2 = 3.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber res = z1*z2;

    // Assert

    EXPECT_EQ(0.0, res.getRe());
    EXPECT_EQ(58.0, res.getIm());
}

TEST(Repin_Vladimir_ComplexNumberTest, assign_is_correct) {
    // Arrange
    double re = 11.0;
    double im = 2.0;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2;
    z2 = z1;

    // Assert

    EXPECT_EQ(z1.getRe(), z2.getRe());
    EXPECT_EQ(z1.getIm(), z2.getIm());
}
