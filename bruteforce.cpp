#include "bruteforce.h"

int bruteforceKS(const KS_List& item, const int maxw)
{
  int n = item.getsize(); //used multiple times so variable for total amount of items

  int A[n]; //array of binary values to create all combos

  for(int x=0;x<item.getsize();x++) //sets all elements to 0
  {
  	A[x]=0;
  }

  int j = 0; //used for making all combos
  int currentWeight=0; //used to keep track of weight in currentChoice
  int currentValue=0;  //same for above except for value
  int bestValue=0;     //keeps track of max value obtained by a combo of items
  int bestWeight=0;    //same as above except for weight

  for(int i=1;i<(2^n);i++)
  {
    j = n;          
    currentValue=0;     //resets variables so a new combo can be made
    currentWeight=0;

    while(A[j] != 0 && j>0)  //creates the new combo in the binary array
    {
      A[j] = 0;
      j--;
    }

    A[j] = 1;        

    for(int k =1; k<n;k++) //creates combo out of items and keeps track of weight and value
    {
      if(A[k] == 1)
      {
      	currentWeight = currentWeight + item[k] -> getweight();
      	currentValue = currentValue + item[k] -> getvalue();
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