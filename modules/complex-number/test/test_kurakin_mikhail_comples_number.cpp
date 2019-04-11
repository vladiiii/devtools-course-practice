// Copyright 2019 Kurakin Mikhail

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kurakin_Mikhail_ComplexNumberTest, Can_Triple_Multiply_Complex) {
    // Arrange
    ComplexNumber a(5.0, 2.0);
    ComplexNumber b(5.0, 4.0);
    ComplexNumber c(2.0, 2.0);

    // Act
    ComplexNumber d = a * b * c;

    // Assert
    ComplexNumber exp_ans(-26.0, 94.0);
    EXPECT_EQ(exp_ans, d);
}

TEST(Kurakin_Mikhail_ComplexNumberTest, Can_Do_All_Operations_Complex) {
    // Arrange
    ComplexNumber a(50.0, 20.0);
    ComplexNumber b(2.0, 4.0);
    ComplexNumber c(4.0, 4.0);
    ComplexNumber d(10.0, 10.0);

    // Act
    ComplexNumber f = (a / b) + c - d;

    // Assert
    ComplexNumber exp_ans(3.0, -14.0);
    EXPECT_EQ(exp_ans, f);
}

TEST(Kurakin_Mikhail_ComplexNumberTest, Can_Assign_Complex) {
    // Arrange
    double re = 55.5;
    double im = 44.4;

    // Act
    ComplexNumber a(re, im);
    ComplexNumber c(2.0, 2.0);

    // Assert
    ASSERT_NO_THROW(c = a);
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

TEST(Kurakin_Mikhail_ComplexNumberTest, Can_Multiply_By_Zero) {
    // Arrange
    ComplexNumber a(50.0, 20.0);
    ComplexNumber b(0.0, 0.0);

    // Act
    ComplexNumber c = a * b;

    // Assert
    EXPECT_EQ(b, c);
}
