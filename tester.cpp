#include "Greedy.h"
#include "KnapSack.h"
#include <fstream>
#include <iostream>

using namespace std;

int main ()
{
  
  clock_t t;
  ofstream fout;
  
  fout.open("result.csv");
  fout << "\"C/S\",\"" << CLOCKS_PER_SEC << "\"" << endl;
  
  
  int maxw;
  int resultv;
    
  const float SIGMA = 25;
  const float MU = 100;
  const int   SIZE = 10;
  const int   TESTS = 10000;
  

  KS_List L_working(SIGMA, MU, SIZE);

  for (int i = 0; i < TESTS; ++i)
  {
    cout << "GREEDY TEST: \t" << i << endl;
    L_working.generate();
    cout << "GENERATE DONE: \t" << i << endl;
    t = clock();
    resultv = GreedyKS(L_working, maxw);
    t = clock() - t;
    fout << "\"GREEDY\",\"" << i << "\",\""
         << t
         << "\"" << endl;
  }

  return 0;
}