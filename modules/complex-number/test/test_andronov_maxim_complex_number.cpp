// Copyright 2019 Andronov Maxim

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Andronov_Maxim_ComplexNumberTest, Can_Create_By_Default) {
    // Arrange
    ComplexNumber expected_z(0.0, 0.0);

    // Act
    ComplexNumber z;

    // Assert
    EXPECT_EQ(expected_z, z);
}

TEST(Andronov_Maxim_ComplexNumberTest, Can_Create_Copy) {
    // Arrange
    ComplexNumber expected_z(10.0, 20.0);

    // Act
    ComplexNumber z(expected_z);

    // Assert
    EXPECT_EQ(expected_z, z);
}

TEST(Andronov_Maxim_ComplexNumberTest, Can_Assign) {
    // Arrange
    ComplexNumber z(10.0, 20.0);
    ComplexNumber expected_z(30.0, 40.0);

    // Act
    z = expected_z;

    // Assert
    EXPECT_EQ(expected_z, z);
}

TEST(Andronov_Maxim_ComplexNumberTest, Can_Add_Several) {
    // Arrange
    ComplexNumber z1(10.0, 20.0);
    ComplexNumber z2(30.0, 40.0);
    ComplexNumber z3(50.0, 60.0);
    ComplexNumber z4;
    ComplexNumber expected_z(90.0, 120.0);

    // Act
    z4 = z1 + z2 + z3;

    // Assert
    EXPECT_EQ(expected_z, z4);
}

TEST(Andronov_Maxim_ComplexNumberTest, Can_Difference_Several) {
    // Arrange
    ComplexNumber z1(10.0, 20.0);
    ComplexNumber z2(30.0, 40.0);
    ComplexNumber z3(50.0, 60.0);
    ComplexNumber z4;
    ComplexNumber expected_z(10.0, 0.0);

    // Act
    z4 = z3 - z2 - z1;

    // Assert
    EXPECT_EQ(expected_z, z4);
}

TEST(Andronov_Maxim_ComplexNumberTest, Can_Multiplication_Several) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);
    ComplexNumber z3(5.0, 6.0);
    ComplexNumber z4;
    ComplexNumber expected_z(-85.0, 20.0);

    // Act
    z4 = z3 * z2 * z1;

    // Assert
    EXPECT_EQ(expected_z, z4);
}

TEST(Andronov_Maxim_ComplexNumberTest, Can_Division_Several) {
    // Arrange
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(-50.0, 100.0);
    ComplexNumber z3(-400.0, 50.0);
    ComplexNumber z4;
    ComplexNumber expected_z(1.0, 0.0);

    // Act
    z4 = z3 / z2 / z1;

    // Assert
    EXPECT_EQ(expected_z, z4);
}
