#include "include/NumberSystemsConverter.h"

NumberSystemsConverter::NumberSystemsConverter(std::string input_number, SysBase input_base) {
    switch(input_base) {
     case BIN:
        NumberInBin = CutFrontZeros(input_number);
        NumberInOct = CutFrontZeros(ConvertBinToOct(input_number));
        NumberInHex = CutFrontZeros(ConvertBinToHex(input_number));
        break;
     case OCT:
        NumberInBin = CutFrontZeros(ConvertOctToBin(input_number));
        NumberInOct = CutFrontZeros(input_number);
        NumberInHex = CutFrontZeros(ConvertBinToHex(NumberInBin));
        break;
     case HEX:
        NumberInBin = CutFrontZeros(ConvertHexToBin(input_number));
        NumberInOct = CutFrontZeros(ConvertBinToOct(NumberInBin));
        NumberInHex = CutFrontZeros(ConvertBinToHex(NumberInBin));
        break;
     default:
        throw("The second argument must be BIN, OCT or HEX!");
        break;
    }
}

NumberSystemsConverter::NumberSystemsConverter(const NumberSystemsConverter &n) {
    NumberInBin = CutFrontZeros(n.NumberInBin);
    NumberInOct = CutFrontZeros(n.NumberInOct);
    NumberInHex = CutFrontZeros(n.NumberInHex);
}

NumberSystemsConverter& NumberSystemsConverter::operator=(const NumberSystemsConverter& n) {
    if (this != &n) {
        NumberInBin = CutFrontZeros(n.NumberInBin);
        NumberInOct = CutFrontZeros(n.NumberInOct);
        NumberInHex = CutFrontZeros(n.NumberInHex);
    }

    return *this;
}

std::string NumberSystemsConverter::getNumberInBin() const {
    return NumberInBin;
}

std::string NumberSystemsConverter::getNumberInOct() const {
    return NumberInOct;
}

std::string NumberSystemsConverter::getNumberInHex() const {
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

std::string NumberSystemsConverter::ConvertBinToOct(const std::string n) {
    std::string result;
    int str_length = n.std::string::length();
    int additional_zeros = 0;
    if (str_length % 3 != 0)
        additional_zeros = 3 - str_length % 3;
    result = n;  // copy std::strings
    // insert additional zeros to the beginning of the std::string
    for (int i = 0; i < additional_zeros; i++) {
        result.std::string::insert(result.std::string::begin(), '0');
    }
    str_length = result.std::string::length();
    // convert each triad to digit in oct
    for (int it = 0; it < str_length / 3; it = it + 1) {
        std::string triad = result.std::string::substr(it, 3);
        int int_triad = atoi(triad.std::string::c_str());
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
        
        result.replace(it, 3, std::to_string(digit_oct));  // replace triad with digit in oct
    }

    return result;    
}

std::string NumberSystemsConverter::ConvertBinToHex(const std::string n) {
    std::string result;
    int str_length = n.std::string::length();
    int additional_zeros = 0;
    if (str_length % 4 != 0)
        additional_zeros = 4 - str_length % 4;
    result = n;  // copy std::strings
                 // insert additional zeros to the beginning of the std::string
    for (int i = 0; i < additional_zeros; i++) {
        result.std::string::insert(result.std::string::begin(), '0');
    }
    str_length = result.std::string::length();
    // convert each tetrad to digit in hex
    for (int it = 0; it < str_length / 4; it = it + 1) {
        std::string tetrad = result.std::string::substr(it, 4);
        int int_tetrad = atoi(tetrad.std::string::c_str());
        std::string digit_hex = "-1";

        switch (int_tetrad) {
        case 0:
            digit_hex = '0';
            break;
        case 1:
            digit_hex = '1';
            break;
        case 10:
            digit_hex = '2';
            break;
        case 11:
            digit_hex = '3';
            break;
        case 100:
            digit_hex = '4';
            break;
        case 101:
            digit_hex = '5';
            break;
        case 110:
            digit_hex = '6';
            break;
        case 111:
            digit_hex = '7';
            break;
        case 1000:
            digit_hex = '8';
            break;
        case 1001:
            digit_hex = '9';
            break;
        case 1010:
            digit_hex = 'A';
            break;
        case 1011:
            digit_hex = 'B';
            break;
        case 1100:
            digit_hex = 'C';
            break;
        case 1101:
            digit_hex = 'D';
            break;
        case 1110:
            digit_hex = 'E';
            break;
        case 1111:
            digit_hex = 'F';
            break;
        default:
            throw("Wrong int_tetrad switch");
            break;
        }

        result.replace(it, 4, digit_hex); // replace tetrad with digit in hex
    }
    return result;
}

std::string NumberSystemsConverter::ConvertOctToBin(const std::string n) {
    std::string result;
    int str_length = n.std::string::length();
    result = n;  // copy std::strings

    for (int it = 0; it < str_length * 3; it = it +3) {
        int oct_digit = atoi(result.std::string::substr(it, 1).std::string::c_str());
        std::string triad = "-1";

        switch (oct_digit) {
        case 0:
            triad = "000";
            break;
        case 1:
            triad = "001";
            break;
        case 2:
            triad = "010";
            break;
        case 3:
            triad = "011";
            break;
        case 4:
            triad = "100";
            break;
        case 5:
            triad = "101";
            break;
        case 6:
            triad = "110";
            break;
        case 7:
            triad = "111";
            break;
        default:
            throw("Wrong oct_digit switch");
            break;
        }
        result.replace(it, 1, triad);
    }

    return result;
}

std::string NumberSystemsConverter::ConvertHexToBin(const std::string n) {
    std::string result;
    int str_length = n.std::string::length();
    result = n;  // copy std::strings

    for (int it = 0; it < str_length * 4; it = it + 4) {
        std::string hex_digit = result.std::string::substr(it, 1);
        const char* char_hex_digit = hex_digit.std::string::c_str();
        std::string tetrad = "-1";

        switch (*char_hex_digit) {
        case '0':
            tetrad = "0000";
            break;
        case '1':
            tetrad = "0001";
            break;
        case '2':
            tetrad = "0010";
            break;
        case '3':
            tetrad = "0011";
            break;
        case '4':
            tetrad = "0100";
            break;
        case '5':
            tetrad = "0101";
            break;
        case '6':
            tetrad = "0110";
            break;
        case '7':
            tetrad = "0111";
            break;
        case '8':
            tetrad = "1000";
            break;
        case '9':
            tetrad = "1001";
            break;
        case 'A':
            tetrad = "1010";
            break;
        case 'B':
            tetrad = "1011";
            break;
        case 'C':
            tetrad = "1100";
            break;
        case 'D':
            tetrad = "1101";
            break;
        case 'E':
            tetrad = "1110";
            break;
        case 'F':
            tetrad = "1111";
            break;
        default:
            throw("Wrong char_hex_digit switch");
            break;
        }
        result.replace(it, 1, tetrad);
    }

    return result;
}

std::string NumberSystemsConverter::CutFrontZeros(const std::string n) {
    std::string result = n;
    if (result.std::string::length() > 1) {
        while (result.std::string::substr(0, 1) == "0") {
            result.erase(result.std::string::begin());
        }
    }
    return result;
}

/*NumberSystemsConverter NumberSystemsConverter::operator + (const NumberSystemsConverter& z) const {
    std::string first_bin, second_bin, result_bin;
    first_bin = this->getNumberInBin;
    second_bin = z.getNumberInBin;



    NumberSystemsConverter result(result_bin, BIN);
    return result;
}
*/