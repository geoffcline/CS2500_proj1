#include "Greedy.h"
#include "KnapSack.h"
#include <fstream>
#include <iostream>

using namespace std;

int main ()
{
  const float SIGMA = 25;
  const float MU = 100;
  const int   SIZE = 10;
  const int   TESTS = 1000;
  const int   MAXW = 1000;
  
  clock_t t;
  ofstream fout;
  int resultv;
  
  fout.open("result.csv");
  fout << "\"C/S\",\"" << CLOCKS_PER_SEC << "\"" << endl;
  
  KS_List L_working(SIGMA, MU, SIZE);

  for (int i = 0; i < TESTS; ++i)
  {
    cout << "GREEDY TEST: \t" << i << endl;
    L_working.generate();
    t = clock();
    resultv = GreedyKS(L_working, MAXW);
    t = clock() - t;
    fout << "\"GREEDY\",\"" << i << "\",\""
         << t
         << "\"" << endl;
  }

  fout.close();

  return 0;
}