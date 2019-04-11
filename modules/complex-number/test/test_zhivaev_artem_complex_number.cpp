// Copyright 2019 Zhivaev Artem

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Zhivaev_Artem_ComplexNumberTest, Can_Create_Without_Parametrs) {
    // Arrange & Act
    ComplexNumber z;

    // Assert
    EXPECT_EQ(0.0, z.getRe());
    EXPECT_EQ(0.0, z.getIm());
}

TEST(Zhivaev_Artem_ComplexNumberTest, Can_Assign_Another_Number) {
    // Arrange
    double re = 13.45;
    double im = 3.85;
    ComplexNumber z;
    ComplexNumber expected_z(re, im);

    // Act
    z = expected_z;

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Zhivaev_Artem_ComplexNumberTest,
     Assign_Operator_Returns_Reference_To_Original_Number) {
    // Arrange
    double re = 13.45;
    double im = 3.85;
    double new_im = 8.95;
    ComplexNumber z;

    // Act
    ComplexNumber expected_z(re, im);
    (z = expected_z).setIm(new_im);

    // Assert
    EXPECT_EQ(new_im, z.getIm());
    EXPECT_EQ(re, z.getRe());
}

TEST(Zhivaev_Artem_ComplexNumberTest,
     Multiply_Zero_Number_On_Non_Zero_Returns_Zero) {
    // Arrage
    ComplexNumber z(11.85, 19.35);
    ComplexNumber z_zero(0.0, 0.0);

    // Act
    ComplexNumber result = z_zero * z;

    // Assert
    EXPECT_EQ(0.0, result.getIm());
    EXPECT_EQ(0.0, result.getRe());
}

TEST(Zhivaev_Artem_ComplexNumberTest,
     Division_Zero_On_Non_Zero_Returns_Zero) {
    // Arrage
    ComplexNumber z(11.85, 19.35);
    ComplexNumber z_zero(0.0, 0.0);

    // Act
    ComplexNumber result = z_zero / z;

    // Assert
    EXPECT_EQ(0.0, result.getIm());
    EXPECT_EQ(0.0, result.getRe());
}

TEST(Zhivaev_Artem_ComplexNumberTest, Can_Create_Negative_Real) {
    // Arrange
    double re = -9.45;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Zhivaev_Artem_ComplexNumberTest, Can_Create_Negative_Imagine) {
    // Arrange
    double re = 0.0;
    double im = -9.45;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Zhivaev_Artem_ComplexNumberTest, Do_Not_Throw_If_Assign_To_Itself) {
    // Arrange
    ComplexNumber z(13.45, 9.25);

    // Act & Assert
    EXPECT_NO_THROW(z = z);
}

TEST(Zhivaev_Artem_ComplexNumberTest,
     Do_Not_Throw_If_Divide_By_Zero_Real_Non_Zero_Imagine) {
    // Arrange
    ComplexNumber z(45.65, 13.35);
    ComplexNumber zero_real_z(0.0, 34.75);

    // Act & Assert
    EXPECT_NO_THROW(z / zero_real_z);
}
