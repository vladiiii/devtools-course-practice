// Copyright 2019 Kurakin Mikhail

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kurakin_Mikhail_ComplexNumberTest, Numbers_Is_Equal_After_Multiply) {
    // Arrange
    ComplexNumber a(5.0, 2.0);
    ComplexNumber b(5.0, 4.0);

    // Act
    ComplexNumber c = a * b;

    // Assert
    ComplexNumber exp_ans(17.0, 30.0);
    EXPECT_EQ(exp_ans, c);
}

TEST(Kurakin_Mikhail_ComplexNumberTest, Numbers_Is_Equal_After_Division) {
    // Arrange
    ComplexNumber a(50.0, 20.0);
    ComplexNumber b(2.0, 4.0);

    // Act
    ComplexNumber c = a / b;

    // Assert
    ComplexNumber exp_ans(9, -8.0);
    EXPECT_EQ(exp_ans, c);
}

TEST(Kurakin_Mikhail_ComplexNumberTest, Can_Copy) {
    // Arrange
    double re = 55.5;
    double im = 44.4;

    // Act
    ComplexNumber a(re, im);
    ComplexNumber c(a);

    // Assert
    EXPECT_EQ(a.getRe(), c.getRe());
    EXPECT_EQ(a.getIm(), c.getIm());
}

TEST(Kurakin_Mikhail_ComplexNumberTest, Copy_Has_Its_Own_Memory) {
    // Arrange
    double re = 55.5;
    double im = 44.4;

    // Act
    ComplexNumber a(re, im);
    ComplexNumber c(a);

    // Assert
    EXPECT_NE(&a, &c);
}

TEST(Kurakin_Mikhail_ComplexNumberTest, Throws_Excp_When_Division_By_Zero) {
    // Arrange
    ComplexNumber a(50.0, 20.0);
    ComplexNumber b(0.0, 0.0);

    // Act & Assert
    ASSERT_ANY_THROW(a / b);
}