#include "Greedy.h"
#include "KnapSack.h"
#include "bruteforce.h"
#include "Dynamic.h"
#include <fstream>
#include <iostream>

using namespace std;

int main ()
{
  const float SIGMA = 10;
  const float MU = 100;
  const int   SIZE = 10;
  //const int   DATAPOINTS=1;
  //const int   NUMPERPOINT=1;
  const int   MAXW = 800;
  //const int   SIGMAINCREMENT = 0;
  //const int   INPUTINCREMENT = 0;
  //const int   INITIALINPUTSIZE = 5;
  //const int   INTIALSIGMA = 5;
  const int   BRUTETHRESHOLD = 20;
  
  clock_t t;
  ofstream fout;
  
  int resultv;
  int totalresultGreedy=0;
  //int totalresultDynamic=0;
  int totalresultBrute=0;
  int totalclockGreedy=0;
  //int totalclockDynamic=0;
  int totalclockBrute=0;
  int i =0;
  
  fout.open("result.csv");
  fout << "\"C/S\",\"" << CLOCKS_PER_SEC << "\"" << endl;
  
  KS_List L_working(SIGMA, MU, SIZE);
  
  //L_working.generate(INITIALINPUTSIZE);
  

   cout << "GREEDY TEST: \t" << i << endl;
    L_working.generate();
    cout << L_working << endl;
    t = clock();
    resultv = GreedyKS(L_working, MAXW);
    t = clock() - t;
    fout << "\"GREEDY\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockGreedy+=t;
    totalresultGreedy+=resultv;

    
    //BRUTE FORCE
    if(L_working.getsize() < BRUTETHRESHOLD)
    {  
      cout << "BRUTE TEST: \t" << i << endl;
      t = clock();
      resultv = bruteforceKS(L_working, MAXW);
      t = clock() - t;
      fout << "\"BRUTE\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;

      totalclockBrute+=t;
      totalresultBrute+=resultv;
    }
    else
    {
      cout << "BRUTE SKIP: \t" << i << endl;
      fout << "\"BRUTE\",\"" << i << "\",\"Input too large\"" << endl;
    }   
  
  fout.close();

  return 0;
}