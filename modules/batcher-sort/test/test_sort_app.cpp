// Copyright 2019 Kondrina Tatyana

#include <vector>
#include <iostream>
#include <string>

#include "include/BatcherSort_app.h"
#include "gtest/gtest.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class BatcherSortAppTest : public ::testing::Test {
 protected:
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
    BatcherSortApp app_;
    string output_;
};

TEST_F(BatcherSortAppTest, Print_Info_Without_Args) {
    vector<string> vec = {};

    Act(vec);

    Assert("This is a Batcher Sort application\\..*");
}

TEST_F(BatcherSortAppTest, Can_Sort) {
    vector<string> vec = { "0", "1", "3", "-1", "6", "5", "1", "2" };

    Act(vec);

    Assert("Sort = -1 0 1 1 2 3 5 6");
}

TEST_F(BatcherSortAppTest, Can_Check_Number_Of_Args) {
    vector<string> vec = { "0", "1", "3" };

    Act(vec);

    Assert("The number of elements must be a degree of 2 *");
}

TEST_F(BatcherSortAppTest, Can_Check_Symbols_In_Args) {
    vector<string> vec = { "1", "0", "s", "2" };

    Act(vec);

    Assert("ERROR : All arguments must be integers. *");
}
