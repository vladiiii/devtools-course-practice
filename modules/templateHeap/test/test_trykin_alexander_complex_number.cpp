// Copyright 2019 Trykin Alexander

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Trykin_Alexander_ComplexNumberTest, Can_Divide_By_Re_One) {
    // Arrange
    ComplexNumber z(12.4, 51);
    ComplexNumber re_one(1.0, 0.0);

    // Act
    ComplexNumber res = z / re_one;

    // Assert
    ComplexNumber expected_res(12.4, 51.0);
    EXPECT_EQ(expected_res, res);
}

TEST(Trykin_Alexander_ComplexNumberTest, Can_Divide_By_Im_One) {
    // Arrange
    ComplexNumber z(5.4, 5.2);
    ComplexNumber im_one(0.0, 1.0);

    // Act
    ComplexNumber res = z / im_one;

    // Assert
    ComplexNumber expected_res(5.2, -5.4);
    EXPECT_EQ(expected_res, res);
}

TEST(Trykin_Alexander_ComplexNumberTest, Can_Multiply_By_Re_One) {
    // Arrange
    ComplexNumber z(-2.9, -4.8);
    ComplexNumber re_one(1.0, 0.0);

    // Act
    ComplexNumber res = z * re_one;

    // Assert
    ComplexNumber expected_res(-2.9, -4.8);
    EXPECT_EQ(expected_res, res);
}

TEST(Trykin_Alexander_ComplexNumberTest, Can_Multiply_By_Im_One) {
    // Arrange
    ComplexNumber z(-12.3, 10.1);
    ComplexNumber im_one(0.0, 1.0);

    // Act
    ComplexNumber res = z * im_one;

    // Assert
    ComplexNumber expected_res(-10.1, -12.3);
    EXPECT_EQ(expected_res, res);
}

TEST(Trykin_Alexander_ComplexNumberTest, Multiply_By_Conjugate_Gives_Radius) {
    // Arrange
    ComplexNumber z1(5.0, 2.0);
    ComplexNumber z2(5.0, -2.0);

    // Act
    ComplexNumber res = z1 * z2;

    // Assert
    double radius = z1.getRe() * z1.getRe() + z2.getIm() * z2.getIm();
    EXPECT_FLOAT_EQ(radius, res.getRe());
}
