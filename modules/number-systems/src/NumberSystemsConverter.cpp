#include "include/NumberSystemsConverter.h"

NumberSystemsConverter::NumberSystemsConverter(string input_number = 0, SysBase input_base = bin) {
    switch(input_base) {
     case 'bin':
        NumberInBin = input_number;
        NumberInOct = ConvertBinToOct(input_number);
        NumberInHex = ConvertBinToHex(input_number);
        break;
     case 'oct':
        NumberInBin = ConvertOctToBin(input_number);
        NumberInOct = input_number;
        NumberInHex = ConvertBinToHex(NumberInBin);
     case 'hex':
        NumberInBin = ConvertHexToBin(input_number);
        NumberInOct = ConvertBinToOct(NumberInBin);
        NumberInHex = ConvertBinToHex(NumberInBin);
    }
}

NumberSystemsConverter::NumberSystemsConverter(const NumberSystemsConverter &n) {
    NumberInBin = n.NumberInBin;
    NumberInOct = n.NumberInOct;
    NumberInHex = n.NumberInHex;
}

NumberSystemsConverter& NumberSystemsConverter::operator=(const NumberSystemsConverter& n) {
    if (this != &n) {
        NumberInBin = n.NumberInBin;
        NumberInOct = n.NumberInOct;
        NumberInHex = n.NumberInHex;
    }

    return *this;
}

string NumberSystemsConverter::getNumberInBin() const {
    return NumberInBin;
}

string NumberSystemsConverter::getNumberInOct() const {
    return NumberInOct;
}

string NumberSystemsConverter::getNumberInHex() const {
    return NumberInHex;
}

/*NumberSystemsConverter NumberSystemsConverter::operator + (const NumberSystemsConverter& z) const;
NumberSystemsConverter NumberSystemsConverter::operator - (const NumberSystemsConverter& z) const;
NumberSystemsConverter NumberSystemsConverter::operator * (const NumberSystemsConverter& z) const;
NumberSystemsConverter NumberSystemsConverter::operator / (const NumberSystemsConverter& z) const;
*/
bool NumberSystemsConverter::operator == (const NumberSystemsConverter& n) const {
    return (NumberInBin == n.NumberInBin);
}
bool NumberSystemsConverter::operator != (const NumberSystemsConverter& n) const {
    return !(NumberInBin == n.NumberInBin);
}

string NumberSystemsConverter::ConvertBinToOct(const string n) {
    string result;
    int str_length = n.length();
    int additional_zeros = 0;
    if (str_length % 3 != 0)
        additional_zeros = 3 - str_length % 3;
    result = n; // copy strings
    // insert additional zeros to the beginning of the string
    for (int i = 0; i < additional_zeros; i++) {
        result.insert(result.begin(), '0');
    }
    // convert each triad to digit in oct
    for (int it = 0; it < str_length / 3; it = it + 1) {
        string triad = result.substr(it, 3);
        int int_triad = atoi(triad.c_str());
        int digit_oct = -1;

        switch (int_triad) {
        case 0:
            digit_oct = 0;
            break;
        case 1:
            digit_oct = 1;
            break;
        case 10:
            digit_oct = 2;
            break;
        case 11:
            digit_oct = 3;
            break;
        case 100:
            digit_oct = 4;
            break;
        case 101:
            digit_oct = 5;
            break;
        case 110:
            digit_oct = 6;
            break;
        case 111:
            digit_oct = 7;
            break;
        default:
            throw("Wrong int_triad switch");
            break;
        }
        
        result.replace(it, 3, to_string(digit_oct)); // replace triad with digit in oct
    }

    return result;
    }
}

string NumberSystemsConverter::ConvertBinToHex(const string n) {

}

string NumberSystemsConverter::ConvertOctToBin(const string n) {

}

string NumberSystemsConverter::ConvertHexToBin(const string n) {

}