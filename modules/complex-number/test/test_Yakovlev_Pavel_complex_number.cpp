// Copyright 2019 Yakovlev Pavel

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Yakovlev_Pavel_ComplexNumberTest, sum_sub_test) {
    // Arrange
	ComplexNumber z1(3.0, 2.0);
	ComplexNumber z2(z1);
    // Act
	ComplexNumber res = z1 - z2;
    // Assert
    EXPECT_DOUBLE_EQ(0.0, res.getRe());
    EXPECT_DOUBLE_EQ(0.0, res.getIm());
}

TEST(Yakovlev_Pavel_ComplexNumberTest, div_number_by_imaginary_unit) {
    // Arrange
    ComplexNumber z1(3.0, 2.0);
    ComplexNumber z2(0.0, 1.0);
    // Act
    ComplexNumber res = z1 / z2;
    // Assert
    EXPECT_DOUBLE_EQ(2.0, res.getRe());
	EXPECT_DOUBLE_EQ(-3.0, res.getIm());
}

TEST(Yakovlev_Pavel_ComplexNumberTest, test_set_function) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    // Act
    z1.setRe(3.0);
	z1.setIm(2.0);
    // Assert
    EXPECT_DOUBLE_EQ(3.0, z1.getRe());
    EXPECT_DOUBLE_EQ(2.0, z1.getIm());
}

TEST(Yakovlev_Pavel_ComplexNumberTest, test_compare_functions) {
    // Arrange
    ComplexNumber z1(3.0, 2.0);
	ComplexNumber z2(3.0, 2.0);
    // Act
    // Assert
    EXPECT_NE(false, z1 == z2);
    EXPECT_NE(true, z1 != z2);
}

TEST(Yakovlev_Pavel_ComplexNumberTest, test_complex_assignment) {
    // Arrange
    ComplexNumber z1(3.0, 2.0);
	ComplexNumber z2();
	ComplexNumber z3();
    // Act
	z3 = z2 = z1;
    // Assert
    EXPECT_EQ(true, z1 == z2);
    EXPECT_EQ(true, z1 == z3);
}
