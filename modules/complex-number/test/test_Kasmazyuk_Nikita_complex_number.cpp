// Copyright 2019 Kasmazyuk Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Can_Distinguish_Complex_Numbers) {
// Arrange
    ComplexNumber q(15.0, 15.0);
    ComplexNumber w(5.0, 10.0);
//  Act & Assert
    EXPECT_NE(q, w);
}

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Can_Add_A_Lot_Of_Complex_Numbers) {
// Arrange
    ComplexNumber q(15.0, 15.0);
    ComplexNumber w(5.0, 10.0);
    ComplexNumber e(10.0, 2.0);
    ComplexNumber r(14.0, 3.0);
    ComplexNumber t;
// Act
    t = q + w + e + r;
// Assert
    EXPECT_EQ(44.0, e.getRe());
    EXPECT_EQ(30.0, e.getIm());
}

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Can_Be_Multiplied_By_Itself) {
// Arrange
    ComplexNumber q(4.0, 6.0);
    ComplexNumber e;
// Act
    e = q * q;
// Assert
    EXPECT_EQ(-20.0, e.getRe());
    EXPECT_EQ(48.0, e.getIm());
}

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Can_Be_Multiplied_By_Zero) {
// Arrange
    ComplexNumber q(15.0, 15.0);
    ComplexNumber w(0.0, 0.0);
// Act
    e = q * 0.0;
// Assert
    EXPECT_EQ(0.0, e.getRe());
    EXPECT_EQ(0.0, e.getIm());
}

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Can_Choose_A_Larger_Number) {
// Act
    ComplexNumber q(1.0, 2.0);
    ComplexNumber w(15.0, 15.0);

//  Act & Assert
    EXPECT_LT(q, w);
}
