#include "bruteforce.h"
#include <cmath>
#include <fstream>

int bruteforceKS(const KS_List& item, const int maxw)
{
  
  ofstream fout;
  
  fout.open("brute.txt");
  
  int n = item.getsize(); //used multiple times so variable for total amount of items
  
  KS_Item** solution = new KS_Item*[n];
  
  for (int i = 0; i < n; i++) {
    solution[i] = 0;
  }

  int A[n]; //array of binary values to create all combos

  

  int m = 0; //move through solution array
  int currentWeight=0; //used to keep track of weight in currentChoice
  int currentValue=0;  //same for above except for value
  int bestValue=0;     //keeps track of max value obtained by a combo of items
  int bestWeight=0;    //same as above except for weight

  for(int i=1;i<=pow(2,n);i++)
  {
    currentValue=0;     //resets variables so a new combo can be made
    currentWeight=0;

    for(int x=0;x<item.getsize();x++) //sets all elements to 0
    {
      A[x]=0;
    }
    
    //set value of binary in A to i;
    
    for (int j = 0; j < n; ++j) {  // assuming a 32 bit int
      A[j] = i & (1 << j) ? 1 : 0;
    }

    for(int k =0; k<n;k++) //creates combo out of items and keeps track of weight and value
    {
      if(A[k] == 1)
      {
      	currentWeight += item[k] -> getweight();
      	currentValue += item[k] -> getvalue();
      }

    }

    if((currentValue > bestValue) && (currentWeight <= maxw)) //replaces max if needed
    {
      bestValue = currentValue;
      bestWeight = currentWeight;
      for (int i = 0; i < n; i++) {
        solution[i] = 0;
      }
      m = 0;
      for(int k =1; k<n;k++) //creates combo out of items and keeps track of weight and value
      {
        if(A[k] == 1)
        {
          solution[m++] = item[k];
        }
      }
    }
     
    

  }
  
  m=0;
  while(solution[m] != 0 && m<n)
  {
    fout << *solution[m] << endl;
    m++;
  }

  return bestValue; //returns max set

}