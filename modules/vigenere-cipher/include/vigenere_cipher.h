// Copyright 2019 Obolenskiy Arseniy
#ifndef MODULES_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_H_
#define MODULES_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_H_
#include <string>

class VigenereCipher {
 public:
    static void encrypt(const std::string &message, const std::string& key);
    static void decrypt(const std::string &message, const std::string& key);
}

#endif  // MODULES_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_H_
