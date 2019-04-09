// Copyright 2019 Trykin Alexander

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Trykin_Alexander_ComplexNumberTest, Can_Divide_By_One) {
    // Arrange
    ComplexNumber z(12.4, 51);
    ComplexNumber one(1, 0);

    // Act
    z = z / one;

    // Assert
    ComplexNumber expected_z(12.4, 51);
    EXPECT_EQ(expected_z, z);
}

