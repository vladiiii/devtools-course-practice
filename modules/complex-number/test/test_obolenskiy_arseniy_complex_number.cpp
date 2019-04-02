// Copyright 2017 Obolenskiy Arseniy

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Obolenskiy_Arseniy_ComplexNumberTest, Can_Sum) {
    // Arrange
    const ComplexNumber a(3, 6), b(4, 8);

    // Act
    ComplexNumber c = a + b;

    // Assert
    EXPECT_EQ(7, c.getRe());
    EXPECT_EQ(14, c.getIm());
}

TEST(Obolenskiy_Arseniy_ComplexNumberTest, Can_Subtract) {
    // Arrange
    const ComplexNumber a(7, 14), b(4, 8);

    // Act
    ComplexNumber c = a - b;

    // Assert
    EXPECT_EQ(3, c.getRe());
    EXPECT_EQ(6, c.getIm());
}
