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

//TEST(Andronov_Maxim_ComplexNumberTest, ) {
//    // Arrange
//
//
//    // Act
//
//
//    // Assert
//
//
//}
//
//TEST(Andronov_Maxim_ComplexNumberTest, ) {
//    // Arrange
//
//
//    // Act
//
//
//    // Assert
//
//
//}
//
//TEST(Andronov_Maxim_ComplexNumberTest, ) {
//    // Arrange
//
//
//    // Act
//
//
//    // Assert
//
//
//}
//
//TEST(Andronov_Maxim_ComplexNumberTest, ) {
//    // Arrange
//
//
//    // Act
//
//
//    // Assert
//
//
//}

