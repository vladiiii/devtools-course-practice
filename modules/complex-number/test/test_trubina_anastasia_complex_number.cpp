// Copyright 2019 Trubina Anastasia

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Trubina_Anastasia_ComplexNumberTest, Property_Of_The_Imaginary_Unit) {
	// Arrange
	ComplexNumber i(0, 1.0);
	ComplexNumber a(-1.0, 0);
	bool res;

	//Act
	res = a == i * i;

	//Assert
	ASSERT_TRUE(res);
}

TEST(Trubina_Anastasia_ComplexNumberTest, Correctness_Of_Operation_Set) {
	// Arrange
	ComplexNumber res();

	// Act
	res.setRe(2.3);
	res.setIm(4.7);

	// Assert
	EXPECT_FLOAT_EQ(2.3, res.getRe());
	EXPECT_FLOAT_EQ(4.7, res.getIm());
}
