// Copyright 2019 Yury Gaydaychuk

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Gaydaychuk_Yury_ComplexNumberTest, Can_Multiple_One) {
    // Arrange
	ComplexNumber z1(1.0, 0.0);
    ComplexNumber z2(22.33, 22.33);

    // Act
    ComplexNumber z3 = z1 * z2;

    // Assert
    EXPECT_EQ(z2, z3);
}

TEST(Gaydaychuk_Yury_ComplexNumberTest, Solve_General_Equation) {
    // Arrange
    ComplexNumber im_one(0.0, 1.0);
    ComplexNumber minus_one(-1.0, 0.0);

    // Act
    ComplexNumber z = im_one * im_one;

    // Assert
    EXPECT_EQ(minus_one, z);
}
