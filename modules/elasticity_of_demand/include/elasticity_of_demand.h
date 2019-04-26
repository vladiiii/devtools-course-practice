// Copyright 2019 Vdovin Eugene

#ifndef MODULES_COMPLEX_NUMBER_INCLUDE_ELASTICITY_OF_DEMAND_H_
#define MODULES_COMPLEX_NUMBER_INCLUDE_ELASTICITY_OF_DEMAND_H_

class ElasticityOfDemand {
  public:
    ElasticityOfDemand();

    double price_elasticity_of_demand(int quantity_1, int quantity_2,
    double price_1, double price_2);

    double income_elasticity_of_demand(int quantity_1, int quantity_2,
    double income_1, double income_2);

    double cross_elasticity_of_demand(int quantity_1_product_1,
    int quantity_2_product_1, double price_1_product_2,
    double price_2_product_2);
};

#endif  // MODULES_COMPLEX_NUMBER_INCLUDE_ELASTICITY_OF_DEMAND_H_
