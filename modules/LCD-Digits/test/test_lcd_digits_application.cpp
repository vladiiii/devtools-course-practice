// Copyright 2019 Repin Vladimir

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/lcd_digits_application.h"

class LCDDigitsApplicationTest
    : public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> parameters;
        parameters.push_back("LCD-Digits.exe");
        for (size_t i = 0; i < args_.size(); ++i) {
            parameters.push_back(args_[i].c_str());
        }

        const char** argv = &parameters.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_EQ(expected, output_);
    }

 private:
    LCDDigitsApplication app_;
    std::string output_;
};

TEST_F(LCDDigitsApplicationTest, Can_Print_Help_Without_Arguments) {
    // Arrange
    std::vector<std::string> args = {};

    Act(args);

    Assert("This application prints multiple strings in LCD format.\n\n"
        "Please provide arguments in the following format:\n\n"
        "  $ LCD-Digits.exe <str_1> <str_2> ... <str_n>\n"
        "Where str_i is string consisiting of digits, '.', ':'.\n");
}

TEST_F(LCDDigitsApplicationTest, Throws_On_Single_Invalid_String) {
    // Arrange
    std::vector<std::string> args = {"12.AB:2019"};

    Act(args);

    Assert("Invalid Symbol\n"
           "This application prints multiple strings in LCD format.\n\n"
           "Please provide arguments in the following format:\n\n"
           "  $ LCD-Digits.exe <str_1> <str_2> ... <str_n>\n"
           "Where str_i is string consisiting of digits, '.', ':'.\n");
}

TEST_F(LCDDigitsApplicationTest, Throws_On_Multiple_Invalid_Strings) {
    // Arrange
    std::vector<std::string> args = { "12", "ABC", "15:30", "db&"};

    Act(args);

    Assert("Invalid Symbol\n"
        "This application prints multiple strings in LCD format.\n\n"
        "Please provide arguments in the following format:\n\n"
        "  $ LCD-Digits.exe <str_1> <str_2> ... <str_n>\n"
        "Where str_i is string consisiting of digits, '.', ':'.\n");
}

TEST_F(LCDDigitsApplicationTest, Printing_Single_Symbol_Is_Correct) {
    // Arrange
    std::vector<std::string> args = { "1" };

    Act(args);

    Assert("  \n"
           "| \n"
           "| \n\n");
}
