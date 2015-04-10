// Lab11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "coinStruct.h"
#include <iostream>

using namespace std;

void changeMaking(int n);
void greedyChangeMaking(int n);

// GLOBAL VARIABLE
int* D = new int[5];

// ---------- main function -----------
int _tmain(int argc, _TCHAR* argv[])
{
	D[0] = 1;
	D[1] = 7;
	D[2] = 30;
	D[3] = 84;
	D[4] = 235;

	int numberOfChange;
	coinStruct answerCoin;
	
	cout << "Enter the amount of change in total: ",
		cin >> numberOfChange;
	 
	int typeOfAlg;
	cout << "Choose your algorithms: " << endl;
	cout << "1 -- change making algorithm" << endl;
	cout << "2 -- greedy algorithm" << endl;
	cout << "Enter your choice of algorithm: ",
		cin >> typeOfAlg;

	while (numberOfChange >= 0)
	{
		if (typeOfAlg == 1)
			changeMaking(numberOfChange);
		else if (typeOfAlg == 2)
			greedyChangeMaking(numberOfChange);
		else
			cout << "Invalid input. Do it again: " << endl;
		cout << "\nEnter the amount of change in total: ",
			cin >> numberOfChange;
		cout << "Choose your algorithms: " << endl;
		cout << "1 -- change making algorithm" << endl;
		cout << "2 -- greedy algorithm" << endl;
		cout << "Enter your choice of algorithm: ",
			cin >> typeOfAlg;
	}
    
	cout << "\nDone." << endl;

	system("PAUSE");
	return 0;
}


void changeMaking(int n)
{
	coinStruct* F = new coinStruct[n + 1];
	//F[0] = tempCoinSet;

	coinStruct temp;
	for (int i = 1; i <= n; i++)
	{
		// initialize temp
		temp.totalNbCoins = i;
		temp.nbEachCoin[0] = i;
		for (short index = 1; index < 5; index++)
			temp.nbEachCoin[index] = 0;
		
		int j = 0;
		while (j < 5 && i >= D[j])
		{
			if ((F[i - D[j]].totalNbCoins + 1) < temp.totalNbCoins)
			{
				temp.totalNbCoins = F[i - D[j]].totalNbCoins + 1;
				for (int z = 0; z < 5; z++)
				{
					if (z != j)
					{
						temp.nbEachCoin[z] = F[i - D[j]].nbEachCoin[z];
					}
					else
					{
						temp.nbEachCoin[z] = F[i - D[j]].nbEachCoin[z] + 1;
					}//end else
				}// end for z
			}// end if
			j++;
		}//end while
		F[i].totalNbCoins = temp.totalNbCoins;
		F[i].nbEachCoin[0] = temp.nbEachCoin[0];
		F[i].nbEachCoin[1] = temp.nbEachCoin[1];
		F[i].nbEachCoin[2] = temp.nbEachCoin[2];
		F[i].nbEachCoin[3] = temp.nbEachCoin[3];
		F[i].nbEachCoin[4] = temp.nbEachCoin[4];

	}// end for i

	cout << "\n----------- Change Making Algorithm ------------- " << endl;
	cout << "\nMinimum number of coins: " << F[n].totalNbCoins << "." << endl;
	cout << "Number of 1 cent: " << F[n].nbEachCoin[0] << endl;
	cout << "Number of 7 cent: " << F[n].nbEachCoin[1] << endl;
	cout << "Number of 30 cent: " << F[n].nbEachCoin[2] << endl;
	cout << "Number of 84 cent: " << F[n].nbEachCoin[3] << endl;
	cout << "Number of 235 cent: " << F[n].nbEachCoin[4] << endl;
}

void greedyChangeMaking(int n)
{
	int F[5];

	int l = n; //total number of coins
	for (int i = 4; i >= 0; i--)
	{
		F[i] = l / D[i];
		l = l % D[i];
	}
	
	cout << "\n----------- Greedy Algorithm ------------- " << endl;
	cout << "\nTotal number of coins: " << F[0] + F[1] + F[2] + F[3] + F[4] << "." << endl;
	cout << "Number of 1 cent: " << F[0] << endl;
	cout << "Number of 7 cent: " << F[1] << endl;
	cout << "Number of 30 cent: " << F[2] << endl;
	cout << "Number of 84 cent: " << F[3] << endl;
	cout << "Number of 235 cent: " << F[4] << endl;
}