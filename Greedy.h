#ifndef GREEDY_H
#define GREEDY_H

#include <iostream>

using namespace std;

void QuickSortP(KS_List& work);

template <typename T>
void QuickSortP(T** work, const int start, const int end);

template <typename T>
int PivotP(T** work, const int start, const int end);

int GreedyKS(const KS_List A, const int maxw );

#endif 