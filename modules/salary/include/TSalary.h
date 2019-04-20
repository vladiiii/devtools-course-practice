// Copyright Irina Astafeva 2019

#ifndef MODULES_SALARY_INCLUDE_TSALARY_H_

#define MODULES_SALARY_INCLUDE_TSALARY_H_

class TSalary {
protected:
    int Salary;      // in month
    int Norm;        // hours in month
    int Overtime;    // hours in month
    int Vacantion;   // hours in month
    int WorkedHours; // hors in month
public:
    TSalary(int _Salary, int _Norm, int _WorkedHours, int Overtime, int Vacantion);
    double Payroll();
};

#endif // !MODULES_SALARY_INCLUDE_TSALARY_H_
