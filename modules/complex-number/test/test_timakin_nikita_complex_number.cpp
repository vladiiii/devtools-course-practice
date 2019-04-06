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
