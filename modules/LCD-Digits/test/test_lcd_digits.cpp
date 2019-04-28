// Copyright 2019 Vikhrev Ivan
#include <gtest/gtest.h>
#include <string>
#include "include/lcd_digits.h"

class LCDDigitsTest : public ::testing::Test {
 public:
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
};



TEST_F(LCDDigitsTest, can_create_zero_from_int) {
    // Act & Assert
    EXPECT_EQ(zero, LCDDigits::lcd(0));
}

TEST_F(LCDDigitsTest, can_create_one_from_int) {
    // Act & Assert
    EXPECT_EQ(one, LCDDigits::lcd(1));
}

TEST_F(LCDDigitsTest, can_create_two_from_int) {
    // Act & Assert
    EXPECT_EQ(two, LCDDigits::lcd(2));
}

TEST_F(LCDDigitsTest, can_create_three_from_int) {
    // Act & Assert
    EXPECT_EQ(three, LCDDigits::lcd(3));
}

TEST_F(LCDDigitsTest, can_create_four_from_int) {
    // Act & Assert
    EXPECT_EQ(four, LCDDigits::lcd(4));
}

TEST_F(LCDDigitsTest, can_create_five_from_int) {
    // Act & Assert
    EXPECT_EQ(five, LCDDigits::lcd(5));
}

TEST_F(LCDDigitsTest, can_create_six_from_int) {
    // Act & Assert
    EXPECT_EQ(six, LCDDigits::lcd(6));
}

TEST_F(LCDDigitsTest, can_create_seven_from_int) {
    // Act & Assert
    EXPECT_EQ(seven, LCDDigits::lcd(7));
}

TEST_F(LCDDigitsTest, can_create_eight_from_int) {
    // Act & Assert
    EXPECT_EQ(eight, LCDDigits::lcd(8));
}

TEST_F(LCDDigitsTest, can_create_nine_from_int) {
    // Act & Assert
    EXPECT_EQ(nine, LCDDigits::lcd(9));
}

TEST_F(LCDDigitsTest, can_create_number_from_int) {
    // Act & Assert
    EXPECT_EQ(n98, LCDDigits::lcd(98));
}


TEST_F(LCDDigitsTest, can_create_zero_from_string) {
    // Act & Assert
    EXPECT_EQ(zero, LCDDigits::lcd("0"));
}

TEST_F(LCDDigitsTest, can_create_one_from_string) {
    // Act & Assert
    EXPECT_EQ(one, LCDDigits::lcd("1"));
}

TEST_F(LCDDigitsTest, can_create_two_from_string) {
    // Act & Assert
    EXPECT_EQ(two, LCDDigits::lcd("2"));
}

TEST_F(LCDDigitsTest, can_create_three_from_string) {
    // Act & Assert
    EXPECT_EQ(three, LCDDigits::lcd("3"));
}


TEST_F(LCDDigitsTest, can_create_four_from_string) {
    // Act & Assert
    EXPECT_EQ(four, LCDDigits::lcd("4"));
}

TEST_F(LCDDigitsTest, can_create_five_from_string) {
    // Act & Assert
    EXPECT_EQ(five, LCDDigits::lcd("5"));
}

TEST_F(LCDDigitsTest, can_create_six_from_string) {
    // Act & Assert
    EXPECT_EQ(six, LCDDigits::lcd("6"));
}

TEST_F(LCDDigitsTest, can_create_seven_from_string) {
    // Act & Assert
    EXPECT_EQ(seven, LCDDigits::lcd("7"));
}

TEST_F(LCDDigitsTest, can_create_eight_from_string) {
    // Act & Assert
    EXPECT_EQ(eight, LCDDigits::lcd("8"));
}

TEST_F(LCDDigitsTest, can_create_nine_from_string) {
    // Act & Assert
    EXPECT_EQ(nine, LCDDigits::lcd("9"));
}

TEST_F(LCDDigitsTest, can_create_number_from_string) {
    // Act & Assert
    EXPECT_EQ(n98, LCDDigits::lcd("98"));
}



