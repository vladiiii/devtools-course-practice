// Copyright 2019 Perov Dima

#include "include/caesar_cipher_application.h"
#include <string>

std::string CaesarCipherApplication::operator()(int argc, const char** argv) {
  std::string result = "";
  std::string myFileInName = "";
  std::string myFileOutName = "";
  std::string myOperation = "";

  if (argc > 4) {
    int key = 0;
    myFileInName = argv[1];
    myFileOutName = argv[2];
    key = atoi(argv[3]);
    myOperation = argv[4];

    if (myOperation == "EN") {
      result = EncryptFile(myFileInName, myFileOutName, key);
    }

    if (myOperation == "DE") {
      result = DecryptFile(myFileInName, myFileOutName, key);
    }

    if (myOperation != "DE" && myOperation != "EN") {
      result = GetHelpMessage();
    }

  } else {
    result = GetHelpMessage();
  }

  if (result == "") {
    result = GetHelpMessage();
  }

  return result;
}

std::string CaesarCipherApplication::GetHelpMessage() {
  std::string helpMessage;
  helpMessage =
      "\nThis application encrypts/decrypts the contents of the file.\n";
  helpMessage += "Please provide arguments in the following format:\n";
  helpMessage += "1: File name(string) for operation;\n";
  helpMessage += "2: File name(string) to save the result;\n";
  helpMessage += "3: The key(int) to encrypt/decrypt operations;\n";
  helpMessage += "4: The operation(string): EN to Encrypt or DE to Decrypt;\n";
  return helpMessage;
}

std::string CaesarCipherApplication::DecryptFile(std::string myFileInName,
                                                 std::string myFileOutName,
                                                 int key) {
  fileText = "";
  if (ReadFile(myFileInName)) {
    fileText = cipher.Decrypt(fileText, key);
    WriteFile(myFileOutName);
  }
  return fileText;
}

std::string CaesarCipherApplication::EncryptFile(std::string myFileInName,
                                                 std::string myFileOutName,
                                                 int key) {
  fileText = "";
  if (ReadFile(myFileInName)) {
    fileText = cipher.Encrypt(fileText, key);
    WriteFile(myFileOutName);
  }
  return fileText;
}

bool CaesarCipherApplication::ReadFile(std::string myFileInName) {
  std::ifstream fileIn(myFileInName);
  if (!fileIn.is_open()) {
    return false;
  } else {
    fileText.assign((std::istreambuf_iterator<char>(fileIn.rdbuf())),
                    std::istreambuf_iterator<char>());
    fileIn.close();
  }
  return true;
}

void CaesarCipherApplication::WriteFile(std::string myFileOutName) {
  std::ofstream fileOut(myFileOutName);
  fileOut << fileText;
  fileOut.close();
}

