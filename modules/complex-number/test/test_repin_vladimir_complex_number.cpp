// Copyright 2019 Repin Vladimir

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Repin_Vladimir_ComplexNumberTest, can_get_zero_by_sum) {
    // Arrange
    double re1 = 3.0;
    double im1 = 2.0;
    double re2 = -3.0;
    double im2 = -2.0;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    ComplexNumber expected_z(0.0, 0.0);
    EXPECT_EQ(expected_z, z);
}

TEST(Repin_Vladimir_ComplexNumberTest, can_get_one_by_division) {
    // Arrange
    double re1 = 3.0;
    double im1 = 7.0;
    double re2 = 3.0;
    double im2 = 7.0;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber z = z1 / z2;

    // Assert
    ComplexNumber expected_z(1.0, 0.0);
    EXPECT_EQ(expected_z, z);
}

TEST(Repin_Vladimir_ComplexNumberTest, multiple_assign_is_correct) {
    // Arrange
    double re = 3.0;
    double im = 7.0;
    ComplexNumber z(re, im);
    ComplexNumber z1, z2;

    // Act
    z2 = z1 = z;

    // Assert
    ComplexNumber expected_z(3.0, 7.0);
    EXPECT_EQ(expected_z, z1);
    EXPECT_EQ(expected_z, z2);
}

TEST(Repin_Vladimir_ComplexNumberTest, sum_operands_stay_unchanged) {
    // Arrange
    double re1 = 3.0;
    double im1 = 7.0;
    double re2 = 3.0;
    double im2 = 7.0;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber z = z1 + z2;
    z = z;
    // Assert
    ComplexNumber expected_z1(3.0, 7.0);
    ComplexNumber expected_z2(3.0, 7.0);
    EXPECT_EQ(expected_z1, z1);
    EXPECT_EQ(expected_z2, z2);
}

TEST(Repin_Vladimir_ComplexNumberTest, division_operands_stay_unchanged) {
    // Arrange
    double re1 = 3.0;
    double im1 = 7.0;
    double re2 = 3.0;
    double im2 = 7.0;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act

    ComplexNumber z = z1 / z2;
    z = z;

    // Assert
    ComplexNumber expected_z1(3.0, 7.0);
    ComplexNumber expected_z2(3.0, 7.0);
    EXPECT_EQ(expected_z1, z1);
    EXPECT_EQ(expected_z2, z2);
}
