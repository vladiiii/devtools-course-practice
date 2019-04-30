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

TEST(Fedotov_Vlad_NumberSystemsConverter, Can_Create_With_Two_Arguments) {
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

TEST(Fedotov_Vlad_NumberSystemsConverter, CanCopy) {
    // Arrange
    NumberSystemsConverter conv("10", BIN);

    // Act & Assert
    ASSERT_NO_THROW(NumberSystemsConverter copyconv(conv));
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanCopyCorrectly) {
    // Arrange
    NumberSystemsConverter conv("10", BIN);

    // Act
    NumberSystemsConverter copyconv(conv);
    // Assert
    EXPECT_EQ(conv.getNumberInBin(), copyconv.getNumberInBin());
    EXPECT_EQ(conv.getNumberInOct(), copyconv.getNumberInOct());
    EXPECT_EQ(conv.getNumberInHex(), copyconv.getNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanAssign) {
    // Arrange
    NumberSystemsConverter conv("10", BIN);
    NumberSystemsConverter conv2("11", BIN);

    // Act & Assert
    ASSERT_NO_THROW(conv = conv2);
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanAssignCorrectly) {
    // Arrange
    NumberSystemsConverter conv("10", BIN);
    NumberSystemsConverter conv2("11", BIN);

    // Act
    conv = conv2;

    // Assert
    EXPECT_EQ(conv2.getNumberInBin(), conv.getNumberInBin());
    EXPECT_EQ(conv2.getNumberInOct(), conv.getNumberInOct());
    EXPECT_EQ(conv2.getNumberInHex(), conv.getNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanCompare) {
    // Arrange
    NumberSystemsConverter conv("10", BIN);
    NumberSystemsConverter conv2("11", BIN);
    bool flag;

    // Act & Assert
    ASSERT_NO_THROW(flag = conv == conv2);
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanCompareCorrectly_1) {
    // Arrange
    NumberSystemsConverter conv("10", BIN);
    NumberSystemsConverter conv2("11", BIN);
    bool flag;

    // Act & Assert
    EXPECT_FALSE(flag = conv == conv2);
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanCompareCorrectly_2) {
    // Arrange
    NumberSystemsConverter conv("10", BIN);
    NumberSystemsConverter conv2("11", BIN);
    bool flag;

    // Act & Assert
    EXPECT_TRUE(flag = conv != conv2);
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

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertOctToBinAndHex_1) {
    // Act & Assert
    NumberSystemsConverter conv("1", OCT);
    EXPECT_EQ("1", conv.getNumberInBin());
    EXPECT_EQ("1", conv.getNumberInOct());
    EXPECT_EQ("1", conv.getNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertOctToBinAndHex_2) {
    // Act & Assert
    NumberSystemsConverter conv("10", OCT);
    EXPECT_EQ("1000", conv.getNumberInBin());
    EXPECT_EQ("10", conv.getNumberInOct());
    EXPECT_EQ("8", conv.getNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertOctToBinAndHex_3) {
    // Act & Assert
    NumberSystemsConverter conv("010", OCT);
    EXPECT_EQ("1000", conv.getNumberInBin());
    EXPECT_EQ("10", conv.getNumberInOct());
    EXPECT_EQ("8", conv.getNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertHexToBinAndOct_1) {
    // Act & Assert
    NumberSystemsConverter conv("ABC", HEX);
    EXPECT_EQ("101010111100", conv.getNumberInBin());
    EXPECT_EQ("5274", conv.getNumberInOct());
    EXPECT_EQ("ABC", conv.getNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertHexToBinAndOct_2) {
    // Act & Assert
    NumberSystemsConverter conv("000ABC", HEX);
    EXPECT_EQ("101010111100", conv.getNumberInBin());
    EXPECT_EQ("5274", conv.getNumberInOct());
    EXPECT_EQ("ABC", conv.getNumberInHex());
}