#include "NetworkInputHelper.h"

#include <iostream>

using namespace std;

AllocatingList<int>* NetworkInputHelper::GetNetwork(int& size)
{
	cin >> size;
	size++;
	AllocatingList<int>* result = new AllocatingList<int>[size];

	int connectionsCount;
	cin >> connectionsCount;
	for (int i = 0; i < connectionsCount; ++i)
	{
		int sourceComputer;
		int destinationComputer;

		cin >> sourceComputer >> destinationComputer;
		result[sourceComputer].Add(destinationComputer);
	}

	return result;
}
