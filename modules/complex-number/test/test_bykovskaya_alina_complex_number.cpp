// Copyright 2019 Bykovskaya Alina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Bykovskaya_Alina_ComplexNumberTest, Can_Assign_Complex) {
    // Arrange
    ComplexNumber a(2., 3.), b(4., 5.);

    // Act
    b = a;

    // Assert
    EXPECT_EQ(true, a == b);
}

TEST(Bykovskaya_Alina_ComplexNumberTest, Can_Assign_To_Itself) {
    // Arrange
    ComplexNumber a(3.0, 4.5);

    // Act & Assert
    ASSERT_NO_THROW(a = a);
}

TEST(Bykovskaya_Alina_ComplexNumberTest, Can_Create_By_Copy_Constructor) {
    // Arrange
    ComplexNumber a(3.0, 5.0);

    // Act
    ComplexNumber b(a);

    // Assert
    EXPECT_EQ(a.getRe(), b.getRe());
    EXPECT_EQ(a.getIm(), b.getIm());
}

TEST(Bykovskaya_Alina_ComplexNumberTest,
                            Can_Add_More_Than_Two_Complex) {
    // Arrange
    ComplexNumber a(1., 1.);
    ComplexNumber b(2., 2.);
    ComplexNumber expect(6., 6.);

    // Act
    ComplexNumber c = a + a + b + b;

    // Assert
    EXPECT_EQ(expect.getRe(), c.getRe());
    EXPECT_EQ(expect.getIm(), c.getIm());
}

TEST(Bykovskaya_Alina_ComplexNumberTest,
                        Can_Difference_More_Than_Two_Complex) {
    // Arrange
    ComplexNumber a(20., 20.);
    ComplexNumber b(2., 2.);
    ComplexNumber expect(14., 14.);

    // Act
    ComplexNumber c = a - b - b - b;

    // Assert
    EXPECT_EQ(expect.getRe(), c.getRe());
    EXPECT_EQ(expect.getIm(), c.getIm());
}

TEST(Bykovskaya_Alina_ComplexNumberTest, Cant_Divide_By_Zero) {
    // Arrange
    ComplexNumber a(5.0, 5.0), b(-5.0, -5.0), z(5.6, 9.8);

    // Act & Assert
    ASSERT_ANY_THROW((z + z) / (a + b));
}
