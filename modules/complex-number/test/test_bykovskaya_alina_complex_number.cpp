// Copyright 2019 Bykovskaya Alina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Bykovskaya_Alina_ComplexNumberTest, Can_Assign_Complex) {
    // Arrange
    ComplexNumber a(2., 3.), b(4., 5.);

    // Act
    b = a;

    // Assert
    EXPECT_EQ(true, a == b);
}

TEST(Bykovskaya_Alina_ComplexNumberTest, Can_Assign_To_Itself) {
    // Arrange
    ComplexNumber a(3.0, 4.5);

    // Act & Assert
    ASSERT_NO_THROW(a = a);
}
