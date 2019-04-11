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


TEST(Trubina_Anastasia_ComplexNumberTest, Are_Reciprocal_Complex_Number) {
	//Arrange
	ComplexNumber dir(3.0, 4.0);

	//Act
	ComplexNumber rec(dir.getRe() / (dir.getRe() * dir.getRe() + dir.getIm() * dir.getIm()),
		              dir.getIm() / (dir.getRe() * dir.getRe() + dir.getIm() * dir.getIm()));

	//Assert
	EXPECT_FLOAT_EQ(0.12, rec.getRe());
	EXPECT_FLOAT_EQ(0.16, rec.getIm());
}