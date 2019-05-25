// Copyright 2019 Savkin Yuriy

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Savkin_Yuriy_ComplexNumberTest,
     Dividing_By_Same_Number_Give_1) {
    // Arrange
    double re = 5.8;
    double im = 28.1;
    ComplexNumber x(re, im);
    ComplexNumber y(1.0, 0.0);

    // Act
    ComplexNumber z = x / x;

    // Assert
    EXPECT_TRUE(y == z);
}

TEST(Savkin_Yuriy_ComplexNumberTest,
     Multiplication_By_Imaginary_One_Works_Correctly) {
    // Arrange
    double d1 = 5.8;
    double d2 = 28.1;
    ComplexNumber x(d1, d2);
    ComplexNumber y(-d2, d1);
    ComplexNumber z(0.0, 1.0);

    // Act
    ComplexNumber w = x * z;

    // Assert
    EXPECT_TRUE(y == w);
}

TEST(Savkin_Yuriy_ComplexNumberTest,
     Adding_To_Real_Part_Do_Not_Change_Imaginary) {
    // Arrange
    double d1 = 5.8;
    double d2 = 28.1;
    double d3 = 95.1;
    ComplexNumber x(d1, d2);
    ComplexNumber y(d3, 0.0);

    // Act
    ComplexNumber z = x + y;

    // Assert
    EXPECT_EQ(28.1, z.getIm());
}

TEST(Savkin_Yuriy_ComplexNumberTest,
     Adding_To_Imaginary_Part_Do_Not_Change_Real) {
    // Arrange
    double d1 = 5.8;
    double d2 = 28.1;
    double d3 = 95.1;
    ComplexNumber x(d1, d2);
    ComplexNumber y(0.0, d3);

    // Act
    ComplexNumber z = x + y;

    // Assert
    EXPECT_EQ(5.8, z.getRe());
}

TEST(Savkin_Yuriy_ComplexNumberTest,
     Multiplication_By_Real_One_Works_Correctly) {
    // Arrange
    double d1 = 5.8;
    double d2 = 28.1;
    ComplexNumber x(d1, d2);
    ComplexNumber y(1.0, 0.0);

    // Act
    ComplexNumber z = x * y;

    // Assert
    EXPECT_TRUE(x == z);
}

TEST(Savkin_Yuriy_ComplexNumberTest,
     Dividing_By_1_Give_Same_Number) {
    // Arrange
    double re = 5.8;
    double im = 28.1;
    ComplexNumber x(re, im);
    ComplexNumber y(1.0, 0.0);

    // Act
    ComplexNumber z = x / y;

    // Assert
    EXPECT_TRUE(x == z);
}
