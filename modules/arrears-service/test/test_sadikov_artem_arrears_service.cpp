// Copyright 2019 Sadikov Artem

#include <gtest/gtest.h>

#include "include/arrears_service.h"

TEST(Sadikov_Artem_ArrearsServiceTest, Can_Create_Client) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(ArrearService c);
}

TEST(Sadikov_Artem_ArrearsServiceTest, Can_Create_Client_With_Args) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(ArrearService c(1, 1, 1, 1));
}
