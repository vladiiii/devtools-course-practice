// Copyright 2019 Dudchenko Anton

#include <vector>
using namespace std;

class BatcherSort
{
private:
    vector<int> v;
    void Shuffle(int l, int r);
    void Compexch(int& a, int& b);
    void Unshuffle(int l, int r);
    void Sort(int l, int r);

public:
	BatcherSort(vector<int> = {});
    ~BatcherSort();
    vector<int> GetVec();
    int GetSize();
    void BatcherMergeSort(int l, int r);
    friend ostream& operator<<(ostream &out, const BatcherSort b);
};

