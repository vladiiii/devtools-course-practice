// Copyright 2019 Yury Gaydaychuk

#include <gtest/gtest.h>

#include "include/complex_number.h"

// Multiplication on 1 must be precise
TEST(Gaydaychuk_Yury_ComplexNumberTest, Precise_One_Multiplication) {
    // Arrange
    ComplexNumber z1(1.0, 0.0);
    ComplexNumber z2(22.33, 22.33);

    // Act
    ComplexNumber z3 = z1 * z2;

    // Assert
    EXPECT_EQ(z2, z3);
}

// Satisfiying additional group equation
TEST(Gaydaychuk_Yury_ComplexNumberTest, Precise_Solve_General_Equation) {
    // Arrange
    ComplexNumber im_one(0.0, 1.0);
    ComplexNumber minus_one(-1.0, 0.0);

    // Act
    ComplexNumber z = im_one * im_one;

    // Assert
    EXPECT_EQ(minus_one, z);
}

// Adding of negative z must be precise
TEST(Gaydaychuk_Yury_ComplexNumberTest, Precisly_Satisfy_Algebraic_Rule) {
    // Arrange
    ComplexNumber z1(-12.34, -56.78);
    ComplexNumber z_negative(12.34, 56.78);
    ComplexNumber z_nul(0.0, 0.0);

    // Act
    ComplexNumber z = z1 + z_negative;

    // Assert
    EXPECT_EQ(z, z_nul);
}
