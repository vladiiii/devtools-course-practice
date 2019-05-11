// Copyright 2019 Kurakin Mikhail

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/shapes_volume_application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;
class ShapesVolumeApplicationTest :public::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("shapes-volume");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }
    void Assert(std::string expected) {
        EXPECT_TRUE(::testing::internal::RE::PartialMatch(output_,
                        ::testing::internal::RE(expected)));
    }
 private:
    ShapesVolumeApplication app_;
    std::string output_;
};

TEST_F(ShapesVolumeApplicationTest, Do_Print_Help_Without_Arguments) {
    // Arrange
    std::vector<std::string> args = {};

    Act(args);

    Assert("ShapesVolume class application:");
}

TEST_F(ShapesVolumeApplicationTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"calc", "tetr"};

    Act(args);

    Assert("too few arguments");
}

TEST_F(ShapesVolumeApplicationTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"calc", "paral", "2", "4", "pu"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(ShapesVolumeApplicationTest, Can_Detect_Wrong_Param) {
    vector<string> args = {"calc", "nst", "2", "4", "5"};

    Act(args);

    Assert("wrong param.*");
}

TEST_F(ShapesVolumeApplicationTest, Can_Detect_Wrong_Command) {
    vector<string> args = {"fs", "paral", "2", "4", "5"};

    Act(args);

    Assert("wrong command.*");
}

TEST_F(ShapesVolumeApplicationTest, Can_Calculate_Cube_Volume) {
    vector<string> args = {"calc", "cube", "2"};

    Act(args);

    Assert("volume = 8.*");
}

TEST_F(ShapesVolumeApplicationTest, Can_Calculate_Cone_Volume) {
    vector<string> args = {"calc", "cone", "3", "2"};

    Act(args);

    Assert("volume = 18.*");
}

TEST_F(ShapesVolumeApplicationTest, Can_Calculate_Sphere_Volume) {
    vector<string> args = {"calc", "sphere", "4"};

    Act(args);

    Assert("volume = 268.*");
}

TEST_F(ShapesVolumeApplicationTest, Can_Calculate_Cylinder_Volume) {
    vector<string> args = {"calc", "cylinder", "2", "2"};

    Act(args);

    Assert("volume = 25.*");
}

TEST_F(ShapesVolumeApplicationTest, Can_Calculate_Parallelipiped_Volume) {
    vector<string> args = {"calc", "paral", "4", "2" , "2"};

    Act(args);

    Assert("volume = 16.*");
}

TEST_F(ShapesVolumeApplicationTest, Can_Calculate_Tetrahedron_Volume) {
    vector<string> args = {"calc", "tetr", "12"};

    Act(args);

    Assert("volume = 203.*");
}
