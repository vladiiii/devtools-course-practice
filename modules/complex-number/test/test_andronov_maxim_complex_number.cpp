// Copyright 2019 Andronov Maxim

#include <gtest/gtest.h>

#include "include/complex_number.h"

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

TEST(Andronov_Maxim_ComplexNumberTest, Can_Assign_To_Itself) {
    // Arrange
    ComplexNumber z(10.0, 20.0);

    // Act & Assert
    ASSERT_NO_THROW(z = z);
}

TEST(Andronov_Maxim_ComplexNumberTest, Can_Add) {
    // Arrange
    ComplexNumber z1(10.0, 20.0);
    ComplexNumber z2(30.0, 40.0);
    ComplexNumber z3;
    ComplexNumber expected_z(40.0, 60.0);

    // Act
    z3 = z1 + z2;

    // Assert
    EXPECT_EQ(expected_z, z3);
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

TEST(Andronov_Maxim_ComplexNumberTest, Can_Difference) {
    // Arrange
    ComplexNumber z1(10.0, 20.0);
    ComplexNumber z2(30.0, 40.0);
    ComplexNumber z3;
    ComplexNumber expected_z(20.0, 20.0);

    // Act
    z3 = z2 - z1;

    // Assert
    EXPECT_EQ(expected_z, z3);
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
///
TEST(Andronov_Maxim_ComplexNumberTest, Can_Multiplication) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);
    ComplexNumber z3;
    ComplexNumber expected_z(-5.0, 10.0);

    // Act
    z3 = z2 * z1;

    // Assert
    EXPECT_EQ(expected_z, z3);
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

TEST(Andronov_Maxim_ComplexNumberTest, Can_Division) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(30.0, 40.0);
    ComplexNumber z3;
    ComplexNumber expected_z(22.0, -4.0);

    // Act
    z3 = z2 / z1;

    // Assert
    EXPECT_EQ(expected_z, z3);
}

