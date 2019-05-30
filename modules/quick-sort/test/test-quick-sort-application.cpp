// Copyright 2019 by Zolotareva Olesya

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/quick-sort-application.h"

using ::testing::internal::RE;

class QuickSortApplicationTest : public ::testing::Test {
 protected:
      void Act(std::vector<std::string> args_) {
         std::vector<const char*> options;
         options.push_back("appname");

         for (size_t i = 0; i < args_.size(); ++i) {
             options.push_back(args_[i].c_str());
         }

          const char** argv = &options.front();
          int argc = static_cast<int>(args_.size()) + 1;

          output_ = app_(argc, argv);
          std::cout << std::endl << output_ << std::endl;
     }

      void Assert(std::string expected) {
         EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
     }

 private:
     QuickSortApplication app_;
     std::string output_;
};

TEST_F(QuickSortApplicationTest, Do_Print_Help_Without_Arguments) {
     std::vector<std::string> args = {};

     Act(args);

     Assert("This is a quick sort application\\..*");
}

TEST_F(QuickSortApplicationTest, Is_Checking_Number_Of_Arguments) {
    std::vector<std::string> args = {"1"};

    Act(args);

    Assert("ERROR: Check count of arguments and size of entered array\\..*");
}

TEST_F(QuickSortApplicationTest, Can_Detect_Wrong_Number_Format) {
    std::vector<std::string> args = {"e", "pi"};

    Act(args);

    Assert("Wrong number format in size!.*");
}


TEST_F(QuickSortApplicationTest, Can_Detect_Wrong_Size_Of_Array) {
    std::vector<std::string> args = {"0"};

    Act(args);

    Assert("ERROR: Size must be >= 1.*");
}

TEST_F(QuickSortApplicationTest,
    Is_Check_Count_of_argument_And_Size) {
    std::vector<std::string> args = {"2", "1", "3", "5"};

    Act(args);

    Assert("ERROR: Check count of arguments and size of entered array\\..*");
}

TEST_F(QuickSortApplicationTest, Can_Detect_Wrong_Number_Format_In_Array) {
    std::vector<std::string> args = {"3", "one", "2", "3"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(QuickSortApplicationTest, Can_Sorted) {
    std::vector<std::string> args = {"3", "1", "2", "3"};

    Act(args);

    Assert("Sorted was successful");
}

TEST_F(QuickSortApplicationTest, Can_Double_Number_Format_In_Array) {
    std::vector<std::string> args = {"3", "8.5", "2", "3"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(QuickSortApplicationTest, Can_Sorted_Negative) {
    std::vector<std::string> args = {"3", "-3", "-5", "-1"};

    Act(args);

    Assert("Sorted was successful");
}

TEST_F(QuickSortApplicationTest, Can_Negative_Wrong_Number_Format) {
    std::vector<std::string> args = {"-3", "1", "2", "3"};

    Act(args);

    Assert("ERROR: Check count of arguments and size of entered array.*");
}
