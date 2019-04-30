// This class represents a number which is being stored in differents number systems at the same time.
// It is necessary to indicate the base number system when you create an object (the parameter of constructor).
// Copyright 2019 Fedotov Vlad

#ifndef MODULES_NUMBER_SYSTEMS_INCLUDE_NUMBER_SYSTEMS_CONVERTER_H_
#define MODULES_NUMBER_SYSTEMS_INCLUDE_NUMBER_SYSTEMS_CONVERTER_H_
#include <string>
using namespace std;

enum SysBase {BIN, OCT, HEX};

class NumberSystemsConverter {
 public:
    NumberSystemsConverter(string input_number = "0", SysBase input_base = BIN);
    NumberSystemsConverter(const NumberSystemsConverter &n);
    NumberSystemsConverter& operator=(const NumberSystemsConverter& n);

    string getNumberInBin() const;
    string getNumberInOct() const;
    string getNumberInHex() const;

    /*NumberSystemsConverter operator + (const NumberSystemsConverter& z) const;
    NumberSystemsConverter operator - (const NumberSystemsConverter& z) const;
    NumberSystemsConverter operator * (const NumberSystemsConverter& z) const;
    NumberSystemsConverter operator / (const NumberSystemsConverter& z) const;
    */
    bool operator == (const NumberSystemsConverter& n) const;
    bool operator != (const NumberSystemsConverter& n) const;
 private:
    string NumberInBin;
    string NumberInOct;
    string NumberInHex;
    // string NumberInDec;

    string ConvertBinToOct(const string n);
    string ConvertBinToHex(const string n);
    string ConvertOctToBin(const string n);
    string ConvertHexToBin(const string n);
    string CutFrontZeros(const string n);
};

#endif // MODULES_NUMBER_SYSTEMS_INCLUDE_NUMBER_SYSTEMS_CONVERTER_H_