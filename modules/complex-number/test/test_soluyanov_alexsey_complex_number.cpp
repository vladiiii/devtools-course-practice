// Copyright 2019 Soluyanov Alexsey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Soluyanov_Alexsey_ComplexNumberTest, ComplexNumberMultiplication) {
    // Arrange
    ComplexNumber z1(3.0, 1.0);
    ComplexNumber z2(5.0, -2.0);
    ComplexNumber res;
    // Act
    res = z1 * z2;

    // Assert
    EXPECT_EQ(16.0, res.getRe() + res.getIm());
}

TEST(Soluyanov_Alexsey_ComplexNumberTest, FalseComparingDiffComplNum) {
    // Arrange
    ComplexNumber z1(0.0, 0.1);
    ComplexNumber z2(0.0, 0.0);
    // Act

    // Assert
    EXPECT_FALSE(z1 == z2);
}

TEST(Soluyanov_Alexsey_ComplexNumberTest, Division_ComplNumber) {
    // Arrange
    ComplexNumber z1(3.0, 2.0);
    ComplexNumber z2(1.0, 1.0);
    ComplexNumber res;
    // Act
    res = z1 / z2;

    // Assert
    EXPECT_EQ(2.5, res.getRe());
}

TEST(Soluyanov_Alexsey_ComplexNumberTest, EQ_Copy_Variables) {
    // Arrange
    ComplexNumber z1(3.0, 2.0);
    // Act
    ComplexNumber compl_copy(z1);

    // Assert
    EXPECT_EQ(z1, compl_copy);
}

TEST(Soluyanov_Alexsey_ComplexNumberTest, EQ_Addition_ComplNum) {
    // Arrange
    ComplexNumber z1(1.5, 2.0);
    ComplexNumber z2(4.5, 6.0);
    ComplexNumber res;
    // Act
    res = z1 + z2;
    // Assert
    EXPECT_EQ(8.0, res.getIm());
}
