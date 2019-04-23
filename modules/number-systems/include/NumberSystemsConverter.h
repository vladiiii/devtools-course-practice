// This class represents a number which is being stored in differents number systems at the same time.
// Copyright 2019 Fedotov Vlad

#ifndef MODULES_NUMBER_SYSTEMS_INCLUDE_NUMBER_SYSTEMS_H_
#define MODULES_NUMBER_SYSTEMS_INCLUDE_NUMBER_SYSTEMS_H_

enum SysBase {bin, oct, hex};

class NumberSystems {
 public:
    NumberSystems(string input_number, SysBase input_base);
    NumberSystems(const NumberSystems &n);
    NumberSystems& operator=(const NumberSystems& n);

    int 
    double getRe() const;
    double getIm() const;
    void setRe(const double real);
    void setIm(const double imaginary);

    /*NumberSystems operator + (const NumberSystems& z) const;
    NumberSystems operator - (const NumberSystems& z) const;
    NumberSystems operator * (const NumberSystems& z) const;
    NumberSystems operator / (const NumberSystems& z) const;
    */
    bool operator == (const NumberSystems& n) const;
    bool operator != (const NumberSystems& n) const;
 private:
    int NumberInBin;
    int NumberInOct;
    int NumberInHex;
    //int NumberInDec;
};

#endif // MODULES_NUMBER_SYSTEMS_INCLUDE_NUMBER_SYSTEMS_H_