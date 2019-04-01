// Copyright 2019 Zhivaev Artem

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Zhivaev_Artem_ComplexNumberTest, Can_Create_Negative_Real) {
    // Arrange
    double re = -4719719.7568345;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

