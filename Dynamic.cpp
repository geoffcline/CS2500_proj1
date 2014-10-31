//Algorithms 2500
//Project 1
//Dynamic Programming
//CPP File

#include "KnapSack.h"
#include "Dynamic.h"
#include <iostream>

int DP_KNAPSACK(const KS_List& A, const int maxw)
{

//Variable to be used later
	int currentW = 0;
	int currentV = 0;
  int view;
  int view2;
	int sizeOfList = A.getsize();
	
//Creates a 2D Dynamic Array to store the Values with sizeOfList and maxw
	int **sackValues;
	sackValues = new int* [maxw+1];
	for (int i = 0; i <= maxw; i++)
	{
		sackValues[i] = new int[sizeOfList];
	}
  
  for (int k = 0; k <= maxw; k++)
  {
    for (int i = 0; i < sizeOfList; i++)
    {
      sackValues[k][i] = 0;
    }
  }
	
	
//Goes through the entire 2D array starting at row 1 to set the the max value
	for (int i = 0; i < sizeOfList; i++)
	{
		for (int j = 1; j <= maxw; j++)
		{
      currentW = A[i] -> getweight();
      currentV = A[i] -> getvalue();
            
			if ( (currentW <= j) && ( (currentV + sackValues[j-currentW][i-1]) > sackValues[j][i-1] ) )
			{
        view = currentV + sackValues[j-currentW][i-1];
        cout << "currentV: \t" <<currentV << endl;
        cout << "sackvalue: \t" << sackValues[j-currentW][i-1] << endl;
        cout << "dy_if: \t\t"<<view << endl;
        
        sackValues[j][i] = view;
			}
			else 
			{
        view2 = sackValues[j][i-1];
        cout << "dy_else: \t" << view2 << endl;
        sackValues[j][i] = view2;
			}
		}
	}
	
  int final = sackValues[maxw][sizeOfList-1];
  
  
  
//Delete 2D Dynamic Array
	for (int i = 0; i < maxw; i++)
	{
		delete [] sackValues[i];
	}
  
	delete [] sackValues;

	
	return final;

}
