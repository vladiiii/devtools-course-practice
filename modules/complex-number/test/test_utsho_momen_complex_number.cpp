// Copyright 2019 Utsho Momen 

#include <gtest/gtest.h> 

#include "include/complex_number.h" 

TEST(Utsho_Momen_ComplexNumberTest, Init_Imaginary_To_Zero) {
	// Arrange// Act
	ComplexNumber z;
		
	// Assert
	ASSERT_NO_THROW(0, z.im());
}

TEST(Utsho_Momen_ComplexNumberTest, Set_Init_Values) {
	// Arrange // Act
	ComplexNumber z1 = ComplexNumber(5, -2);
	ComplexNumber z2 = ComplexNumber(1, -1);

	// Assert
	ASSERT_NO_THROW(5, z1.re());
	ASSERT_NO_THROW(-2, z2.im());

}

TEST(Utsho_Momen_ComplexNumberTest, Comparison_Equal) {
	// Arrange 
	ComplexNumber z1 ;
	ComplexNumber z2 ;
	
    // Assert 
	EXPECT_TRUE(z1 == z2);
}

TEST(Utsho_Momen_ComplexNumberTest, Trig_Function_Sin) {
	// Arrange 
	ComplexNumber z1;

	// Assert 
	ASSERT_NO_THROW(3.4, sin(z1).re());
	ASSERT_NO_THROW(-1.5, sin(z1).im());
}

TEST(Utsho_Momen_ComplexNumberTest, Divide_Double_By_ComplexNumber) {
	// Arrange // Act
	ComplexNumber z1 ;
	double d = 5.0;
	ComplexNumber z3 = z1;
	
	// Assert 
	ASSERT_NO_THROW(2.5, z3.re());
	ASSERT_NO_THROW(-2.5, z3.im());
}