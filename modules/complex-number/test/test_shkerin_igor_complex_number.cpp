// Copyright 2019 Shkerin Igor

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Shkerin_Igor_ComplexNumberTest, Can_Create_Negative_complex) {
    // Arrange
    double re = -3.0;
    double im = -7.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}