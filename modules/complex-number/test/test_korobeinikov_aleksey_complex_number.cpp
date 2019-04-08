// Copyright 2019 Korobeinikov Aleksey

#include <gtest/gtest.h>

#include <string>

#include "include/complex_number.h"
#include "include/complex_calculator.h"


TEST(Korobeinikov_Aleksey_ComplexNumberTest,
    Can_Correct_Add_Complex_And_After_Difference_Complex) {
    // Arrange
    ComplexNumber a(5.5, 6.0);
    ComplexNumber b(343.234, 36.2764);
    ComplexNumber c(348.734, 42.2764);
    ComplexNumber e;

    // Act
    ComplexNumber d = a + b;
    e = d - c;

    // Assert
    ComplexNumber  expected_ans(0.0, 0.0);
    EXPECT_EQ(expected_ans, e);
}

TEST(Korobeinikov_Aleksey_ComplexNumberTest,
    Can_Multiply_And_Divide) {
    // Arrange
    ComplexNumber a(5.0, 1.25);
    ComplexNumber b(6.0, 8.0);
    ComplexNumber c(20.0, 47.5);
    ComplexNumber e;

    // Act
    ComplexNumber d = a * b;
    e = d/c;

    // Assert
    ComplexNumber expected_ans(1.0, 0.0);
    EXPECT_EQ(expected_ans, e);
}

TEST(Korobeinikov_Aleksey_ComplexNumberTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    ComplexNumber a;
    ComplexNumber b(1.0, 1.0);

    // Act&Assert
    EXPECT_ANY_THROW(b/a);
}

TEST(Korobeinikov_Aleksey_ComplexNumberTest,
    Check_Correctness_Of_Bool_Operations) {
    // Arrange
    ComplexNumber a(5.0, 1.25);
    ComplexNumber b(6.0, 8.0);
    ComplexNumber c, d;

    // Act
    c = a - b;
    d = a + b;

    // Assert
    ComplexNumber expected_ans(-1.0, -6.75);
    EXPECT_TRUE(expected_ans == c);
    EXPECT_TRUE(expected_ans != d);
}

TEST(Korobeinikov_Aleksey_ComplexCalculatorTest, Can_Do_Simple_Operations) {
    // Arrange
    const char* arr1[] = {"5", "4.0", "24.42", "5.0", "12.3", "-"};
    const char* arr2[] = { "5", "4.0", "24.42", "5.0", "12.3", "+"};
    ComplexCalculator app;

    // Act
    std::string ans1 = app(6, arr1);
    std::string ans2 = app(6, arr2);

    // Assert
    std::string expected_ans1 = "Real = -1 Imaginary = 12.12";
    std::string expected_ans2 = "Real = 9 Imaginary = 36.72";
    EXPECT_EQ(expected_ans1, ans1);
    EXPECT_EQ(expected_ans2, ans2);
}
