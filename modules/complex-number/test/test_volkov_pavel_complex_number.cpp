// Copyright 2019 Volkov Pavel

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Volkov_Pavel_ComplexNumberTest, Copy_Constructor_Is_Not_Deep) {
    // Arrange
    double re = 0.0;
    double im = 1.0;

    double re_changed = 2.0;
    double im_changed = 3.0;

    // Act
    ComplexNumber z1(re, im);

    ComplexNumber z2(z1);

    z2.setRe(re_changed);
    z2.setIm(im_changed);

    // Assert
    EXPECT_EQ(re, z1.getRe());
    EXPECT_EQ(im, z1.getIm());

    EXPECT_EQ(re_changed, z2.getRe());
    EXPECT_EQ(im_changed, z2.getIm());
}

TEST(Volkov_Pavel_ComplexNumberTest, Imagine_One_Sqr_Equal_Negative_One) {
    // Arrange
    double re = 0.0;
    double im = 1.0;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2;

    z2 = z1 * z1;

    // Assert
    EXPECT_EQ(-1.0, z2.getRe());
    EXPECT_EQ(0.0, z2.getIm());
}

TEST(Volkov_Pavel_ComplexNumberTest, Assignment_Operator_Return_Correct_Link) {
    // Arrange
    ComplexNumber z1;
    ComplexNumber z2(2.0, 3.0);
    ComplexNumber *returned_link;

    // Act
    returned_link = &(z1 = z2);


    // Assert
    EXPECT_EQ(returned_link, &z1);
}

TEST(Volkov_Pavel_ComplexNumberTest, Multiple_Summation_Check) {
    // Arrange
    ComplexNumber z;
    ComplexNumber z_rezult;

    z.setRe(1.0);
    z.setIm(2.0);

    z_rezult.setIm(0.0);
    z_rezult.setRe(0.0);

    // Act
    z_rezult = z + z + z;

    // Assert
    EXPECT_EQ(3, z_rezult.getRe());
    EXPECT_EQ(6, z_rezult.getIm());
}

TEST(Volkov_Pavel_ComplexNumberTest, Multiply_On_Zero_Check) {
    // Arrange
    ComplexNumber z;
    ComplexNumber z_rezult;

    z.setRe(0.0);
    z.setIm(0.0);

    z_rezult.setIm(1.0);
    z_rezult.setRe(1.0);

    // Act
    z_rezult = z_rezult * z;

    // Assert
    EXPECT_EQ(0.0, z_rezult.getRe());
    EXPECT_EQ(0.0, z_rezult.getIm());
}
