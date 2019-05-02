// Copyright 2019 Ryabova Alyona

#include <gtest/gtest.h>

#include <string>

#include "include/complex_number.h"
#include "include/complex_calculator.h"

using std::string;

TEST(Ryabova_Alyona_ComplexNumberTest,
    No_Throw_When_Set_Negative_Real_And_Imaginary) {
    // Arrange
    double re = -1.23;
    double im = -1.23;
    ComplexNumber z;

    // Act & Assert
    ASSERT_NO_THROW(z.setRe(re));
    ASSERT_NO_THROW(z.setIm(im));
}

TEST(Ryabova_Alyona_ComplexNumberTest, Correct_Division_By_Itself) {
    // Arrange
    ComplexNumber z1(2.0, 3.0);

    // Act
    ComplexNumber z = z1 / z1;

    // Assert
    ComplexNumber expected_z(1.0, 0.0);
    EXPECT_EQ(expected_z, z);
}

TEST(Ryabova_Alyona_ComplexNumberTest, Can_Multiply_Complex_Twice) {
    // Arrange
    ComplexNumber z1(1.0, 3.0);
    ComplexNumber z2(3.0, 2.0);
    ComplexNumber z3(2.0, 2.0);

    // Act
    ComplexNumber z = z1 * z2 * z3;

    // Assert
    ComplexNumber expected_z(-28.0, 16.0);
    EXPECT_EQ(expected_z, z);
}

TEST(Ryabova_Alyona_ComplexNumberTest, Can_Add_Complex_Twice) {
    // Arrange
    ComplexNumber z1(1.0, 3.0);
    ComplexNumber z2(1.0, 7.0);
    ComplexNumber z3(2.0, 2.0);

    // Act
    ComplexNumber z = z1 + z2 + z3;

    // Assert
    ComplexNumber expected_z(4.0, 12.0);
    EXPECT_EQ(expected_z, z);
}

TEST(Ryabova_Alyona_ComplexNumberTest, Can_Difference_Complex_Twice) {
    // Arrange
    ComplexNumber z1(10.0, 5.0);
    ComplexNumber z2(1.0, 3.0);
    ComplexNumber z3(5.0, 2.0);

    // Act
    ComplexNumber z = z1 - z2 - z3;

    // Assert
    ComplexNumber expected_z(4.0, 0.0);
    EXPECT_EQ(expected_z, z);
}
