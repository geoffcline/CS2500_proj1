//Algorithms 2500
//Project 1
//Dynamic Programming
//CPP File

#include "KnapSack.h"
#include "Dynamic.h"
#include <iostream>
#include <fstream>

int DP_KNAPSACK(const KS_List& A, const int maxw)
{

	ofstream fout;
	fout.open("dynamic.txt");
	

//Variable to be used later
	int currentW = 0;
	int currentV = 0;
  //int view;
  //int view2;
	int sizeOfList = A.getsize();
	
//Creates a 2D Dynamic Array to store the Values with sizeOfList and maxw
	int **sackValues;
	sackValues = new int* [maxw+1];
	for (int i = 0; i <= maxw; i++)
	{
		sackValues[i] = new int[sizeOfList+1];
	}
  
  int **keep;
  keep = new int* [maxw+1];
  for (int i = 0; i <= maxw; i++)
  {
    keep[i] = new int[sizeOfList+1];
  }
  
  for(int m = 0; m <= sizeOfList; m++)
  {
    for (int k = 0; k <= maxw; k++)
    {
      sackValues[k][m] = 0;
      keep[k][m] = 0;
    }
  }

	
//Goes through the entire 2D array starting at row 1 to set the the max value
	for (int i = 1; i <= sizeOfList; i++)
	{
		for (int j = 0; j <= maxw; j++)
		{
      		currentW = A[i-1] -> getweight();
      		currentV = A[i-1] -> getvalue();
			if ( (currentW <= j) && ( (currentV + sackValues[j-currentW][i-1]) > sackValues[j][i-1] ) )
			{
        		sackValues[j][i] = currentV + sackValues[j-currentW][i-1];
        		keep[j][i] = 1;
			}
			else 
			{
        		sackValues[j][i] = sackValues[j][i-1];
      		}
		}
	}
	
  int final = sackValues[maxw][sizeOfList];
  int K = maxw;
  

  for (int i = sizeOfList; i >= 1; i--)
  {
    currentW = A[i-1] -> getweight();
    if (keep[K][i] == 1)
    {
      fout << *A[i-1] << endl;
      K = K - currentW;
    }
  }
  
//Delete 2D Dynamic Array
	for (int i = 0; i < maxw; i++)
	{
		delete [] sackValues[i];
    	delete [] keep[i];
	}
  	delete [] keep;
	delete [] sackValues;
	
	fout.close();
	
	return final;

}
