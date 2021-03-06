#include "bruteforce.h"
#include <cmath>

int bruteforceKS(const KS_List& item, const int maxw)
{
  
  int n = item.getsize(); //used multiple times so variable for total amount of items
  
  int* A = new int[n]; //array of binary values to create all combos

  int currentWeight=0; //used to keep track of weight in currentChoice
  int currentValue=0;  //same for above except for value
  int bestValue=0;     //keeps track of max value obtained by a combo of items
  int bestWeight=0;    //same as above except for weight

  for(int i=1;i<pow(2,n);i++)
  {
    currentValue=0;     //resets variables so a new combo can be made
    currentWeight=0;

    for(int x=0;x<item.getsize();x++) //sets all elements to 0
    {
      A[x]=0;
    }
    
    //set value of binary in A to i;
    
    for (int j = 0; j < n; ++j) 
    {
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
    }
     
    

  }
  

  return bestValue; //returns max set

}
