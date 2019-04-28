// Copyright 2019 Sadikov Artem

#ifndef MODULES_ARREARS_SERVICE_INCLUDE_ARREARS_SERVICE_H_
#define MODULES_ARREARS_SERVICE_INCLUDE_ARREARS_SERVICE_H_

class ArrearService {
 public:
    ArrearService(const int d, const int i,
                  const int g, const int t);
    ArrearService(const ArrearService& obj);

    void SetYearPay(double prog);
    void SetExpress();
    void SetDebt(const int d);
    void SetProcent(const int i);
    void SetRate(const int g);
    void SetTime(const int t);
    double GetYearPay();
    double GetExpress();
    double GetDebt();
    int GetProcent();
    int GetRate();
    int GetTime();

    double Fond();

 private:
    double YearPayVal(double prog);
    double ExpressPay();
    int debt;
    double express;
    int procent;
    double yearpay;
    int rate;
    int time;
};

#endif  // MODULES_ARREARS_SERVICE_INCLUDE_ARREARS_SERVICE_H_