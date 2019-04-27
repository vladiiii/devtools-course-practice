// Copyright 2019 Malkin Danil

#ifndef MODULES_POLYNOMS_INCLUDE_POLYNOM_H_
#define MODULES_POLYNOMS_INCLUDE_POLYNOM_H_

#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;
class Monom;

class Polynom {
	
public:
	Polynom();
	explicit Polynom(double coff);
	Polynom(const Polynom& rhs);
	Polynom(const vector<Monom>& mons);
	Polynom(const Monom& mon);

	Polynom& operator=(const Polynom& z);

	void AddMonom(const Monom& m);
	string ToString();

	bool operator==(const Polynom& rhs) const;
	bool operator!=(const Polynom& rhs) const;

	Polynom operator+(const Polynom& rhs);
	Polynom operator-(const Polynom& rhs);
	Polynom operator*(const Polynom& rhs);
	Polynom operator/(const Monom& m);

	double CalculateResult(const map<char, double>& in_params);

private:
	int Contains(const vector<Monom>& vec, const Monom& m) const;

private:
	vector<Monom> monoms;
};
#endif  // MODULES_POLYNOMS_INCLUDE_POLYNOM_H_