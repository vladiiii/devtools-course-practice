// Copyright 2019 Perov Dima
#include "include/caesar_cipher_application.h"

int main(int argc, char const **argv) {
  CaesarCipherApplication myApplication;
  std::cout << myApplication(argc, argv);
  return 0;
}

