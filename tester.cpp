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
  const float MU = 50;
  const int   SIZE = 300;
  const int   TESTS = 1000; //no longer used
  const int   DATAPOINTS=10;
  const int   NUMPERPOINT=15;
  const int   MAXW = 5000;
  const int   SIGMAINCREMENT = 5;
  const int   INPUTINCREMENT = 100;
  
  clock_t t;
  ofstream fout;
  int resultv;
  int totalresultGreedy=0;
  int totalresultDynamic=0;
  int totalresultBrute=0;
  int totalclockGreedy=0;
  int totalclockDynamic=0;
  int totalclockBrute=0;
  
  fout.open("result.csv");
  fout << "\"C/S\",\"" << CLOCKS_PER_SEC << "\"" << endl;
  
  KS_List L_working(SIGMA, MU, SIZE);

  for (int i = 0; i < DATAPOINTS*NUMPERPOINT; ++i) //denpendant->execution independant->inputsize
  {
     
    if(i%NUMPERPOINT==0)
    {
      L_working.setsize(L_working.getsize() + INPUTINCREMENT);
  
      totalclockGreedy  = totalclockGreedy/NUMPERPOINT;
      totalresultGreedy = totalresultGreedy/NUMPERPOINT;
      totalclockBrute   = totalclockBrute/NUMPERPOINT;
      totalresultBrute  = totalresultBrute/NUMPERPOINT;
      totalclockDynamic = totalclockDynamic/NUMPERPOINT;
      totalresultDynamic= totalresultDynamic/NUMPERPOINT;

      fout << "\"GREEDY DATA POINT\",\"" << i << "\",\"" << totalclockGreedy << "\",\"" << totalresultGreedy << "\"" << endl;
      fout << "\"BRUTE DATA POINT\",\"" << i << "\",\"" << totalclockBrute << "\",\"" << totalresultBrute << "\"" << endl;
      fout << "\"DYNAMIC DATA POINT\",\"" << i << "\",\"" << totalclockDynamic << "\",\"" << totalresultDynamic << "\"" << endl;
      
      totalclockGreedy  = 0;
      totalresultGreedy = 0;
      totalclockBrute   = 0;
      totalresultBrute  = 0;
      totalclockDynamic = 0;
      totalresultDynamic= 0;
    }

    //GREEDY APPROACH
    cout << "GREEDY TEST: \t" << i << endl;
    L_working.generate();
    t = clock();
    resultv = GreedyKS(L_working, MAXW);
    t = clock() - t;
    fout << "\"GREEDY\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockGreedy+=t;
    totalresultGreedy+=resultv;

    
    //BRUTE FORCE
    cout << "BRUTE TEST: \t" << i << endl;
    t = clock();
    resultv = bruteforceKS(L_working, MAXW);
    t = clock() - t;
    fout << "\"BRUTE\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;

    totalclockBrute+=t;
    totalresultBrute+=resultv;    
    
    //DYNAMIC APPROACH
    cout << "DYNAMIC TEST: \t" << i << endl;
    t = clock();
    resultv = DP_KNAPSACK(L_working, MAXW);
    t = clock() - t;
    fout << "\"DYNAMIC\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockDynamic+=t;
    totalresultDynamic+=resultv;

  }

  for (int i = 0; i < DATAPOINTS*NUMPERPOINT; ++i) //denpendant->execution independant->variance
  {
     
    if(i%NUMPERPOINT==0)
    {
      L_working.setsigma(L_working.getsigma()+SIGMAINCREMENT);
  
      totalclockGreedy  = totalclockGreedy/NUMPERPOINT;
      totalresultGreedy = totalresultGreedy/NUMPERPOINT;
      totalclockBrute   = totalclockBrute/NUMPERPOINT;
      totalresultBrute  = totalresultBrute/NUMPERPOINT;
      totalclockDynamic = totalclockDynamic/NUMPERPOINT;
      totalresultDynamic= totalresultDynamic/NUMPERPOINT;

      fout << "\"GREEDY DATA POINT\",\"" << i << "\",\"" << totalclockGreedy << "\",\"" << totalresultGreedy << "\"" << endl;
      fout << "\"BRUTE DATA POINT\",\"" << i << "\",\"" << totalclockBrute << "\",\"" << totalresultBrute << "\"" << endl;
      fout << "\"DYNAMIC DATA POINT\",\"" << i << "\",\"" << totalclockDynamic << "\",\"" << totalresultDynamic << "\"" << endl;
      
      totalclockGreedy  = 0;
      totalresultGreedy = 0;
      totalclockBrute   = 0;
      totalresultBrute  = 0;
      totalclockDynamic = 0;
      totalresultDynamic= 0;
    }

    //GREEDY APPROACH
    cout << "GREEDY TEST: \t" << i << endl;
    L_working.generate();
    t = clock();
    resultv = GreedyKS(L_working, MAXW);
    t = clock() - t;
    fout << "\"GREEDY\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockGreedy+=t;
    totalresultGreedy+=resultv;

    
    //BRUTE FORCE
    cout << "BRUTE TEST: \t" << i << endl;
    t = clock();
    resultv = bruteforceKS(L_working, MAXW);
    t = clock() - t;
    fout << "\"BRUTE\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;

    totalclockBrute+=t;
    totalresultBrute+=resultv;    
    
    //DYNAMIC APPROACH
    cout << "DYNAMIC TEST: \t" << i << endl;
    t = clock();
    resultv = DP_KNAPSACK(L_working, MAXW);
    t = clock() - t;
    fout << "\"DYNAMIC\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockDynamic+=t;
    totalresultDynamic+=resultv;
  }

  for (int i = 0; i < DATAPOINTS*NUMPERPOINT; ++i) //denpendant->value independant->inputsize
  {
     
    if(i%NUMPERPOINT==0)
    {
      L_working.setsize(L_working.getsize() + INPUTINCREMENT);
  
      totalclockGreedy  = totalclockGreedy/NUMPERPOINT;
      totalresultGreedy = totalresultGreedy/NUMPERPOINT;
      totalclockBrute   = totalclockBrute/NUMPERPOINT;
      totalresultBrute  = totalresultBrute/NUMPERPOINT;
      totalclockDynamic = totalclockDynamic/NUMPERPOINT;
      totalresultDynamic= totalresultDynamic/NUMPERPOINT;

      fout << "\"GREEDY DATA POINT\",\"" << i << "\",\"" << totalclockGreedy << "\",\"" << totalresultGreedy << "\"" << endl;
      fout << "\"BRUTE DATA POINT\",\"" << i << "\",\"" << totalclockBrute << "\",\"" << totalresultBrute << "\"" << endl;
      fout << "\"DYNAMIC DATA POINT\",\"" << i << "\",\"" << totalclockDynamic << "\",\"" << totalresultDynamic << "\"" << endl;
      
      totalclockGreedy  = 0;
      totalresultGreedy = 0;
      totalclockBrute   = 0;
      totalresultBrute  = 0;
      totalclockDynamic = 0;
      totalresultDynamic= 0;
    }

    //GREEDY APPROACH
    cout << "GREEDY TEST: \t" << i << endl;
    L_working.generate();
    t = clock();
    resultv = GreedyKS(L_working, MAXW);
    t = clock() - t;
    fout << "\"GREEDY\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockGreedy+=t;
    totalresultGreedy+=resultv;

    
    //BRUTE FORCE
    cout << "BRUTE TEST: \t" << i << endl;
    t = clock();
    resultv = bruteforceKS(L_working, MAXW);
    t = clock() - t;
    fout << "\"BRUTE\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;

    totalclockBrute+=t;
    totalresultBrute+=resultv;    
    
    //DYNAMIC APPROACH
    cout << "DYNAMIC TEST: \t" << i << endl;
    t = clock();
    resultv = DP_KNAPSACK(L_working, MAXW);
    t = clock() - t;
    fout << "\"DYNAMIC\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockDynamic+=t;
    totalresultDynamic+=resultv;
  }

  for (int i = 0; i < DATAPOINTS*NUMPERPOINT; ++i) //denpendant->value independant->variance
  {
     
    if(i%NUMPERPOINT==0)
    {
      L_working.setsigma(L_working.getsigma()+SIGMAINCREMENT);
  
      totalclockGreedy  = totalclockGreedy/NUMPERPOINT;
      totalresultGreedy = totalresultGreedy/NUMPERPOINT;
      totalclockBrute   = totalclockBrute/NUMPERPOINT;
      totalresultBrute  = totalresultBrute/NUMPERPOINT;
      totalclockDynamic = totalclockDynamic/NUMPERPOINT;
      totalresultDynamic= totalresultDynamic/NUMPERPOINT;

      fout << "\"GREEDY DATA POINT\",\"" << i << "\",\"" << totalclockGreedy << "\",\"" << totalresultGreedy << "\"" << endl;
      fout << "\"BRUTE DATA POINT\",\"" << i << "\",\"" << totalclockBrute << "\",\"" << totalresultBrute << "\"" << endl;
      fout << "\"DYNAMIC DATA POINT\",\"" << i << "\",\"" << totalclockDynamic << "\",\"" << totalresultDynamic << "\"" << endl;
      
      totalclockGreedy  = 0;
      totalresultGreedy = 0;
      totalclockBrute   = 0;
      totalresultBrute  = 0;
      totalclockDynamic = 0;
      totalresultDynamic= 0;
    }

    //GREEDY APPROACH
    cout << "GREEDY TEST: \t" << i << endl;
    L_working.generate();
    t = clock();
    resultv = GreedyKS(L_working, MAXW);
    t = clock() - t;
    fout << "\"GREEDY\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockGreedy+=t;
    totalresultGreedy+=resultv;

    
    //BRUTE FORCE
    cout << "BRUTE TEST: \t" << i << endl;
    t = clock();
    resultv = bruteforceKS(L_working, MAXW);
    t = clock() - t;
    fout << "\"BRUTE\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;

    totalclockBrute+=t;
    totalresultBrute+=resultv;    
    
    //DYNAMIC APPROACH
    cout << "DYNAMIC TEST: \t" << i << endl;
    t = clock();
    resultv = DP_KNAPSACK(L_working, MAXW);
    t = clock() - t;
    fout << "\"DYNAMIC\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockDynamic+=t;
    totalresultDynamic+=resultv;
  }

  fout.close();

  return 0;
}