// Copyright 2019 Sadikov Artem

#include <gtest/gtest.h>

#include "include/arrears_service.h"

TEST(Sadikov_Artem_ArrearServiceTest, Can_Create_Client_With_Args) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(ArrearService(1, 1, 1, 1));
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Copy_Client) {
    // Arrange
    ArrearService c(1, 1, 1, 1);

    // Act & Assert
    ASSERT_NO_THROW(ArrearService c1(c));
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Calculate_Express_Pay) {
    // Arrange
    ArrearService c(100, 22, 20, 5);
    double res;

    // Act
    res = c.GetExpress();

    // Assert
    EXPECT_NEAR(32.92059, res, 0.0001);
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Calculate_Year_Pay) {
    // Arrange
    ArrearService c(10000, 10, 0, 5);
    double res;

    // Act
    c.SetYearPay(500);

    // Assert
    EXPECT_NEAR(732.91, c.GetYearPay(), 0.01);
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Calculate_Fond) {
    // Arrange
    ArrearService c(300, 12, 15, 6);

    // Act & Assert
    EXPECT_NEAR(8.11518, c.Fond(), 0.00001);
}
