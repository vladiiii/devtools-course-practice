// Copyright 2019 Vikhrev Ivan
#include <gtest/gtest.h>

#include "include/lcd_digits.h"

class LCDDigitsTestt : public ::testing::Test {
  public:
      std::string zero =  " _ "
                                     "| |"
                                     "|_|";

      std::string one = " "
                        "|"
                        "|";
      std::string two =  " _ "
                                    " _|"
                                    "|_ ";

      std::string three =  " _ "
                                      " _|"
                                      " _|";

      std::string four =  "   "
                                     "|_|"
                                     "  |";

      std::string five =  " _ "
                                     "|_ "
                                     " _|" ;

      std::string six =  " _ "
                                    "|_ "
                                    "|_|" ;

      std::string seven =  " _ "
                                      "|  "
                                      "|  ";

      std::string eight =  " _ "
                                      "|_| "
                                      "|_|" ;

      std::string nine =  " _ "
                                     "|_|"
                                     " _|" ;
};


TEST_F(LCDDigitsTest, can_print_one) {
    //Act & Assert
    EXPECT_EQ(one, LCDDigits::lcd("1"));
}


