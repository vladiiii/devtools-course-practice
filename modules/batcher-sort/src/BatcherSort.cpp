// Copyright 2019 Dudchenko Anton

#include <iostream>
#include "BatcherSort.h"
#include <algorithm>

using namespace std;

BatcherSort::BatcherSort(vector<int> vec) :v(vec) 
{
	if ((!(v.size() && !(v.size() & (v.size() - 1)))) && (v.size() != 0))
		throw -1;
}

BatcherSort::~BatcherSort()
{
    v.clear();
}

void BatcherSort::Shuffle(int l, int r)
{
    int i, j;
    int m = (l + r) / 2;
    vector<int> tmp(v.size());

    if (r - l + 1 <= 1) 
        return;

    for (j = 0, i = l; i <= m; j += 2, i++) 
        tmp[j] = v[i];

    for (j = 1, i = m + 1; i <= r; j += 2, i++) 
        tmp[j] = v[i];

    for (i = l; i <= r; i++) 
        v[i] = tmp[i - l];

    tmp.clear();
}

void BatcherSort::Compexch(int& a, int& b)
{
    if (b < a)
        std::swap(a, b);
}

void BatcherSort::Unshuffle(int l, int r)
{
    int i, j;
    int m = (l + r) / 2;
    vector<int> tmp(v.size());
    
    if (r - l + 1 <= 1) 
        return;

    for (j = 0, i = l; i <= r; j++, i += 2) 
        tmp[j] = v[i];

    for (j = m + 1 - l, i = l + 1; i <= r; j++, i += 2) 
        tmp[j] = v[i];

    for (i = l; i <= r; i++) 
        v[i] = tmp[i - l];

    tmp.clear();
}

void BatcherSort::Sort(int l, int r)
{
    int m = (l + r) / 2;
    int i;

    if (r - l + 1 <= 1)
        return;

    if (r - l + 1 == 2) {
        Compexch(v[l], v[r]);
        return;
    }

    Unshuffle(l, r);
    Sort(l, m);
    Sort(m + 1, r);
    Shuffle(l, r);

    for (i = l; i < r; i++) 
        Compexch(v[i], v[i + 1]);
}

void BatcherSort::BatcherMergeSort(int l, int r)
{
    int m = (l + r) / 2;

    if (r - l + 1 <= 1) 
        return;

	BatcherMergeSort(l, m);
	BatcherMergeSort(m + 1, r);
    Sort(l, r);
}

int BatcherSort::GetSize()
{
    return v.size();
}

vector<int> BatcherSort::GetVec()
{
    vector<int> tmp = v;
    return tmp;
}

ostream& operator<<(ostream &out, BatcherSort b) {
	for (int i = 0; i < b.GetSize(); i++)
		cout << b.v[i];
	return out;
}