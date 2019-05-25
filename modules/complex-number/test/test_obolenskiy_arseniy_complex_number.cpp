// Copyright 2019 Obolenskiy Arseniy

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Obolenskiy_Arseniy_ComplexNumberTest,
                    Subtraction_Of_The_Same_Number_Gives_Zero) {
    // Arrange
    ComplexNumber a(7., 14.);

    // Act
    ComplexNumber c = a - a;

    // Assert
    EXPECT_EQ(0, c.getRe());
    EXPECT_EQ(0, c.getIm());
}

TEST(Obolenskiy_Arseniy_ComplexNumberTest,
                    Can_Combine_Multiplication_And_Addition) {
    // Arrange
    ComplexNumber a(7., 14.), b(9., 10.), c(2., 3.);

    // Act
    ComplexNumber d = a + b * c;

    // Assert
    EXPECT_EQ(-5., d.getRe());
    EXPECT_EQ(61., d.getIm());
}

TEST(Obolenskiy_Arseniy_ComplexNumberTest, Can_Create_Via_Copy_Constructor) {
    // Arrange
    const ComplexNumber a(7., 14.);

    // Act
    ComplexNumber b(a);

    // Assert
    EXPECT_EQ(a, b);
}

TEST(Obolenskiy_Arseniy_ComplexNumberTest, Cannot_Divide_By_Zero) {
    // Arrange
    const ComplexNumber a(7., 14.), b(8., 9.), c(b);

    // Act & Assert
    EXPECT_ANY_THROW(a / (b - c));
}

TEST(Obolenskiy_Arseniy_ComplexNumberTest, Can_Plus_And_Assign_To_Itself) {
    // Arrange
    ComplexNumber a(7., 14.);

    // Act
    a = a + a;

    // Assert
    EXPECT_EQ(ComplexNumber(14., 28.), a);
}
