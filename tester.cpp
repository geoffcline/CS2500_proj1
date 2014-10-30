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
  const int   DATAPOINTS=10;
  const int   NUMPERPOINT=15;
  const int   MAXW = 5000;
  const int   SIGMAINCREMENT = 5;
  const int   INPUTINCREMENT = 100;
  const int   INITIALINPUTSIZE = 100;
  const int   INTIALSIGMA = 5;
  const int   BRUTETHRESHOLD = 99;
  
  clock_t t;
  ofstream fout;
  
  int resultv;
  int totalresultGreedy=0;
  int totalresultDynamic=0;
  int totalresultBrute=0;
  int totalclockGreedy=0;
  int totalclockDynamic=0;
  int totalclockBrute=0;
  int brutetooLarge=0;
  
  fout.open("result.csv");
  fout << "\"C/S\",\"" << CLOCKS_PER_SEC << "\"" << endl;
  
  KS_List L_working(SIGMA, MU, SIZE);
  
  L_working.generate(INITIALINPUTSIZE);

  for (int i = 0; i < DATAPOINTS*NUMPERPOINT; ++i) //denpendant->execution independant->inputsize
  {
    


    //GREEDY APPROACH
    cout << "GREEDY TEST 1: \t" << i << endl;
    L_working.generate();
    t = clock();
    resultv = GreedyKS(L_working, MAXW);
    t = clock() - t;
    fout << "\"GREEDY 1\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockGreedy+=t;
    totalresultGreedy+=resultv;

    
    //BRUTE FORCE
    if(L_working.getsize() < BRUTETHRESHOLD)
    {  
      cout << "BRUTE TEST 1: \t" << i << endl;
      t = clock();
      resultv = bruteforceKS(L_working, MAXW);
      t = clock() - t;
      fout << "\"BRUTE 1\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
      totalclockBrute+=t;
      totalresultBrute+=resultv;
    }
    else
    {
      cout << "BRUTE SKIP: \t" << i << endl;
      fout << "\"BRUTE 1\",\"" << i << "\",\"Input too large\"" << endl;
      brutetooLarge++;
    }
    
    //DYNAMIC APPROACH
    cout << "DYNAMIC TEST 1: \t" << i << endl;
    t = clock();
    resultv = DP_KNAPSACK(L_working, MAXW);
    t = clock() - t;
    fout << "\"DYNAMIC 1\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockDynamic+=t;
    totalresultDynamic+=resultv;

    
    if(i%NUMPERPOINT==0 && i!=0)
    {
      L_working.generate(L_working.getsize() + INPUTINCREMENT);
  
      totalclockGreedy  = totalclockGreedy/NUMPERPOINT;
      totalresultGreedy = totalresultGreedy/NUMPERPOINT;
      totalclockBrute   = totalclockBrute/(NUMPERPOINT- brutetooLarge);
      totalresultBrute  = totalresultBrute/(NUMPERPOINT- brutetooLarge);
      totalclockDynamic = totalclockDynamic/NUMPERPOINT;
      totalresultDynamic= totalresultDynamic/NUMPERPOINT;

      fout << "\"GREEDY DATA POINT 1\",\"" << i << "\",\"" << totalclockGreedy << "\",\"" << totalresultGreedy << "\"" << endl;
      fout << "\"BRUTE DATA POINT 1\",\"" << i << "\",\"" << totalclockBrute << "\",\"" << totalresultBrute << "\"" << endl;
      fout << "\"DYNAMIC DATA POINT 1\",\"" << i << "\",\"" << totalclockDynamic << "\",\"" << totalresultDynamic << "\"" << endl;
      
      totalclockGreedy  = 0;
      totalresultGreedy = 0;
      totalclockBrute   = 0;
      totalresultBrute  = 0;
      totalclockDynamic = 0;
      totalresultDynamic= 0;
      brutetooLarge     = 0;
    }

  }
 
  L_working.setsigma(INTIALSIGMA);

  for (int i = 0; i < DATAPOINTS*NUMPERPOINT; ++i) //denpendant->execution independant->variance
  {
    


    //GREEDY APPROACH
    cout << "GREEDY TEST 2: \t" << i << endl;
    L_working.generate();
    t = clock();
    resultv = GreedyKS(L_working, MAXW);
    t = clock() - t;
    fout << "\"GREEDY 2\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockGreedy+=t;
    totalresultGreedy+=resultv;

    
    //BRUTE FORCE
    if(L_working.getsize() < BRUTETHRESHOLD)
    {  
      cout << "BRUTE TEST 2: \t" << i << endl;
      t = clock();
      resultv = bruteforceKS(L_working, MAXW);
      t = clock() - t;
      fout << "\"BRUTE 2\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;

      totalclockBrute+=t;
      totalresultBrute+=resultv;
    }
    else
    {
      cout << "BRUTE SKIP: \t" << i << endl;
      fout << "\"BRUTE\",\"" << i << "\",\"Input too large\"" << endl;
      brutetooLarge++;
    }
    
    //DYNAMIC APPROACH
    cout << "DYNAMIC TEST 2: \t" << i << endl;
    t = clock();
    resultv = DP_KNAPSACK(L_working, MAXW);
    t = clock() - t;
    fout << "\"DYNAMIC\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockDynamic+=t;
    totalresultDynamic+=resultv;

    if(i%NUMPERPOINT==0 && i != 0)
    {
      L_working.setsigma(L_working.getsigma()+SIGMAINCREMENT);
  
      totalclockGreedy  = totalclockGreedy/NUMPERPOINT;
      totalresultGreedy = totalresultGreedy/NUMPERPOINT;
      totalclockBrute   = totalclockBrute/(NUMPERPOINT- brutetooLarge);
      totalresultBrute  = totalresultBrute/(NUMPERPOINT- brutetooLarge);
      totalclockDynamic = totalclockDynamic/NUMPERPOINT;
      totalresultDynamic= totalresultDynamic/NUMPERPOINT;

      fout << "\"GREEDY DATA POINT 2\",\"" << i << "\",\"" << totalclockGreedy << "\",\"" << totalresultGreedy << "\"" << endl;
      fout << "\"BRUTE DATA POINT 2\",\"" << i << "\",\"" << totalclockBrute << "\",\"" << totalresultBrute << "\"" << endl;
      fout << "\"DYNAMIC DATA POINT 2\",\"" << i << "\",\"" << totalclockDynamic << "\",\"" << totalresultDynamic << "\"" << endl;
      
      totalclockGreedy  = 0;
      totalresultGreedy = 0;
      totalclockBrute   = 0;
      totalresultBrute  = 0;
      totalclockDynamic = 0;
      totalresultDynamic= 0;
      brutetooLarge     = 0;
    }


  }

  L_working.generate(INITIALINPUTSIZE);

  for (int i = 0; i < DATAPOINTS*NUMPERPOINT; ++i) //denpendant->value independant->inputsize
  {
    


    //GREEDY APPROACH
    cout << "GREEDY TEST 3: \t" << i << endl;
    L_working.generate();
    t = clock();
    resultv = GreedyKS(L_working, MAXW);
    t = clock() - t;
    fout << "\"GREEDY 3\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockGreedy+=t;
    totalresultGreedy+=resultv;

    
    //BRUTE FORCE
    if(L_working.getsize() < BRUTETHRESHOLD)
    {  
      cout << "BRUTE TEST 3: \t" << i << endl;
      t = clock();
      resultv = bruteforceKS(L_working, MAXW);
      t = clock() - t;
      fout << "\"BRUTE 3\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;

      totalclockBrute+=t;
      totalresultBrute+=resultv;
    }
    else
    {
      cout << "BRUTE SKIP: \t" << i << endl;
      fout << "\"BRUTE 3\",\"" << i << "\",\"Input too large\"" << endl;
      brutetooLarge++;
    }    
    
    //DYNAMIC APPROACH
    cout << "DYNAMIC TEST 3: \t" << i << endl;
    t = clock();
    resultv = DP_KNAPSACK(L_working, MAXW);
    t = clock() - t;
    fout << "\"DYNAMIC 3\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockDynamic+=t;
    totalresultDynamic+=resultv;

    if(i%NUMPERPOINT==0 && i!=0)
    {
      L_working.generate(L_working.getsize() + INPUTINCREMENT);
  
      totalclockGreedy  = totalclockGreedy/NUMPERPOINT;
      totalresultGreedy = totalresultGreedy/NUMPERPOINT;
      totalclockBrute   = totalclockBrute/(NUMPERPOINT- brutetooLarge);
      totalresultBrute  = totalresultBrute/(NUMPERPOINT- brutetooLarge);
      totalclockDynamic = totalclockDynamic/NUMPERPOINT;
      totalresultDynamic= totalresultDynamic/NUMPERPOINT;

      fout << "\"GREEDY DATA POINT 3\",\"" << i << "\",\"" << totalclockGreedy << "\",\"" << totalresultGreedy << "\"" << endl;
      fout << "\"BRUTE DATA POINT 3\",\"" << i << "\",\"" << totalclockBrute << "\",\"" << totalresultBrute << "\"" << endl;
      fout << "\"DYNAMIC DATA POINT 3\",\"" << i << "\",\"" << totalclockDynamic << "\",\"" << totalresultDynamic << "\"" << endl;
      
      totalclockGreedy  = 0;
      totalresultGreedy = 0;
      totalclockBrute   = 0;
      totalresultBrute  = 0;
      totalclockDynamic = 0;
      totalresultDynamic= 0;
      brutetooLarge     = 0;
    }

  }

  L_working.setsigma(INTIALSIGMA);
 
  for (int i = 0; i < DATAPOINTS*NUMPERPOINT; ++i) //denpendant->value independant->variance
  {
     


    //GREEDY APPROACH
    cout << "GREEDY TEST 4: \t" << i << endl;
    L_working.generate();
    t = clock();
    resultv = GreedyKS(L_working, MAXW);
    t = clock() - t;
    fout << "\"GREEDY 4\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockGreedy+=t;
    totalresultGreedy+=resultv;

    
    //BRUTE FORCE
    if(L_working.getsize() < BRUTETHRESHOLD)
    {  
      cout << "BRUTE TEST 4: \t" << i << endl;
      t = clock();
      resultv = bruteforceKS(L_working, MAXW);
      t = clock() - t;
      fout << "\"BRUTE 4\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;

      totalclockBrute+=t;
      totalresultBrute+=resultv;
    }
    else
    {
      cout << "BRUTE SKIP: \t" << i << endl;
      fout << "\"BRUTE 4\",\"" << i << "\",\"Input too large\"" << endl;
      brutetooLarge++;
    }   
    
    //DYNAMIC APPROACH
    cout << "DYNAMIC TEST 4: \t" << i << endl;
    t = clock();
    resultv = DP_KNAPSACK(L_working, MAXW);
    t = clock() - t;
    fout << "\"DYNAMIC 4\",\"" << i << "\",\"" << t << "\",\"" << resultv << "\"" << endl;
    
    totalclockDynamic+=t;
    totalresultDynamic+=resultv;

    if(i%NUMPERPOINT==0 && i!=0)
    {
      L_working.setsigma(L_working.getsigma()+SIGMAINCREMENT);
  
      totalclockGreedy  = totalclockGreedy/NUMPERPOINT;
      totalresultGreedy = totalresultGreedy/NUMPERPOINT;
      totalclockBrute   = totalclockBrute/(NUMPERPOINT- brutetooLarge);
      totalresultBrute  = totalresultBrute/(NUMPERPOINT- brutetooLarge);
      totalclockDynamic = totalclockDynamic/NUMPERPOINT;
      totalresultDynamic= totalresultDynamic/NUMPERPOINT;

      fout << "\"GREEDY DATA POINT 4\",\"" << i << "\",\"" << totalclockGreedy << "\",\"" << totalresultGreedy << "\"" << endl;
      fout << "\"BRUTE DATA POINT 4\",\"" << i << "\",\"" << totalclockBrute << "\",\"" << totalresultBrute << "\"" << endl;
      fout << "\"DYNAMIC DATA POINT 4\",\"" << i << "\",\"" << totalclockDynamic << "\",\"" << totalresultDynamic << "\"" << endl;
      
      totalclockGreedy  = 0;
      totalresultGreedy = 0;
      totalclockBrute   = 0;
      totalresultBrute  = 0;
      totalclockDynamic = 0;
      totalresultDynamic= 0;
      brutetooLarge     = 0;
    }
  }

  fout.close();

  return 0;
}