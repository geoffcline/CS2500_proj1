#ifndef GREEDY_H
#define GREEDY_H

#include "KnapSack.h"

int GreedyKS(const KS_List& A, const int maxw);

void QuickSortP(KS_List& work);

template <typename T>
void QuickSortP(T** work, const int start, const int end);

template <typename T>
int PivotP(T** work, const int start, const int end);

template <typename T>
void swap(T lhs, T rhs);

#endif 