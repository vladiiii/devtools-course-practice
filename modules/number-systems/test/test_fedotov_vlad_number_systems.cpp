// Copyright 2019 Fedotov Vlad

#include <gtest/gtest.h>
#include <string>
#include "include/NumberSystemsConverter.h"

TEST(Fedotov_Vlad_NumberSystemsConverter, Can_Create_With_No_Arguments) {
    // Act & Assert
    ASSERT_NO_THROW(NumberSystemsConverter());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, Can_Create_With_No_Arguments_Correctly) {
    // Act & Assert
    NumberSystemsConverter conv;
    EXPECT_EQ("0", conv.getNumberInBin());
    EXPECT_EQ("0", conv.getNumberInHex());
    EXPECT_EQ("0", conv.getNumberInOct());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, Can_Create_With_One_Argument) {
    // Act & Assert
    ASSERT_NO_THROW(NumberSystemsConverter("1010"));
}

TEST(Fedotov_Vlad_NumberSystemsConverter, Can_Create_With_One_Argument_Correctly) {
    // Act & Assert
    NumberSystemsConverter conv("1010");
    EXPECT_EQ("1010", conv.getNumberInBin());
    EXPECT_EQ("12", conv.getNumberInOct());
    EXPECT_EQ("A", conv.getNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, Can_Create_With_Two_Argument) {
    // Act & Assert
    ASSERT_NO_THROW(NumberSystemsConverter("1010", BIN));
}

TEST(Fedotov_Vlad_NumberSystemsConverter, Can_Create_With_Two_Arguments_Correctly) {
    // Act & Assert
    NumberSystemsConverter conv("1010", BIN);
    EXPECT_EQ("1010", conv.getNumberInBin());
    EXPECT_EQ("12", conv.getNumberInOct());
    EXPECT_EQ("A", conv.getNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertBinToOctAndHex_1) {
    // Act & Assert
    NumberSystemsConverter conv("1", BIN);
    EXPECT_EQ("1", conv.getNumberInBin());
    EXPECT_EQ("1", conv.getNumberInOct());
    EXPECT_EQ("1", conv.getNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertBinToOctAndHex_2) {
    // Act & Assert
    NumberSystemsConverter conv("1000", BIN);
    EXPECT_EQ("1000", conv.getNumberInBin());
    EXPECT_EQ("10", conv.getNumberInOct());
    EXPECT_EQ("8", conv.getNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertBinToOctAndHex_3) {
    // Act & Assert
    NumberSystemsConverter conv("0", BIN);
    EXPECT_EQ("0", conv.getNumberInBin());
    EXPECT_EQ("0", conv.getNumberInOct());
    EXPECT_EQ("0", conv.getNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertBinToOctAndHex_4) {
    // Act & Assert
    NumberSystemsConverter conv("11111111", BIN);
    EXPECT_EQ("11111111", conv.getNumberInBin());
    EXPECT_EQ("377", conv.getNumberInOct());
    EXPECT_EQ("FF", conv.getNumberInHex());
}
