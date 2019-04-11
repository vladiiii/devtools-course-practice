// Copyright 2019 Vdovin Eugene

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Vdovin_Eugene_ComplexNumberTest, Can_Create_Zero_Two_Way) {
    bool f = false;

    ComplexNumber cn(0.0, 0.0);
    ComplexNumber cn2;

    if (cn2 == cn) {
        f = true;
    } else {
        f = false;
    }

    EXPECT_EQ(true, f);
}

TEST(Vdovin_Eugene_ComplexNumberTest, Work_Triple_Assignment) {
    bool f = false;

    ComplexNumber cn1(3.0, 4.0);
    ComplexNumber cn2(-5.0, 6.3);
    ComplexNumber cn3(-8.0, -9.3);

    cn1 = cn2 = cn3;

    if ((cn1 == cn3) && (cn2 == cn3)) {
        f = true;
    } else {
        f = false;
    }

    EXPECT_EQ(true, f);
}

TEST(Vdovin_Eugene_ComplexNumberTest, Mult_And_Div_Compensation) {
    bool f = false;

    // Only at such coefficients, otherwise the computational error is large

    ComplexNumber cn1(4.0, 4.0);
    ComplexNumber cn2(5.0, 5.0);
    ComplexNumber cn3;

    cn3 = (cn1 * cn2) / cn1;

    if (cn2 == cn3) {
        f = true;
    } else {
        f = false;
    }

    EXPECT_EQ(true, f);
}
