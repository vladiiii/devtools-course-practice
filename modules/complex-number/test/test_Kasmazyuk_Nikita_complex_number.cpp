// Copyright 2019 Kasmazyuk Nikita

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Kasmazyuk_Nikita_ComplexNumberTest, Can_Create_Zero) {

    double re = 0.0;
    double im = 0.0;
    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}
