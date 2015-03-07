#include "stdafx.h"
#include "coinStruct.h"
#include <iostream>

using namespace std;

coinStruct::coinStruct()
{
	this->totalNbCoins = 0;
	this->nbEachCoin = new int[5];
	for (short i = 0; i < 5; i++)
	{
		nbEachCoin[i] = 0;
	}

}