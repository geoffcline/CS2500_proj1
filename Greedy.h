#ifndef GREEDY_H
#define GREEDY_H

#include "KnapSack.h"

int GreedyKS(const KS_List& A, const int maxw);

//support function for QuickSortP
template <typename T>
int PivotP(T** work, const int start, const int end);

//friend function to KS_LIST
//designed to determine appropriate paramaters
void QuickSortP(KS_List& work);

template <typename T>
void QuickSortP(T** work, const int start, const int end);

#endif 