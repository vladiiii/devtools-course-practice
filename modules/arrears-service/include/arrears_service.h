// Copyright 2019 Sadikov Artem

#ifndef MODULES_ARREARS_SERVICE_INCLUDE_ARREARS_SERVICE_H_
#define MODULES_ARREARS_SERVICE_INCLUDE_ARREARS_SERVICE_H_

class ArrearService {
 public:
    ArrearService(const double d, const double e,
                  const int i, const int g,
                  const int t);
    ArrearService(const ArrearService& obj);

    double ExpressPay(int time, int proc);
    double YearPayVal(int proc, int time, double prog);
    double Fond(int proc, int t);

 private:
    double debt;
    double express;
    int procent;
    double yearpay;
    int rate;
    int time;
};

#endif  // MODULES_ARREARS_SERVICE_INCLUDE_ARREARS_SERVICE_H_