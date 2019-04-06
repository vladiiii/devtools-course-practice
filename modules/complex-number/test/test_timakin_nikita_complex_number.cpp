// Copyright 2019 Timakin Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Timakin_Nikita_ComplexNumberTest, Default_Equals_Zero) {
    // Arrange
    ComplexNumber zero(0.0, 0.0);

    // Act
    ComplexNumber z;

    // Assert
    EXPECT_EQ(z, zero);
}

TEST(Timakin_Nikita_ComplexNumberTest, Can_Get_Real) {
    // Arrange
    ComplexNumber z(1.0, 2.0);

    // Act
    double real = z.getRe();

    // Assert
    EXPECT_EQ(1.0, real);
}
