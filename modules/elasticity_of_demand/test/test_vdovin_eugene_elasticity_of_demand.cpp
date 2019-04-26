// Copyright 2019 Vdovin Eugene

#include <gtest/gtest.h>
#include "include/elasticity_of_demand.h"

TEST(ElasticityOfDemandTest, check_1_price_elasticity_of_demand) {
    // Arrange
    ElasticityOfDemand demand;

    // Act
    double elasticity = demand.price_elasticity_of_demand(100, 98,
                                                          100.0, 102.0);

    // Assert
    EXPECT_EQ(-1.0, elasticity);
}

TEST(ElasticityOfDemandTest, check_2_price_elasticity_of_demand) {
    // Arrange
    ElasticityOfDemand demand;

    // Act
    double elasticity = demand.price_elasticity_of_demand(100, 60,
                                                          100.0, 140.0);

    // Assert
    EXPECT_EQ(-1.5, elasticity);
}

TEST(ElasticityOfDemandTest, check_income_elasticity_of_demand) {
    // Arrange
    ElasticityOfDemand demand;

    // Act
    double elasticity = demand.income_elasticity_of_demand(100, 102,
                                                           10000.0, 10200.0);

    // Assert
    EXPECT_EQ(1.0, elasticity);
}

TEST(ElasticityOfDemandTest, check_cross_elasticity_of_demand) {
    // Arrange
    ElasticityOfDemand demand;

    // Act
    double elasticity = demand.cross_elasticity_of_demand(100, 102,
                                                          100.0, 102.0);

    // Assert
    EXPECT_EQ(1.0, elasticity);
}