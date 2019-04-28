// Copyright 2019 Vikhrev Ivan
#include <gtest/gtest.h>
#include <string>
#include "include/lcd_digits.h"

class LCDDigitsTest : public ::testing::Test {
 public:
      std::string colon = "  \n"
                          ". \n"
                          ". \n";
      std::string point = "  \n"
                          "  \n"
                          ". \n";
      std::string zero =  " _  \n"
                          "| | \n"
                          "|_| \n";

      std::string one = "  \n"
                        "| \n"
                        "| \n";

      std::string two =  " _  \n"
                         " _| \n"
                         "|_  \n";

      std::string three =  " _  \n"
                           " _| \n"
                           " _| \n";

      std::string four =  "    \n"
                          "|_| \n"
                          "  | \n";

      std::string five =  " _  \n"
                          "|_  \n"
                          " _| \n";

      std::string six =  " _  \n"
                         "|_  \n"
                         "|_| \n";

      std::string seven =  " _  \n"
                           "|   \n"
                           "|   \n";

      std::string eight =  " _  \n"
                           "|_| \n"
                           "|_| \n";

      std::string nine =  " _  \n"
                          "|_| \n"
                          " _| \n";

      std::string n98 = " _   _  \n"
                        "|_| |_| \n"
                        " _| |_| \n";

      std::string time = "   _     _   _     _   _  \n"
                         "| |_  . | | | | . |_  |_| \n"
                         "| |_| . |_| |_| .  _|  _| \n";

      std::string date = "   _     _         _   _   _   _  \n"
                         "|  _|    _| |_|   |_  |_  |   |_| \n"
                         "| |_  .  _|   | .  _| |_| |   |_| \n";
};



TEST_F(LCDDigitsTest, can_create_lcd_zero_from_int) {
    // Act & Assert
    EXPECT_EQ(zero, LCDDigits::lcd(0));
}

TEST_F(LCDDigitsTest, can_create_lcd_one_from_int) {
    // Act & Assert
    EXPECT_EQ(one, LCDDigits::lcd(1));
}

TEST_F(LCDDigitsTest, can_create_lcd_two_from_int) {
    // Act & Assert
    EXPECT_EQ(two, LCDDigits::lcd(2));
}

TEST_F(LCDDigitsTest, can_create_lcd_three_from_int) {
    // Act & Assert
    EXPECT_EQ(three, LCDDigits::lcd(3));
}

TEST_F(LCDDigitsTest, can_create_lcd_four_from_int) {
    // Act & Assert
    EXPECT_EQ(four, LCDDigits::lcd(4));
}

TEST_F(LCDDigitsTest, can_create_lcd_five_from_int) {
    // Act & Assert
    EXPECT_EQ(five, LCDDigits::lcd(5));
}

TEST_F(LCDDigitsTest, can_create_lcd_six_from_int) {
    // Act & Assert
    EXPECT_EQ(six, LCDDigits::lcd(6));
}

TEST_F(LCDDigitsTest, can_create_lcd_seven_from_int) {
    // Act & Assert
    EXPECT_EQ(seven, LCDDigits::lcd(7));
}

TEST_F(LCDDigitsTest, can_create_lcd_eight_from_int) {
    // Act & Assert
    EXPECT_EQ(eight, LCDDigits::lcd(8));
}

TEST_F(LCDDigitsTest, can_create_lcd_nine_from_int) {
    // Act & Assert
    EXPECT_EQ(nine, LCDDigits::lcd(9));
}

TEST_F(LCDDigitsTest, can_create_lcd_number_from_int) {
    // Act & Assert
    EXPECT_EQ(n98, LCDDigits::lcd(98));
}

TEST_F(LCDDigitsTest, can_create_lcd_point_from_string) {
    // Act & Assert
    EXPECT_EQ(point, LCDDigits::lcd("."));
}

TEST_F(LCDDigitsTest, can_create_lcd_colon_from_string) {
    // Act & Assert
    EXPECT_EQ(colon, LCDDigits::lcd(":"));
}

TEST_F(LCDDigitsTest, can_create_lcd_zero_from_string) {
    // Act & Assert
    EXPECT_EQ(zero, LCDDigits::lcd("0"));
}

TEST_F(LCDDigitsTest, can_create_lcd_one_from_string) {
    // Act & Assert
    EXPECT_EQ(one, LCDDigits::lcd("1"));
}

TEST_F(LCDDigitsTest, can_create_lcd_two_from_string) {
    // Act & Assert
    EXPECT_EQ(two, LCDDigits::lcd("2"));
}

TEST_F(LCDDigitsTest, can_create_lcd_three_from_string) {
    // Act & Assert
    EXPECT_EQ(three, LCDDigits::lcd("3"));
}


TEST_F(LCDDigitsTest, can_create_lcd_four_from_string) {
    // Act & Assert
    EXPECT_EQ(four, LCDDigits::lcd("4"));
}

TEST_F(LCDDigitsTest, can_create_lcd_five_from_string) {
    // Act & Assert
    EXPECT_EQ(five, LCDDigits::lcd("5"));
}

TEST_F(LCDDigitsTest, can_create_lcd_six_from_string) {
    // Act & Assert
    EXPECT_EQ(six, LCDDigits::lcd("6"));
}

TEST_F(LCDDigitsTest, can_create_lcd_seven_from_string) {
    // Act & Assert
    EXPECT_EQ(seven, LCDDigits::lcd("7"));
}

TEST_F(LCDDigitsTest, can_create_lcd_eight_from_string) {
    // Act & Assert
    EXPECT_EQ(eight, LCDDigits::lcd("8"));
}

TEST_F(LCDDigitsTest, can_create_lcd_nine_from_string) {
    // Act & Assert
    EXPECT_EQ(nine, LCDDigits::lcd("9"));
}

TEST_F(LCDDigitsTest, can_create_lcd_number_from_string) {
    // Act & Assert
    EXPECT_EQ(n98, LCDDigits::lcd("98"));
}

TEST_F(LCDDigitsTest, can_create_lcd_time_from_string) {
    // Act & Assert
    EXPECT_EQ(time, LCDDigits::lcd("16:00:59"));
}

TEST_F(LCDDigitsTest, can_create_lcd_date_from_string) {
    // Act & Assert
    EXPECT_EQ(date, LCDDigits::lcd("12.34.5678"));
}



