// Copyright 2019 Valiullin Damir

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Valiullin_Damir_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Valiullin_Damir_ComplexNumberTest, Complex_numbers_are_equal) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(z);

    // Assert
    EXPECT_EQ(z, z1);
}

TEST(Valiullin_Damir_ComplexNumberTest, Can_multiply_by_zero) {
    // Arrange
    double re = 10.0;
    double im = 20.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(0.0, 0.0);

    // Assert
    EXPECT_EQ(z1, z*z1);
}

TEST(Valiullin_Damir_ComplexNumberTest, Can_not_divide_by_zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(10.0, 20.0);

    // Assert
    ASSERT_ANY_THROW(z1/z);
}

TEST(Valiullin_Damir_ComplexNumberTest, 
    Multiplying_by_one_gives_the_same_number) {
    // Arrange
    double re = 10.0;
    double im = 20.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(1.0, 0.0);

    // Assert
    EXPECT_EQ(z, z*z1);
}
