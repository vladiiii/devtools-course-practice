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

TEST(Timakin_Nikita_ComplexNumberTest, Can_Get_Imaginary) {
    // Arrange
    ComplexNumber z(1.0, 2.0);

    // Act
    double im = z.getIm();

    // Assert
    EXPECT_EQ(2.0, im);
}

TEST(Timakin_Nikita_ComplexNumberTest, Copy_Constructor_Returns_Copy) {
    // Arrange
    ComplexNumber z(1.0, 2.0);

    // Act
    ComplexNumber z_copy(z);

    // Assert
    EXPECT_EQ(z, z_copy);
}

TEST(Timakin_Nikita_ComplexNumberTest, Addidng_Zero_Does_Not_Change_Number) {
    // Arrange
    ComplexNumber z(1.0, 2.0);

    // Act
    ComplexNumber the_same_z = z + ComplexNumber(0, 0);

    // Assert
    EXPECT_EQ(z, the_same_z);
}

TEST(Timakin_Nikita_ComplexNumberTest, Multiplication_By_Zero_Returns_Zero) {
    // Arrange
    ComplexNumber z(1.0, 2.0);
    ComplexNumber zero(0, 0);

    // Act
    z = z * zero;

    // Assert
    EXPECT_EQ(z, zero);
}

TEST(Timakin_Nikita_ComplexNumberTest, Difference_By_Itself_Equals_Zero) {
    // Arrange
    ComplexNumber z(1.0, 2.0);
    ComplexNumber zero(0, 0);

    // Act
    ComplexNumber diff_result = z - z;

    // Assert
    EXPECT_EQ(diff_result, zero);
}
