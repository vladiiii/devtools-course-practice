// Copyright 2019 Pinaev Danil

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Pinaev_Danil_ComplexNumberTest, can_create_complex_numbers) {
    // Assert
    ASSERT_NO_THROW(ComplexNumber a(1.0, 1.0));
}


TEST(Pinaev_Danil_ComplexNumberTest, can_add_complex_numbers) {
    // Arrange
    ComplexNumber a(1, -2);
    ComplexNumber b(3, -2);
    
    // Assert
    ASSERT_EQ(a+b, ComplexNumber(4,-4));
}


TEST(Pinaev_Danil_ComplexNumberTest, can_subtract_complex_numbers) {
    // Arrange
    ComplexNumber a(1, -2);
    ComplexNumber b(3, -2);

    // Assert
    ASSERT_EQ(a - b, ComplexNumber(-2, -0));
}


TEST(Pinaev_Danil_ComplexNumberTest, can_multiple_complex_numbers) {
    // Arrange
    ComplexNumber a(1, -2);
    ComplexNumber b(3, -2);

    // Assert
    ASSERT_EQ(a * b, ComplexNumber(-1, -8));
}

TEST(Pinaev_Danil_ComplexNumberTest, can_not_division_on_zero_complex_number) {
    // Arrange
    ComplexNumber a(1, -2);
    ComplexNumber b(0, 0);

    // Assert
    ASSERT_ANY_THROW(a / b);
}