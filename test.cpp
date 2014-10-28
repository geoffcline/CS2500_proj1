#include "Greedy.h"
#include "KnapSack.h"
#include <fstream>


int main ()
{
  clock_t t;
  int maxw;
  int r;
  ofstream fout;   // out is a stream that will stream data to a file
  fout.open("table.csv");
    
  const float SIGMA = 0;
  const float MU = 0;
  const int SIZE = 0;
  const int TESTS = 0;

  KS_List L_working(SIGMA, MU, SIZE);

  for (int i = 0; i < TESTS; ++i)
  {
    L_working.generate();
    t = clock();
    r = GreedyKS(L_working, maxw);
    t = clock() - t;
    fout << "\"GREEDY\",\"" << i << "\",\"" << t << "\"" << endl;
  }

  return 0;
}