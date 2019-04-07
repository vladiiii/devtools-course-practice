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
	EXPECT_EQ(17.0, res.getRe());
	EXPECT_EQ(-1.0, res.getIm());
}

TEST(Soluyanov_Alexsey_ComplexNumberTest, FalseComparingDiffComplNum) {
	// Arrange
	ComplexNumber z1(0.0, 0.1);
	ComplexNumber z2(0.0, 0.0);
	// Act

	// Assert
	EXPECT_FALSE(z1 == z2);
}

TEST(Soluyanov_Alexsey_ComplexNumberTest, TrueComparingEQComplNum) {
	// Arrange
	ComplexNumber z1(3.0, 2.0);
	ComplexNumber z2(1.0, -1.0);
	ComplexNumber res;
	// Act
	res = z1 / z2;
	res = res * z2;

	// Assert
	EXPECT_TRUE(res == z1);
}

TEST(Soluyanov_Alexsey_ComplexNumberTest, EQResultsSeveralAct) {
	// Arrange
	ComplexNumber z1(3.0, 2.0);
	ComplexNumber z2(1.0, -1.0);
	ComplexNumber z3(0.0, 1.0);
	ComplexNumber z4(1.0, 2.0);
	ComplexNumber res;
	// Act
	res = z4 * z3 - (z1 / z2);

	// Assert
	EXPECT_EQ(-2.5, res.getRe());
	EXPECT_EQ(-1.5, res.getIm());
}

TEST(Soluyanov_Alexsey_ComplexNumberTest, EQ_Add_and_mult) {
	// Arrange
	ComplexNumber z1(1.5, 2.0);
	ComplexNumber z2(4.5, 6.0);
	ComplexNumber res1, res2;
	// Act
	res1 = z1 + z1;
	res2 = z2 - z1;
	// Assert
	EXPECT_TRUE(res1.getRe() == res2.getRe());
	EXPECT_TRUE(res1.getIm() == res2.getIm());
}
