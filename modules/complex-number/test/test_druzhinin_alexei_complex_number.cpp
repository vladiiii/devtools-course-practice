// Copyright 2019 Druzhinin Alexei

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Druzhinin_Alexei_ComplexNumberTest, Can_add_complex_numbers) {
    // Arrange
    ComplexNumber z1(3.2, 6.8);
    ComplexNumber z2(6.8, 3.2);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    EXPECT_EQ(10.0, z.getRe());
    EXPECT_EQ(10.0, z.getIm());
}

TEST(Druzhinin_Alexei_ComplexNumberTest, Can_sub_complex_numbers) {
    // Arrange
    ComplexNumber z1(6.2, 3.3);
    ComplexNumber z2(1.2, -1.7);

    // Act
    ComplexNumber z = z1 - z2;

    // Assert
    EXPECT_EQ(5.0, z.getRe());
    EXPECT_EQ(5.0, z.getIm());
}

TEST(Druzhinin_Alexei_ComplexNumberTest, Can_multiply_complex_numbers) {
    // Arrange
    ComplexNumber z1(5.0, 1.0);
    ComplexNumber z2(1.0, 5.0);

    // Act
    ComplexNumber z = z1 * z2;

    // Assert
    EXPECT_EQ(0.0, z.getRe());
    EXPECT_EQ(26.0, z.getIm());
}

TEST(Druzhinin_Alexei_ComplexNumberTest, Can_division_complex_numbers) {
    // Arrange
    ComplexNumber z1(5.0, 1.0);
    ComplexNumber z2(z1);

    // Act
    ComplexNumber z = z1 / z2;

    // Assert
    EXPECT_EQ(1.0, z.getRe());
    EXPECT_EQ(0.0, z.getIm());
}

TEST(Druzhinin_Alexei_ComplexNumberTest, Can_compare_eq_complex_numbers) {
    // Arrange
    ComplexNumber z1(1.0, 1.0);

    // Act
    ComplexNumber z2 = z1;

    // Assert
    EXPECT_EQ(z1, z2);
}

TEST(Druzhinin_Alexei_ComplexNumberTest, Can_compare_neq_complex_numbers) {
    // Arrange
    ComplexNumber z1(1.0, 1.0);

    // Act
    ComplexNumber z2 = z1;
    z2.setRe(2.0);

    // Assert
    EXPECT_NE(z1, z2);
}
