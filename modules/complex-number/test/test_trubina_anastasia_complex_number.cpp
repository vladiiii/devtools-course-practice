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

TEST(Trubina_Anastasia_ComplexNumberTest, Are_Additive_Inverse_Complex_Numbers) {
	//Arrange
	ComplexNumber dir(1.0, 1.0);
	ComplexNumber inv(-1.0, -1.0);
	ComplexNumber res(0.0, 0.0);
	bool result;

	//Act
	result = res == dir + inv;

	//Assert
	ASSERT_TRUE(result);
}