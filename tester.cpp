#include "Greedy.h"
#include "KnapSack.h"
#include <iostream>

using namespace std;

int main ()
{
  
  clock_t t;
  
  
  int maxw;
  int resultv;
    
  const float SIGMA = 25;
  const float MU = 100;
  const int   SIZE = 10;
  const int   TESTS = 10;
  

  KS_List L_working(SIGMA, MU, SIZE);

  for (int i = 0; i < TESTS; ++i)
  {
    cout << "TEST: " << i << endl;
    L_working.generate();
    t = clock();
              //WHY DON'T YOU KNOW GREEDYKS? 
    resultv = GreedyKS(L_working, maxw);
    t = clock() - t;
    cout << "\"GREEDY\",\"" << i << "\",\""
         << static_cast<float>(t) / CLOCKS_PER_SEC
         << "\"" << endl;
  }

  return 0;
}