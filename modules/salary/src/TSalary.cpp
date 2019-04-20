// Copyright Irina Astafeva 2019

#include "TSalary.h"

TSalary::TSalary(int _Salary, int _Norm, int _WorkedHours, int _Overtime, int _Vacantion) {
    if (_Salary <= 0 || _Norm <= 0 || _WorkedHours < 0 || _Overtime < 0 || _Vacantion < 0 || _WorkedHours + _Overtime - _Vacantion < 0) throw - 1;
    Salary = _Salary;
    Norm = _Norm;
    Overtime = _Overtime;
    Vacantion = _Vacantion;
    WorkedHours = _WorkedHours;
}

double TSalary::Payroll() {
    return Salary / Norm * (WorkedHours + Overtime - Vacantion);
}
