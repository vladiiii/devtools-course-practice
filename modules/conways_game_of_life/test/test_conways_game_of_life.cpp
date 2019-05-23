// Copyright 2019 Logvinenko Alexandra

#include <gtest/gtest.h>
#include "include/conways_game_of_life.h"
#include <string>

TEST(Conways_life, Can_create_field) {
	// Arrange
	int widht = 5;
	int heigth = 6;

	// Act
	Conways_life z(widht, heigth);

	// Assert
	EXPECT_EQ(widht, z.getW());
	EXPECT_EQ(heigth, z.getH());
}

TEST(Conways_life, Can_Get_Widht) {
	// Arrange
	Conways_life z(5, 6);

	// Act
	int w = z.getW();

	// Assert
	EXPECT_EQ(5, w);
}
TEST(Conways_life, Can_Get_Heigth) {
	// Arrange
	Conways_life z(5, 6);

	// Act
	int h = z.geth();

	// Assert
	EXPECT_EQ(6, h);
}
TEST(Conways_life, Do_Throw_When_Wrong_Sizes) {
	// Arrange
	int widht = 0;
	int heigth = 6;

	// Act & Assert
	EXPECT_THROW(Conways_life z(widht, heigth), std::string);
}
TEST(Conways_life, Do_Throw_When_Put_Wrong_Point) {
	// Arrange
	Conways_life z(5, 6);

	// Act & Assert
	EXPECT_THROW(z.putStart(0, -1), std::string);
}