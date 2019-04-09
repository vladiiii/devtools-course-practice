// Copyright 2019 Obolenskiy Arseniy
#include <gtest/gtest.h>
#include <string>
#include "include/vigenere_cipher.h"

TEST(VigenereCipherTest, Can_Replicate_Caesar_Cipher_With_Zero_Shift) {
    std::string message = "walrus";
    std::string key = "a";
    ASSERT_EQ(message, VigenereCipher::encrypt(message, key));
}

TEST(VigenereCipherTest, Can_Replicate_Caesar_Cipher_With_Shift_1) {
    const char shift = 1;
    std::string message = "walrus";
    std::string key = "b";
    std::string expected(message);
    for (unsigned i = 0; i < expected.size(); ++i) {
        int ch = expected[i] + shift;
        if (ch > 122)
            ch -= 26;
        expected[i] = ch;
    }
    ASSERT_EQ(expected, VigenereCipher::encrypt(message, key));
}

TEST(VigenereCipherTest, Can_Replicate_Caesar_Cipher_With_Shift_5) {
    const char shift = 5;
    std::string message = "walrus";
    std::string key = "f";
    std::string expected(message);
    for (unsigned i = 0; i < expected.size(); ++i) {
        int ch = expected[i] + shift;
        if (ch > 122)
            ch -= 26;
        expected[i] = ch;
    }
    ASSERT_EQ(expected, VigenereCipher::encrypt(message, key));
}

TEST(VigenereCipherTest, Can_Replicate_Caesar_Cipher_With_Shift_25) {
    const char shift = 25;
    std::string message = "walrus";
    std::string key = "z";
    std::string expected(message);
    for (unsigned i = 0; i < expected.size(); ++i) {
        int ch = expected[i] + shift;
        if (ch > 122)
            ch -= 26;
        expected[i] = ch;
    }
    ASSERT_EQ(expected, VigenereCipher::encrypt(message, key));
}

TEST(VigenereCipherTest, Throw_An_Exception_With_Incorrest_Key) {
    std::string message = "word";
    std::string key = "doo1";
    ASSERT_ANY_THROW(VigenereCipher::encrypt(message, key));
}

TEST(VigenereCipherTest, Can_Encrypt_Word_With_Key_With_The_Same_Size) {
    std::string message = "word";
    std::string key = "door";
    std::string expected = "zcfu";
    ASSERT_EQ(expected, VigenereCipher::encrypt(message, key));
}

TEST(VigenereCipherTest, Encrypting_And_Decrypting_Gives_Original_String) {
    std::string message = "Lorem ipsum";
    std::string key = "test";
    ASSERT_EQ(message, VigenereCipher::decrypt(
                        VigenereCipher::encrypt(message, key),
                        key));
}
