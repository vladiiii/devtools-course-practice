// Copyright 2019 Vikhrev Ivan
#ifndef MODULES_LCD_DIGITS_INCLUDE_LCD_DIGITS__H_
#define MODULES_LCD_DIGITS__INCLUDE_LCD_DIGITS__H_

#include <string>

class LCDDigits {
  public:
    static std::string lcd(const int& n);
    static std::string lcd(const std::string& s);
  private:
    static std::string decompose(const int& n);
    static std::string lcd_str(const std::string& s);
 
    static const std::string plus[3];
    static const std::string minus[3];
    static const std::string colon[3];
    static const std::string point[3];

    static const std::string zero[3];
    static const std::string one[3];
    static const std::string two[3];
    static const std::string three[3];
    static const std::string four[3];
    static const std::string five[3];
    static const std::string six[3];
    static const std::string seven[3];
    static const std::string eight[3];
    static const std::string nine[3];
};

#endif  // MODULES_LCD_DIGITS__INCLUDE_LCD_DIGITS__H_