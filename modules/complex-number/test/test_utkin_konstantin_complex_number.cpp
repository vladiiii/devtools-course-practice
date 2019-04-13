// Copyright 2017 Korniakov Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Utkin_Konstantin_ComplexNumberTest, Cant_Divide_By_Zero) {
    // Arrange
    ComplexNumber z1(5.9, 10.9);
    ComplexNumber z2(-5.9, -10.9);
    ComplexNumber z3(-3.0, -3.0);
    
    // Act & Assert
    EXPECT_ANY_THROW(z3/(z1+z2));
}

TEST(Utkin_Konstantin_ComplexNumberTest, Can_Add_Several_Complex_Numbers) {
    // Arrange
    ComplexNumber z1(105.3, -220.6);
    ComplexNumber z2(-100.0, 200.0);
    ComplexNumber z3(-5.3, 20.6);
    ComplexNumber exp_z(0.0, 0.0);
    
    // Act
    ComplexNumber res_z = z1 + z2 + z3;
    
    // Assert
    EXPECT_EQ(exp_z, res_z);
}
