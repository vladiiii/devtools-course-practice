// Copyright 2019 Bykovskaya Alina

#ifndef MODULES_ROMA_NUMBER_INCLUDE_ROMANUMBER_H_
#define MODULES_ROMA_NUMBER_INCLUDE_ROMANUMBER_H_

#include <string>

class RomaNumber {
 private:
    std::string roma;
    int arabic;
    bool isStringCorrect(std::string);
    std::string RomaConvert(int, int);
 public:
    RomaNumber() : roma(""), arabic(0) { }
    explicit RomaNumber(std::string);
    explicit RomaNumber(int ar);
    void RomaToArab(std::string);
    void ArabToRoma(int ar);
    std::string GetRoma() { return roma; }
    int GetArabic() { return arabic; }
    void Print();
};
#endif  // MODULES_ROMA_NUMBER_INCLUDE_ROMANUMBER_H_
