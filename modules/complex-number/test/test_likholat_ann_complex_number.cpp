// Copyright 2019 Likholat Ann

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Likholat_Ann_ComplexNumberTest, Can_Create_Copy) {
    // Arrange
    ComplexNumber z(2.3, 1.4);

    // Act
    ComplexNumber z_1(z);

    // Assert
    EXPECT_EQ(z, z_1);
}

TEST(Likholat_Ann_ComplexNumberTest, Can_Add_Associativy) {
    // Arrange
    ComplexNumber z(2.0, 1.4);
    ComplexNumber z_1(4.6, 3.0);
    ComplexNumber z_2(7.3, 1.2);

    // Act
    ComplexNumber res = (z + z_1) + z_2;
    ComplexNumber res_1 = z + (z_1 + z_2);

    // Assert
    EXPECT_DOUBLE_EQ(res.getRe(), res_1.getRe());
    EXPECT_DOUBLE_EQ(res.getIm(), res_1.getIm());
}

TEST(Likholat_Ann_ComplexNumberTest, Can_Multiply_By_Zero) {
    // Arrange
    ComplexNumber z(2.0, 1.0);
    ComplexNumber zero(0.0, 0.0);

    // Act
    ComplexNumber res = z * zero;

    // Assert
    EXPECT_EQ(res, zero);
}


TEST(Likholat_Ann_ComplexNumberTest, Can_Multiply_By_Itself) {
    // Arrange
    ComplexNumber z(2.3, 1.2);

    // Act
    ComplexNumber res = z * z;

    // Assert
    ComplexNumber expected_res(3.85, 5.52);
    EXPECT_DOUBLE_EQ(expected_res.getRe(), res.getRe());
    EXPECT_DOUBLE_EQ(expected_res.getIm(), res.getIm());
}
