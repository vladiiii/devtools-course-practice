// Copyright 2019 Obolenskiy Arseniy
#include <string>
#include <stdexcept>
#include "include/vigenere_cipher.h"

std::string VigenereCipher::expand_key(const std::string &key, int size) {
    std::string nkey;
    nkey.resize(size);
    for (unsigned i = 0; i < nkey.size(); ++i) {
        if (!isalpha(key[i % key.size()]))
            throw std::runtime_error("Key should be alphabetic");
        nkey[i] = tolower(key[i % key.size()]);
    }
    return nkey;
}

std::string VigenereCipher::encrypt(const std::string &message,
                                    const std::string &key) {
    if (key.size() == 0)
        return message;
    std::string nkey = expand_key(key, message.size());
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
                                    const std::string &key) {
    if (key.size() == 0)
        return message;
    std::string nkey = expand_key(key, message.size());
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
