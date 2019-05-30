// Copyright 2019 Konnov Sergey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Konnov_Sergey_ComplexNumberTest, Can_Sum_Multiple_Times) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(2.0, 3.0);
    ComplexNumber z3(3.0, 4.0);

    // Act
    ComplexNumber z = z1+z2+z3;

    // Assert
    ComplexNumber expected_z(6.0, 9.0);
    EXPECT_EQ(expected_z, z);
}

TEST(Konnov_Sergey_ComplexNumberTest,
     Dividing_The_Complex_Number_By_Itself_Gives_One) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);

    // Act
    ComplexNumber z = z1/z1;

    // Assert
    ComplexNumber expected_z(1.0, 0.0);
    EXPECT_EQ(expected_z, z);
}

TEST(Konnov_Sergey_ComplexNumberTest, Cant_Divide_By_Zero) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(0.0, 0.0);

    // Act & Assert
    ASSERT_ANY_THROW(z1/z2);
}

TEST(KonnovSergey_ComplexNumberTest, Can_Create_Copy_Of_Complex_Number) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);

    // Act
    ComplexNumber z(z1);

    // Assert
    EXPECT_EQ(z, z1);
}
