// Copyright 2019 Kumbrasev Pavel

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kumbrasev_Pavel_ComplexNumberTest, Zero_Number_Does_Not_Change_Value) {
    // Arrange
	ComplexNumber test_number(2, 0);

    // Act
	ComplexNumber result_complex = test_number + ComplexNumber(0, 0);

    // Assert
    EXPECT_EQ(result_complex, test_number);
}

TEST(Kumbrasev_Pavel_ComplexNumberTest, Can_Copy_Class_Instances) {
	// Arrange
	ComplexNumber test_number(2, 0);

	// Act
	ComplexNumber result_complex(test_number);

	// Assert
	EXPECT_EQ(result_complex, test_number);
}
