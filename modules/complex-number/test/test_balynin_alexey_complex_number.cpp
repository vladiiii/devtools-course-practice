// Copyright 2017 Balynin Alexey
#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Balynin_Alexey_ComplexNumberTest, Multiplication_With_Zero) {
    // Arrange
    ComplexNumber a(2.0, 3.0);
    ComplexNumber zero(0, 0);

    // Act
    a = a * zero;

    // Assert
    EXPECT_EQ(a, zero);
}

TEST(Balynin_Alexey_ComplexNumberTest, Can_Make_Assigned_To_Yourself) {
    // Act
    ComplexNumber a(6.0, 9.9);

    // Assert
    ASSERT_NO_THROW(a = a);
}

TEST(Balynin_Alexey_ComplexNumberTest, Can_Generate_Zero) {
    // Arrange
    double a = 0.0;
    double b = 0.0;

    // Act
    ComplexNumber c(a, b);

    // Assert
    EXPECT_EQ(a, c.getRe());
    EXPECT_EQ(b, c.getIm());
}

TEST(Alexey_Balynin_ComplexNumberTest, Can_Create_Without_Arguments) {
    // Arrange & Act
    ComplexNumber f(0.0, 0.0);
    ComplexNumber fp;

    // Assert
    EXPECT_EQ(f, fp);
}

TEST(Balynin_Alexey_ComplexNumberTest, Can_Assign_Complex) {
    // Arrange & Act
    ComplexNumber c(15.0, 15.0);
    ComplexNumber c1;

    // Assert
    ASSERT_NO_THROW(c1 = c);
}
