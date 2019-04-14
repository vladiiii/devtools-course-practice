// Copyright 2019 Kondrina Tatyana

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kondrina_Tatyana_ComplexNumder, Can_GetRe_And_GetIm) {
    // Arrange
    ComplexNumber z(2.0, 3.0);

    // Assert
    EXPECT_EQ(2.0, z.getRe());
    EXPECT_EQ(3.0, z.getIm());
}

TEST(Kondrina_Tatyana_ComplexNumber, Can_Assign) {
    // Arrange
    ComplexNumber z;
    ComplexNumber z1(2.0, 3.0);

    // Act
    z = z1;

    // Assert
    EXPECT_EQ(z, z1);
}

TEST(Kondrina_Tatyana_ComplexNumper, Can_Compare) {
    // Arrange
    ComplexNumber z;
    ComplexNumber z1(2.0, 3.0);

    // Assert
    EXPECT_EQ(false, z == z1);

    // Act
    z = z1;

    // Assert
    EXPECT_EQ(false, z != z1);
}

TEST(Kondrina_Tatyana_ComplexNumber, Can_Add) {
    // Arrange
    ComplexNumber z;
    ComplexNumber z1(2.0, 3.0);

    // Assert
    EXPECT_EQ(z1, z + z1);
}

TEST(Kondrina_Tatyana_ComplexNumber, Can_Multi_Some_Numbers) {
    // Arrange
    ComplexNumber z(2.0, 3.0);
    ComplexNumber z1(3.0, 4.0);

    // Act
    ComplexNumber z2 = z + z1;

    //Assert
    ComplexNumber expected_z(-149.0, 43.0);
    EXPECT_EQ(expected_z, z*z1*z2);
}
