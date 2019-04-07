// Copyright 2019 Shkerin Igor

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Shkerin_Igor_ComplexNumberTest, Can_Create_Zero) 
{
	// Arrange
	double re = 0.0;
	double im = 0.0;

	// Act
	ComplexNumber z(re, im);

	// Assert
	EXPECT_EQ(re, z.getRe());
	EXPECT_EQ(im, z.getIm());
}

//////////////////////////////////////////////////////////////////////////////

TEST(Shkerin_Igor_ComplexNumberTest, Can_Sum_Two_Complex_Numbers) 
{
	// Arrange
	double re1 = 1.0;
	double im1 = 2.0;

	double re2 = 4.0;
	double im2 = 5.0;

	// Act
	ComplexNumber z1(re1, im1);
	ComplexNumber z2(re2, im2);

	ComplexNumber z3 = z1 + z2;

	ComplexNumber expected_z3(5.0, 7.0);

	// Assert
	EXPECT_EQ(z3, expected_z3);
}

//////////////////////////////////////////////////////////////////////////////

TEST(Shkerin_Igor_ComplexNumberTest, Can_Multiplication_Complex_By_Zero) 
{
	// Arrange
	ComplexNumber z1(27.0, 11.0);
	ComplexNumber zero(0.0, 0.0);

	// Act
	ComplexNumber z3 = z1 * zero;

	ComplexNumber expected_z3(0.0, 0.0);

	// Assert
	EXPECT_EQ(z3, expected_z3);
}

//////////////////////////////////////////////////////////////////////////////

TEST(Shkerin_Igor_ComplexNumberTest, Throw_When_Multiplication_Complex_By_Zero)
{
	// Arrange
	ComplexNumber z1(27.0, 11.0);
	ComplexNumber zero(0.0, 0.0);

	// Act & Assert
	EXPECT_THROW(z1/zero, std::string);
}

//////////////////////////////////////////////////////////////////////////////

TEST(Shkerin_Igor_ComplexNumberTest, Copying_and_Direct_Equal_Initialize_Is_Equal)
{
	// Arrange
	double re1 = 1.0;
	double im1 = 2.0;

	ComplexNumber z1(re1, im1);
	ComplexNumber z2(1.0, 2.0);

	// Act & Assert
	EXPECT_EQ(z1, z2);
}