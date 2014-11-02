#include "KnapSack.h"
#include "Greedy.h"

int GreedyKS(const KS_List& A, const int maxw)
{
  
  KS_List W = A;
  
  int P_wgt = 0;
  int P_vl = 0;
  int P_ct = 0;
  
  QuickSortP(W);
  
  for (int j= W.getsize() - 1; j >= 0; j--)
  {
    
    if((P_wgt + (W[j] -> getweight())) <= maxw)
    {
      
      P_wgt += W[j] -> getweight();
      P_vl += W[j] -> getvalue();
      P_ct++;
      
    }
  }
  
  return P_vl;
}

template <typename T>
int PivotP(T** A, int start, int end)
{
  int  p = start;
  T pivotElement = *A[start];
  
  for(int i = start+1 ; i < end ; i++)
  {
    if(*A[i] <= pivotElement)
    {
      p++;
      swap(A[i], A[p]);
    }
  }
  
  swap(A[p], A[start]);
  
  return p;
}

void QuickSortP(KS_List& work)
{
  QuickSortP(work.Data, 0, work.getsize());
}

template <typename T>
void QuickSortP(T** A, int start, int end)
{
  int pivotElement;
  
  if (start < end)
  {
    pivotElement = PivotP(A, start, end);
    QuickSortP(A, start, pivotElement - 1);
    QuickSortP(A, pivotElement + 1, end);
  }
}

