// Copyright 2019 Kasmazyuk Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Can_Create_Complex_Number) {
// Arrange
    double re = 2.0;
    double im = 3.0;
// Act
    ComplexNumber e(re, im);
// Assert
    EXPECT_EQ(re, e.getRe());
    EXPECT_EQ(im, e.getIm());
}

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Can_Sum_Complex_Number) {
// Arrange
    ComplexNumber q(15.0, 15.0);
    ComplexNumber w(5.0, 10.0);
    ComplexNumber e;
// Act
    e = q + w;
// Assert
    EXPECT_EQ(20.0, e.getRe());
    EXPECT_EQ(25.0, e.getIm());
}

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Can_Multiplication_Complex_Number) {
// Arrange
    ComplexNumber q(15.0, 15.0);
    ComplexNumber w(5.0, 10.0);
    ComplexNumber e;
// Act
    e = q * w;
// Assert
    EXPECT_EQ(-75.0, e.getRe());
    EXPECT_EQ(225.0, e.getIm());
}

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Equal_Numbers_Are_Equal) {
// Arrange
    ComplexNumber q(15.0, 15.0);
    ComplexNumber w(15.0, 15.0);
// Act & Assert
    EXPECT_EQ(q.getRe(), w.getRe());
    EXPECT_EQ(q.getIm(), w.getIm());
}

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Not_Equal_Numbers_Not_Equal) {
// Act
    ComplexNumber q(1.0, 2.0);
    ComplexNumber w(15.0, 15.0);

//  Act & Assert
    EXPECT_EQ(true, q != w);
}
