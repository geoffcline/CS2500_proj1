#include "KnapSack.h"
#include "Greedy.h"
#include <iostream>
#include <fstream>

int GreedyKS(const KS_List& A, const int maxw)
{
  ofstream fout;
  
  fout.open("greedy.txt");
  
  KS_List W = A;
  
  KS_Item** solution = new KS_Item*[A.getsize()];
  
  for (int i = 0; i < A.getsize(); i++) {
    solution[i] = 0;
  }
  
  int P_wgt = 0;
  int P_vl = 0;
  int P_ct = 0;
  int m = 0; //count items selected
  int k = 0; //move through items while printing
  
  int j;
  
  QuickSortP(W);
  
  for (j=0; j < W.getsize(); j++)
  {
    
    if((P_wgt + (W[j] -> getweight())) <= maxw)
    {
      
      P_wgt += W[j] -> getweight();
      P_vl += W[j] -> getvalue();
      P_ct++;
      
      solution[m++] = W[j];
      
    }
  }
  
  while(solution[k] != 0 && m < A.getsize())
  {
    fout << *solution[k] << endl;
    k++;
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

