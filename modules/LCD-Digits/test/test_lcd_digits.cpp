// Copyright 2019 Repin Vladimir
#include <gtest/gtest.h>

#include "include/lcd_digits.h"

TEST(LCD_Digit_Test, can_print_one) {
    // Arrange
    std::string one = "";
    // Act
    one = LCDDigits::lcd("212");
    // Assert
    std::cout << one << std::endl;
    //ASSERT_NO_THROW(LCDDigits d);
}


