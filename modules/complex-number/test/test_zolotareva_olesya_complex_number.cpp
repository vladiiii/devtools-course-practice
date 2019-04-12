//Copyright 2019 by Zolotareva Olesya

#include "math.h"

#include <gtest/gtest.h>

#include "include/complex_number.h"

# define M_PI           3.14159265358979323846  /* pi */


TEST(Zolotareva_Olesya_NumberComplex_test, Can_distribute_one) {
	//arrange
	ComplexNumber num1(2.0, 3.0);
	ComplexNumber num2(1.0, 4.0);
	ComplexNumber num3(5.0, 6.0);

	//act
	ComplexNumber res = (num1 + num2)*(num1 + num3);

	//assert
	EXPECT_FLOAT_EQ(-53.0, res.getRe());
	EXPECT_FLOAT_EQ(76.0, res.getIm());
}

TEST(Zolotareva_Olesya_NumberComplex_test, Can_distribute_two) {
	//arrange
	ComplexNumber num1(2.0, 3.0);
	ComplexNumber num2(1.0, 4.0);
	ComplexNumber num3(5.0, 6.0);

	//act
	ComplexNumber res = (num1 * num2) + (num1 * num3);

	//assert
	EXPECT_FLOAT_EQ(-18.0, res.getRe());
	EXPECT_FLOAT_EQ(34.0, res.getIm());
}



TEST(Zolotareva_Olesya_NumberComplex_test, Can_complex_logarifm) {
	//arrange
	double Re = 3.0;
	double Im = 4.0;

	//act
	double R = sqrt(pow(Re, 2) + pow(Im, 2));
	double Phi = Re / Im;

	Re = log10(R);
	Im = Phi + 2 * M_PI;

	ComplexNumber res;
	//assert
	EXPECT_FLOAT_EQ(Re, res.getRe());
	EXPECT_FLOAT_EQ(Im, res.getIm());
}
