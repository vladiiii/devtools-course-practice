// Copyright 2019 Sadikov Artem

#include <gtest/gtest.h>

#include "include/arrears_service.h"

TEST(Sadikov_Artem_ArrearServiceTest, Can_Create_Client_With_Args) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(ArrearService(1, 1, 1, 1, 1));
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Copy_Client) {
    // Arrange
    ArrearService c(1, 1, 1, 1, 1);

    // Act & Assert
    ASSERT_NO_THROW(ArrearService c1(c));
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Calculate_Express_Pay) {
    // Arrange
    ArrearService c(100, 0, 20, 22, 5);
    double res;

    // Act
    res = c.ExpressPay(5, 20);

    // Assert
    EXPECT_EQ(33, res);
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Calculate_Year_Pay) {
    // Arrange
    ArrearService c(10000, 0, 10, 0, 5);
    double res;

    // Act
    res = c.YearPayVal(10, 5, 500);

    // Assert
    EXPECT_EQ(732.91, res);
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Calculate_Fond) {
    // Arrange
    ArrearService c(1, 1, 1, 1, 1);

    // Act & Assert
    EXPECT_TRUE(773958 == (int)(c.Fond(22, 5) * 100000));
}
