// Copyright 2019 Logvinenko Alexandra

#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include "include/conways_game_of_life.h"

TEST(Conways_life, Do_Throw_When_Wrong_Sizes) {
    // Arrange
    int widht = 0;
    int heigth = 2;

    // Act & Assert
    EXPECT_THROW(Conways_life z(widht, heigth), std::string);
}

TEST(Conways_life, Can_Get_Widht) {
    // Arrange
    Conways_life zz(1, 2);

    // Act
    int w = zz.getW();

    // Assert
    EXPECT_EQ(1, w);
}
TEST(Conways_life, Can_Get_Heigth) {
    // Arrange
    Conways_life zy(1, 2);

    // Act
    int h = zy.getH();

    // Assert
    EXPECT_EQ(2, h);
}
TEST(Conways_life, Do_Throw_When_Put_Wrong_Point) {
    // Arrange
    Conways_life zx(1, 2);

    // Act & Assert
    EXPECT_THROW(zx.putStart(0, -1), std::string);
}
TEST(Conways_life, Can_create_field) {
    // Arrange
    int widht = 1;
    int heigth = 2;

    // Act
    Conways_life zc(widht, heigth);

    // Assert
    EXPECT_EQ(widht, zc.getW());
    EXPECT_EQ(heigth, zc.getH());
}
