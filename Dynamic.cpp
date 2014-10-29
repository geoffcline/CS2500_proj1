//Algorithms 2500
//Project 1
//Dynamic Programming
//CPP File

#include "KnapSack.h"
#include "Dynamics.h"
#include <iostream>

int DP_KNAPSACK(const KS_List& A, const maxw)
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
		sackValues[0][i] = 0;
	}
	
//Goes through the entire 2D array starting at row 1 to set the the max value
	for (i = 1; i < sizeOfList; i++)
	{
		for (j = 0; j < maxw; j++)
		{
			currentW = Data[i] -> getweight();
			currentV = Data[i] -> getvalue();	
			if ( (currentW <= j) && ( (currentV + sackValues[i-1][j-currentW]) > sackValues[i-1][j] ) )
			{
				sackValues[i][j] = currentV + sackValues[i-1][j-currentW];
			}
			else 
			{
				sackValues[i][j] = sackValues[i-1][j];
			}
		}
	}
	return sackValues[sizeOfList][maxw];
}
