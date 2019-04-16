// Copyright 2019 Vorobev Pavel

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Vorobev_Pavel_ComplexNumberTest, Can_Check_Equality) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber y(re, im);

    // Assert
    EXPECT_EQ(true, z == y);
}

TEST(Vorobev_Pavel_ComplexNumberTest, Can_Add_Two_Numbers) {
    // Act
    ComplexNumber x(1.0, 2.0);
    ComplexNumber y(2.0, 3.0);
    ComplexNumber z = x + y;

    // Assert
    EXPECT_EQ(3.0, z.getRe());
    EXPECT_EQ(5.0, z.getIm());
}

TEST(Vorobev_Pavel_ComplexNumberTest, Can_Substract_Two_Numbers) {
    // Act
    ComplexNumber x(11.0, 12.0);
    ComplexNumber y(3.0, 5.0);
    ComplexNumber z = x - y;

    // Assert
    EXPECT_EQ(8.0, z.getRe());
    EXPECT_EQ(7.0, z.getIm());
}

TEST(Vorobev_Pavel_ComplexNumberTest, Can_Check_Inequality) {
    // Act
    ComplexNumber x(1.0, 12.0);
    ComplexNumber y(4.0, 7.0);

    // Assert
    EXPECT_EQ(true, x != y);
}

TEST(Vorobev_Pavel_ComplexNumberTest, Can_Multiply_Two_Numbers) {
    // Act
    ComplexNumber x(1.0, 1.0);
    ComplexNumber y(3.0, 5.0);
    ComplexNumber z = x * y;

    // Assert
    EXPECT_EQ(-2, z.getRe());
    EXPECT_EQ(8, z.getIm());
}
