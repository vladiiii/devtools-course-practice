// Copyright 2019 Valiullin Damir

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Valiullin_Damir_ComplexNumberTest, Can_Create_Zero) {
	// Arrange
	double re = 0.0;
	double im = 0.0;

	// Act
	ComplexNumber z(re, im);

	// Assert
	EXPECT_EQ(re, z.getRe());
	EXPECT_EQ(im, z.getIm());
}

TEST(Valiullin_Damir_ComplexNumberTest, Complex_numbers_are_equal) {
	// Arrange
	double re = 0.0;
	double im = 0.0;

	// Act
	ComplexNumber z(re, im);
	ComplexNumber z1(z);

	// Assert
	EXPECT_EQ(z,z1);
}