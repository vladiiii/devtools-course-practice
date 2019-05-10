// Copyright 2019 Repin Vladimir
#ifndef MODULES_CAESAR_CIPHER_INCLUDE_CAESAR_CIPHER_APPLICATION_H_
#define MODULES_CAESAR_CIPHER_INCLUDE_CAESAR_CIPHER_APPLICATION_H_

#include <string>
#include <iostream>
#include <fstream>
#include "include/caesar_cipher.h"

class CaesarCipherApplication {
 protected:
  bool ReadFile(std::string myFileInName);
  void WriteFile(std::string myFileOutName);
  std::string fileText;
  CaesarCipher cipher;

 public:
  std::string operator()(int argc, const char** argv);
  std::string GetHelpMessage();
  std::string DecryptFile(std::string myFileInName, std::string myFileOutName,
                          int key);
  std::string EncryptFile(std::string myFileInName, std::string myFileOutName,
                          int key);
};

#endif  // MODULES_CAESAR_CIPHER_INCLUDE_CAESAR_CIPHER_APPLICATION_H_
