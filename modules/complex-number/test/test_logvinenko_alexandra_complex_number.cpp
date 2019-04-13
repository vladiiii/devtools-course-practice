// Copyright 2019 Logvinenko Alexandra

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Logvinenko_Alexandra_ComplexNumberTest, Can_Сompare) {
    // Arrange
    bool result1, result2;
    ComplexNumber z1(1.2, 1.2);
    ComplexNumber z2(1.2, 1.2);
    ComplexNumber z3(21.2, 1.2);

    // Act
    result1 = (z1==z2);
    result2 = (z1==z3);

    // Assert
    EXPECT_EQ(true, result1);
    EXPECT_EQ(false, result2);
}

TEST(Logvinenko_Alexandra_ComplexNumberTest, Can_Summarize) {
    // Arrange
    ComplexNumber z1(1.2, 1.2);
    ComplexNumber z2(1.2, 1.2);

    // Act
    ComplexNumber z3 = z1+z2;

    // Assert
    EXPECT_EQ(2.4, z3.getRe());
    EXPECT_EQ(2.4, z3.getIm());
}

TEST(Logvinenko_Alexandra_ComplexNumberTest, Can_Subtract) {
	// Arrange
	ComplexNumber z1(2.4, 4.2);
	ComplexNumber z2(1.2, 2.1);

	// Act
	ComplexNumber z3 = z1 - z2;

	// Assert
	EXPECT_EQ(z2, z3);
}

TEST(Logvinenko_Alexandra_ComplexNumberTest, Can_Subtract2) {
	// Arrange
	ComplexNumber z1(3.2, 3.2);
	ComplexNumber z2(1.2, 1.2);

	// Act
	ComplexNumber z3 = z1 - z2;

	// Assert
	EXPECT_EQ(2.0, z3.getRe());
	EXPECT_EQ(2.0, z3.getIm());
}

TEST(Logvinenko_Alexandra_ComplexNumberTest, Can_Сreate_A_Copy) {
	// Arrange
	ComplexNumber z1(2.2, 3.2);

	// Act
	ComplexNumber z2(z1);

	// Assert
	EXPECT_EQ(2.2, z2.getRe());
	EXPECT_EQ(3.2, z2.getIm());
}