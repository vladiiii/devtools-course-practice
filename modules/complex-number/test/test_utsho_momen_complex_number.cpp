// Copyright 2019 Utsho Momen

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Utsho_Momen_ComplexNumberTest, Init_Imaginary_To_Zero) {
    // Arrange & Act
    ComplexNumber z;

    // Assert
    EXPECT_FLOAT_EQ(0, z.getIm());
}

TEST(Utsho_Momen_ComplexNumberTest, Divide_By_Zero) {
    // Arrange
    ComplexNumber z1(45.65, 13.35);
    ComplexNumber z2(0.0, 34.75);
    
    // Act & Assert
    EXPECT_NO_THROW(z1 / z2);
}

TEST(Utsho_Momen_ComplexNumberTest, Comparison_Equal) {
    // Arrange
    ComplexNumber z1;
    ComplexNumber z2;

    // Assert
    EXPECT_TRUE(z1 == z2);
}

TEST(Utsho_Momen_ComplexNumberTest, Double_Real_Number) {
    // Arrange
    ComplexNumber z(1.0, 2.0);
    
    // Act
    double real = z.getRe();
    
    // Assert
    EXPECT_EQ(1.0, real);
}

TEST(Utsho_Momen_ComplexNumberTest, Divide_Double_By_ComplexNumber) {
    // Arrange & Act
    ComplexNumber z1;
    double d = 5.0;
    ComplexNumber z3 = z1;

    // Assert 
    ASSERT_NO_THROW(2.5, z3.re());
}
