// Copyright 2019 Trykin Alexander

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Trykin_Alexander_ComplexNumberTest, Can_Divide_By_Re_One) {
    // Arrange
    ComplexNumber z(12.4, 51);
    ComplexNumber one(1, 0);

    // Act
    z = z / one;

    // Assert
    ComplexNumber expected_z(12.4, 51);
    EXPECT_EQ(expected_z, z);
}

TEST(Trykin_Alexander_ComplexNumberTest, Can_Divide_By_Im_One) {
    // Arrange
    ComplexNumber z(5.4, 5.2);
    ComplexNumber one(0, 1);

    // Act
    z = z / one;

    // Assert
    ComplexNumber expected_z(5.2, -5.4);
    EXPECT_EQ(expected_z, z);
}

