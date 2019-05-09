// Copyright 2019 Bykovskaya Alina

#ifndef MODULES_ROMA_NUMBER_INCLUDE_ROMANUMBER_H_
#define MODULES_ROMA_NUMBER_INCLUDE_ROMANUMBER_H_

#include <string>
#include <iostream>

class RomaNumber {
 private:
    std::string roma_;
    int arabic_;
    std::string RomaConvert(int, int);
 public:
    RomaNumber() : roma_(""), arabic_(0) { }
    explicit RomaNumber(char*);
    explicit RomaNumber(int ar);
	bool IsRomaStringCorrect(const char*) const;
	bool IsArabStringCorrect(const char*) const;
    void RomaToArab(std::string);
    void ArabToRoma(int ar);
    std::string GetRoma() { return roma_; }
    int GetArabic() { return arabic_; }
    friend std::ostream& operator<<(std::ostream &out,
        const RomaNumber a);
};
#endif  // MODULES_ROMA_NUMBER_INCLUDE_ROMANUMBER_H_
