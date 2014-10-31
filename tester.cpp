#include "Greedy.h"
#include "KnapSack.h"
#include "bruteforce.h"
#include "Dynamic.h"
#include <fstream>
#include <iostream>

using namespace std;

int main ()
{
  const float SIGMA = 50;
  const float MU = 100;
  const int   SIZE = 4;
  const int   MAXW = 100;
  
  const int   TESTS = 16;
  const int   INCREMENTEVERY = 1;
  const int   INCREMENTSIZE = 1;
  
  clock_t t;
  int resultv = 0;
  ofstream fout;
  ofstream fout2;
  
  fout.open("result3.csv");
  fout2.open("inputs.txt");
  fout << "\"C/S\",\"" << CLOCKS_PER_SEC << "\"" << endl;
  
  KS_List L_working(SIGMA, MU, SIZE);
  
  for (int i = 0; i < TESTS; i++)
  {
    if (i % INCREMENTEVERY == 0 && i !=0)
      L_working.generate(L_working.getsize() + INCREMENTSIZE);
    else
      L_working.generate();
    
    fout2 << "INPUTS: " << i << endl;
    fout2 << L_working << endl << endl << endl << endl << endl;
    
    
    //GREEDY
    cout << "\t\tGREEDY TEST: \t" << i << endl;
    t = clock();
    resultv = GreedyKS(L_working, MAXW);
    t = clock() - t;
    fout << "\"GREEDY\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    
    
    //DYNAMIC
    cout << "\t\tDYNAMIC TEST: \t" << i << endl;
    t = clock();
    resultv = DP_KNAPSACK(L_working, MAXW);
    t = clock() - t;
    fout << "\"DYNAMIC\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    //BRUTE
    cout << "\t\tBRUTE TEST: \t" << i << endl;
    t = clock();
    resultv = bruteforceKS(L_working, MAXW);
    t = clock() - t;
    fout << "\"BRUTE\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;

    
  }
  
  fout.close();
  fout2.close();

  return 0;
}