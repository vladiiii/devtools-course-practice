// Copyright 2019 Evdokimov Artem 

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Evdokimov_Artem_ComplexNumberTest, Copy_Has_Its_Own_Memory) {
    // Arrange 
    double re = 1.1;
    double im = 1.1;

    // Act 
    ComplexNumber a(re , im);
    ComplexNumber b(a);Ы

    // Assert 
    EXPECT_NE(&a , &b);
}

TEST(Evdokimov_Artem_ComplexNumberTest, Self_�omparison) {
    // Arrange 
    double re = 1.1;
    double im = 1.1;

    // Act 
    ComplexNumber a(re , im);

    // Assert 
    ASSERT_NO_THROW(a = a);
}

TEST(Evdokimov_Artem_ComplexNumberTest, Can_Create_Object_Without_Arguments) {
    // Arrange 
    double re = 0.0;
    double im = 0.0;

    //Act 
    ComplexNumber a(re , im);
    ComplexNumber b;

    //Assert 
    ASSERT_NO_THROW(a , b);
}

TEST(Evdokimov_Artem_ComplexNumberTest, Can_Multiply_By_Zero) {
    // Arrange 
    double re = 1.1;
    double im = 1.1;

    // Act 
    ComplexNumber a(re , im);
    ComplexNumber b(0.0 , 0.0);

    // Assert 
    EXPECT_EQ(b , a * b);
}
