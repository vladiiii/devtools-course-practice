// Copyright 2019 Valiullin Damir

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Valiullin_Damir_ComplexNumberTest, Can_Create_Only_Re) {
    // Arrange
    double re = 1.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Valiullin_Damir_ComplexNumberTest, Can_Create_Only_Im) {
    // Arrange
    double re = 0.0;
    double im = 1.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Valiullin_Damir_ComplexNumberTest, Can_Multiply_By_Zero) {
    // Arrange
    double re = 10.0;
    double im = 20.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(0.0, 0.0);

    // Assert
    EXPECT_EQ(z1, z*z1);
}

TEST(Valiullin_Damir_ComplexNumberTest, Div_By_One_Gives_The_Same_Number) {
    // Arrange
    double re = 10.0;
    double im = 20.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(1.0, 0.0);

    // Assert
    EXPECT_EQ(z, z/z1);
}

TEST(Valiullin_Damir_ComplexNumberTest, Mult_By_One_Gives_The_Same_Number) {
    // Arrange
    double re = 10.0;
    double im = 20.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(1.0, 0.0);

    // Assert
    EXPECT_EQ(z, z*z1);
}
