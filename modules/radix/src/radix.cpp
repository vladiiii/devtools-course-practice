// Copyright 2019 Valiullin Damir

#include "include/radix.h"

#include <string>

Radix::Radix() : size_(1) {
    counter_ = new int[256];
    offset_ = new int[256];
    tempMas_ = new int[1];
}

Radix::Radix(const int size) {
    if (size <= 0) {
        throw std::string("Size can't be zero or lower");
    }
    else {
        size_ = size;

        counter_ = new int[256];
        offset_ = new int[256];
        tempMas_ = new int[size_];
    }
}

Radix::Radix(int* mas, const int size) {
    if (size <= 0) {
        throw std::string("Size can't be zero or lower");
    }
    else {
        size_ = size;

        counter_ = new int[256];
        offset_ = new int[256];
        tempMas_ = new int[size];

        sortMas(mas);
    }
}

Radix::~Radix() {
    delete[] tempMas_;
    delete[] offset_;
    delete[] counter_;
}

void Radix::sort(int* mas, const int size) {
    if (size <= 0) {
        throw std::string("Size can't be zero or lower");
    } 
    else {

        if (size != size_) {
            delete[] tempMas_;

            size_ = size;
            tempMas_ = new int[size_];
        }

        radixSort(mas, tempMas_, 0);
        radixSort(tempMas_, mas, 1);
        radixSort(mas, tempMas_, 2);
        lastRadixSort(tempMas_, mas);
    }
}

int Radix::getSize() const {
    return size_;
}

void Radix::setSize(const int size) {
    if (size <= 0) {
        throw std::string("Size can't be zero or lower");
    }
    else {

        if (size != size_) {
            delete[] tempMas_;

            size_ = size;
            tempMas_ = new int[size_];
        }
    }
}
int Radix::howMuchMem() {
    int mem = 0;
    mem += 2 * 256 * 4 + 4;
    mem += size_ * 4;
    return mem;
}

void Radix::resetCounter() {
    for (int i = 0; i < 256; ++i) {
        counter_[i] = 0;
    }
}

void Radix::sortMas(int* mas) {
    radixSort(mas, tempMas_, 0);
    radixSort(tempMas_, mas, 1);
    radixSort(mas, tempMas_, 2);
    lastRadixSort(tempMas_, mas);
}

void Radix::radixSort(int* mas, int* tempMas, int byte) {
    unsigned char* c = (unsigned char*)mas;
    offset_[0] = 0;
    resetCounter();

    for (int i = 0; i < size_; ++i) {
        counter_[c[i * 4 + byte]]++;
    }

    for (int i = 1; i < 256; ++i) {
        offset_[i] = counter_[i - 1] + offset_[i - 1];
    }

    for (int i = 0; i < size_; ++i) {
        tempMas[offset_[c[i * 4 + byte]]++] = mas[i];
    }
}

void Radix::lastRadixSort(int* mas, int* tempMas) {
    char* c = (char*)mas;
    offset_[0] = 0;
    resetCounter();

    for (int i = 0; i < size_; ++i) {
        counter_[c[i * 4 + 3] + 128]++;
    }

    for (int i = 1; i < 256; ++i) {
        offset_[i] = counter_[i - 1] + offset_[i - 1];
    }

    for (int i = 0; i < size_; ++i) {
        tempMas[offset_[c[i * 4 + 3] + 128]++] = mas[i];
    }
}
