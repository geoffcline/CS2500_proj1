#include "KnapSack.h"
#include "Greedy.h"

int GreedyKS(const KS_List& A, const int maxw)
{
  
  KS_List W = A;  //create working copy of initial
  
  int P_wgt = 0; //partial weight
  int P_vl = 0;  //partial value
  int P_ct = 0;  //parital count
  
  QuickSortP(W); //sort array
  
  
  //move through items greatest to least
  for (int j= W.getsize() - 1; j >= 0; j--)
  {
   
    //if item fits into current solution
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

