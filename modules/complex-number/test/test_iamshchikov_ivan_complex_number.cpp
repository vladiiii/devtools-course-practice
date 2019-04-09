// Copyright 2019 Iamshchikov Ivan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Iamshchikov_Ivan_ComplexNumberTest,
     Copied_Complex_Number_Has_Own_Memory) {
  // Arrange
  ComplexNumber z1(2.3, 3.2);

  // Act
  ComplexNumber z2 = z1;

  // Assert
  EXPECT_NE(&z1, &z2);
}

TEST(Iamshchikov_Ivan_ComplexNumberTest,
     Number_Copied_Via_Copy_Constructor_Is_Equal_To_Original_Number) {
  // Arrange
  ComplexNumber z1(2.3, 3.2);
  ComplexNumber z2(z1);
  bool res;

  // Act
  res = z1 == z2;

  // Assert
  EXPECT_EQ(1, res);
}

TEST(Iamshchikov_Ivan_ComplexNumberTest, Division_Of_Two_Complex_Number) {
  // Arrange
  double re1 = 6.5;
  double im1 = 0;
  double re2 = 3.25;
  double im2 = 0;
  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);
  ComplexNumber res;

  // Act
  res = z1 / z2;

  // Assert
  EXPECT_EQ(re1 / re2, res.getRe());
}

TEST(Iamshchikov_Ivan_ComplexNumberTest,
     Two_Complex_Number_With_Different_Values_Are_Not_Equal) {
  // Arrange
  double re1 = 1.5;
  double im1 = -5.2;
  double re2 = 5.2;
  double im2 = 1.3;
  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);
  bool res;

  // Act
  res = z1 == z2;

  // Assert
  EXPECT_EQ(0, res);
}
