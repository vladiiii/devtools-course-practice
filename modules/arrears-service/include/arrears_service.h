// Copyright 2019 Sadikov Artem

#ifndef MODULES_ARREARS_SERVICE_INCLUDE_ARREARS_SERVICE_H_
#define MODULES_ARREARS_SERVICE_INCLUDE_ARREARS_SERVICE_H_

class ArrearService {
 public:
    ArrearService();
    ArrearService(const double d, const double r, const double y, const int t);
    ArrearService(const ArrearService& obj);
    ~ArrearService();

    double ExpressPay(int time, int proc);
    double YearPayVal(int proc, int time, double prog);
    double SumYears(int proc, int time, double prog);

 private:
    double debt;
    double rate;
    double yearpay;
    double *capital;
    int time;
};

#endif  // MODULES_ARREARS_SERVICE_INCLUDE_ARREARS_SERVICE_H_
