// Copyright 2019 Daria Koroleva

#include <gtest/gtest.h>
#include <limits>
#include "include/complex_number.h"

TEST(Koroleva_Daria_ComplexNumberTest, constructor_complexnumber_is_OK) 
{
	// Arrange
	ComplexNumber a(1., 143.);

	// Act
	ComplexNumber b(a);

	// Assert
	EXPECT_EQ(a, b);
}

TEST(Koroleva_Daria_ComplexNumberTest, can_divide_by_small_number)
{
	// Arrange
	const double eps = std::numeric_limits<double>::epsilon();
	ComplexNumber a(-32., 143.);
	ComplexNumber b(eps, eps);

	// Act
	// Assert
	ASSERT_NO_THROW(a/b);
}

TEST(Koroleva_Daria_ComplexNumberTest, cant_divide_by_zero)
{
	// Arrange
	ComplexNumber a(-32., 24.);
	ComplexNumber b(0., 0.);

	// Act
	// Assert
	ASSERT_ANY_THROW(a / b);
}

TEST(Koroleva_Daria_ComplexNumberTest, can_multiply_three_complex)
{
	// Arrange
	ComplexNumber a(-32., 24.);
	ComplexNumber b(0., -12.);
	ComplexNumber c(-12., 12.);

	// Act
	ComplexNumber res = a * b * c;

	// Assert
	EXPECT_EQ(-8064, res.getRe());
	EXPECT_EQ(-1152, res.getIm());
}
