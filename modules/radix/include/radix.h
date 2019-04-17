// Copyright 2019 Valiullin Damir

#ifndef MODULES_RADIX_INCLUDE_RADIX_H_
#define MODULES_RADIX_INCLUDE_RADIX_H_

class Radix {
 public:
    explicit Radix(const int size = 1);
    Radix(int* mas, const int size);
    ~Radix();

    void radixSort(int* mas, const int size);
    int getSize() const;
    void setSize(const int size);
    int howMuchMem();

 private:
    void resetCounter();
    void sortMas(int* mas);
    void radix(int* mas, int* tempMas, int byte);
    void lastRadix(int* mas, int* tempMas);

    int size_;
    int* tempMas_;
    int* counter_;
    int* offset_;
};

#endif  // MODULES_RADIX_INCLUDE_RADIX_H_
