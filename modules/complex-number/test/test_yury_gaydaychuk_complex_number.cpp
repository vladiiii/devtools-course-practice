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
