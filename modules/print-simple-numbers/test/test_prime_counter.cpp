// Copyright 2019 Gaydaychuk Yuri

#include "include/prime_counter.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

using ::testing::internal::RE;
using std::vector;
using std::string;

class PrimeCounterTest : public ::testing::Test {
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
    PrimeCounter app_;
    string output_;
};

TEST_F(PrimeCounterTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a simple printer of prime numbers\\..*");
}

TEST_F(PrimeCounterTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1"};

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(PrimeCounterTest, Five_Primes) {
    vector<string> args = {"2", "11"};

    Act(args);

    Assert("Count of prime numbers between 2 and  11 equal 5");
}
