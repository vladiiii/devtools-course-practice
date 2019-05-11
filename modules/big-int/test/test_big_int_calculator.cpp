// Copyright 2019 Volkov Pavel


#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/big_int_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;



class BigIntCalculatorTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    BigIntCalculator app_;
    string output_;
};

TEST_F(BigIntCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a complex number calculator application\\..*");
}
