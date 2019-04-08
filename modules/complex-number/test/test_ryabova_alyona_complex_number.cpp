// Copyright 2019 Ryabova Alyona

#include <gtest/gtest.h>

#include <string>

#include "include/complex_number.h"
#include "include/complex_calculator.h"

using std::string;

TEST(Ryabova_Alyona_ComplexNumberTest,
    Can_Create_Complex_With_Negative_Real_And_Imaginary) {
    // Arrange
    double re = -1.23;
    double im = -1.23;

     // Act
    ComplexNumber z(re, im);

     // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Ryabova_Alyona_ComplexNumberTest, Can_Set_Negative_Real) {
    // Arrange
    double re = -1.23;

     // Act
    ComplexNumber z;
    z.setRe(re);

     // Assert
    EXPECT_EQ(re, z.getRe());
}

TEST(Ryabova_Alyona_ComplexNumberTest, Can_Set_Negative_Imaginary) {
    // Arrange
    double im = -1.23;

     // Act
    ComplexNumber z;
    z.setIm(im);

     // Assert
    EXPECT_EQ(im, z.getIm());
}

TEST(Ryabova_Alyona_ComplexNumberTest, Can_Add_Some_Complex) {
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

TEST(Ryabova_Alyona_ComplexNumberTest, Can_Difference_Some_Complex) {
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
