#include "Greedy.h"
#include "KnapSack.h"
#include <fstream>

class KS_Item
{
private:
  int value;
  int weight;
public:
  const int getweight() const {return weight;}
  const int getvalue() const {return value;}
  KS_Item(const KS_Item &i) {}
  KS_Item(const int v, const int w) {}
  const KS_Item& operator= (const KS_Item& rhs) {return rhs;}
  
  bool operator< (const KS_Item& rhs) {return true;}
  bool operator==(const KS_Item& rhs) {return true;}
  bool operator> (const KS_Item& rhs) {return !(*this < rhs);}
  bool operator!=(const KS_Item& rhs) {return !(*this == rhs);}
  bool operator<=(const KS_Item& rhs) {return (*this < rhs) || (*this == rhs);}
  bool operator>=(const KS_Item& rhs) {return (*this > rhs) || (*this == rhs);}
};


class KS_List
{
private:
  KS_Item** Data;
  int size;
  float mu;
  float sigma;
public:
  void  setsize (const int s) {size = s;}
  int   getsize () const {return size;}
  void  setmu   (const float m) {mu = m;}
  float getmu   () const {return mu;}
  void  setsigma(const float s) {sigma = s;}
  float getsigma() const {return sigma;}
  void  generate() {}
  void  clear() {}
  friend void QuickSortP(KS_List& rhs);
  KS_Item*& operator [] (const int i) {return Data[i];}
  KS_List(const KS_List &rhs) {}
  KS_List(const float s = 0, const float m = 0, const int sz = 1) {}
  ~KS_List() {}
  const KS_List& operator= (const KS_List& rhs) {return *this;}
};

void QuickSortP(KS_List& work);

template <typename T>
void QuickSortP(T** work, const int start, const int end);

template <typename T>
int PivotP(T** work, const int start, const int end);

int GreedyKS(const KS_List& A, const int maxw)
{
  KS_List W = A;
  
  int P_wgt = 0;
  int P_vl = 0;
  
  int j = 0;
  
  QuickSortP(W);
  
  while(P_wgt + W[j] -> getweight() <= maxw && j < W.getsize())
  {
    P_wgt += W[j] -> getweight();
    P_vl += W[j] -> getvalue();
    j++;
  }
  
  return P_wgt;
}

void QuickSortP(KS_List& work)
{
  QuickSortP(work.Data, 0, work.getsize());
}

template <typename T>
int PivotP(T** A, int start, int end)
{
  int  p = start;
  T pivotElement = *A[start];
  
  for(int i = start+1 ; i <= end ; i++)
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

int main ()
{
  clock_t t;
  
  ofstream fout;
  fout.open("table.csv");
  
  int maxw;
  int resultv;
    
  const float SIGMA = 0;
  const float MU = 0;
  const int   SIZE = 0;
  const int   TESTS = 0;
  

  KS_List L_working(SIGMA, MU, SIZE);

  for (int i = 0; i < TESTS; ++i)
  {
    L_working.generate();
    t = clock();
              //WHY DON'T YOU KNOW GREEDYKS? 
    resultv = GreedyKS(L_working, maxw);
    t = clock() - t;
    fout << "\"GREEDY\",\"" << i << "\",\"" << t << "\"" << endl;
  }

  return 0;
}