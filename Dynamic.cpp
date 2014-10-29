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
	int currentW, currentV;
	int sizeOfList = A.getsize();
//Creates a 2D Dynamic Array to store the Values with sizeOfList and maxw
	int **sackValues;
	sackValues = new int *[maxw];
	for (int i = 0; i < maxw; i++)
	{
		sackValues[i] = new int[sizeOfList];
	}

//Sets each value in row 0 and column i to 0
	for (int i = 0; i < maxw; i++)
	{
		sackValues[i][0] = 0;
	}
	
//Goes through the entire 2D array starting at row 1 to set the the max value
	for (int i = 1; i < sizeOfList; i++)
	{
		for (int j = 0; j < maxw; j++)
		{
			currentW = A[i] -> getweight();
			currentV = A[i] -> getvalue();
			if ( (currentW <= j) && ( (currentV + sackValues[j-currentW][i-1]) > sackValues[j][i-1] ) )
			{
				sackValues[j][i] = currentV + sackValues[j-currentW][i-1];
			}
			else 
			{
				sackValues[j][i] = sackValues[j][i-1];
			}
		}
	}
	return sackValues[maxw][sizeOfList];
}
