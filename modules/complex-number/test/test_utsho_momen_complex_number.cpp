// Copyright 2019 Utsho Momen 

#include <gtest/gtest.h> 

#include "include/complex_number.h" 

TEST(Utsho_Momen_ComplexNumberTest, Can_Create_Zero) {
	// Arrange
	double re = 0.0;
	double im = 0.0;

	// Act
	ComplexNumber с3(re, im);

	// Assert
	EXPECT_EQ(re, с3.getRe());
	EXPECT_EQ(im, с3.getIm());
}

TEST(Utsho_Momen_ComplexNumberTest, Multiplication_With_Two_Numbers) {
	// Arrange 
	ComplexNumber c1(5.0, 3.0);
	ComplexNumber c2(4.0, 6.0);

	// Act
	ComplexNumber c3 = c1 * c2;

	// Assert
	EXPECT_EQ(2, c3.getRe());
	EXPECT_EQ(42, c3.getIm());

}

TEST(Utsho_Momen_ComplexNumberTest, Adding_Two_Numbers) {
	// Arrange 
	ComplexNumber c1(1.0, 3.0);
	ComplexNumber c2(4.0, 6.0);

	// Act
	ComplexNumber c3 = c1 + c2;

	// Assert 
	EXPECT_EQ(5, c3.getRe());
	EXPECT_EQ(9, c3.getIm());
}

TEST(Utsho_Momen_ComplexNumberTest, Substracting_Number) {
	// Arrange 
	ComplexNumber c1(1.0, 3.0);
	ComplexNumber c2(4.0, 6.0);

	// Act
	ComplexNumber c3 = c1 - c2;

	// Assert 
	EXPECT_EQ(-3, c3.getRe());
	EXPECT_EQ(-3, c3.getIm());
}

TEST(Utsho_Momen_ComplexNumberTest, Dividing_Two_Number) {
	// Arrange 
	ComplexNumber c1(4.0, 6.0);
	ComplexNumber c2(2.0, 3.0);

	// Act
	ComplexNumber c3 = c1 / c2;

	// Assert 
	EXPECT_EQ(2, c3.getRe());
	EXPECT_EQ(0, c3.getIm());
}
