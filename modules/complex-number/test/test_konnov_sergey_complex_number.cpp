// Copyright 2017 Konnov Sergey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Konnov_Sergey_ComplexNumberTest, Can_Multiply) {
    // Arrange
    ComplexNumber z1(3.0, 4.0);
    ComplexNumber z2(4.0, 5.0);

    // Act
    ComplexNumber z = z1*z2;

    // Assert
    ComplexNumber expected_z(-8.0, 31.0);
    EXPECT_EQ(expected_z, z);
}
