// Copyright 2019 Astafeva Irina

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Astafeva_Irina_ComplexNumberTest, Can_Create_Without_Parameters) {
    // Act & Assert
    ASSERT_NO_THROW(ComplexNumber{});
}

TEST(Astafeva_Irina_ComplexNumberTest, Calculates_By_Priority) {
    // Arrange
    ComplexNumber c1(5.0, 4.0);
    ComplexNumber c2(7.0, 3.0);
    ComplexNumber c3(9.0, 8.0);
    // Act
    ComplexNumber c4 = c1 + c2 * c3;
    // Assert
    ComplexNumber expected_c4(44.0, 87.0);
    ASSERT_EQ(c4, expected_c4);
}

TEST(Astafeva_Irina_ComplexNumberTest, Calculates_By_Difficult_Priority) {
    // Arrange
    ComplexNumber c1(5.0, 5.0);
    ComplexNumber c2(7.0, 3.0);
    ComplexNumber c3(9.0, 8.0);
    ComplexNumber c4(4.0, 8.0);
    // Act
    ComplexNumber c5 = (c1 + c2 * c3) / c4;
    // Assert
    ComplexNumber expected_c5(11.0, 0.0);
    ASSERT_EQ(c5, expected_c5);
}

TEST(Astafeva_Irina_ComplexNumberTest, Can_Divide_By_Itself) {
    // Arrange
    ComplexNumber c(5.0, 6.5);
    // Act & Assert
    ASSERT_NO_THROW(c / c);
}

TEST(Astafeva_Irina_ComplexNumberTest, Can_Multiply_By_Itself) {
    // Arrange
    ComplexNumber c(5.0, 6.5);
    // Act & Assert
    ASSERT_NO_THROW(c * c * c);
}
