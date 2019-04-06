// Copyright 2019 Obolenskiy Arseniy
#include <string>
#include "include/vigenere_cipher.h"

std::string VigenereCipher::encrypt(const std::string &message,
                                    const std::string& key) {
    std::string nkey(message);
    for (unsigned i = 0; i < nkey.size(); ++i)
        nkey[i] = tolower(key[i % key.size()]);
    std::string result(message);
    for (unsigned i = 0; i < result.size(); ++i) {
        if (isalpha(result[i])) {
            if (isupper(result[i]))
                result[i] = (result[i] - 'A' + nkey[i] - 'a') % 26 + 'A';
            else
                result[i] = (result[i] - 'a' + nkey[i] - 'a') % 26 + 'a';
        }
    }
    return result;
}

std::string VigenereCipher::decrypt(const std::string &message,
                                    const std::string& key) {
    std::string nkey(message);
    for (unsigned i = 0; i < nkey.size(); ++i)
        nkey[i] = tolower(key[i % key.size()]);
    std::string result(message);
    for (unsigned i = 0; i < result.size(); ++i) {
        if (isalpha(result[i])) {
            if (isupper(result[i]))
                result[i] = (result[i] - 'A' - nkey[i] + 'a' + 26) % 26 + 'A';
            else
                result[i] = (result[i] - 'a' - nkey[i] + 'a' + 26) % 26 + 'a';
        }
    }
    return result;
}
