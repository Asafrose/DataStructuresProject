#include "NetworkInputHelper.h"

#include <iostream>

using namespace std;

// function receives a prt to int, creates an array of allocating list , updates the prt value with Array size and returns the array.
// each item in the array holds the allocating list of connections with the corresponding computer as source
AllocatingList<int>* NetworkInputHelper::GetNetwork(int& size)
{
	cin >> size;
	if (size < 1)
	{
		cout << "not valid size ";
		exit(1);
	}
	size++;
	AllocatingList<int>* result = new AllocatingList<int>[size];

	int connectionsCount;
	cin >> connectionsCount;
	if(connectionsCount<0)
	{
		cout << "not valid connections amount ";
		exit(1);
	}
	
	for (int i = 0; i < connectionsCount; ++i)
	{
		int sourceComputer;
		int destinationComputer;

		cin >> sourceComputer >> destinationComputer;

		if (sourceComputer > size - 1)
		{
			cout << "no such computer " << sourceComputer;
			exit(1);
		}
		if (destinationComputer > size - 1)
		{
			cout << "no such computer " << destinationComputer;
			exit(1);
		}

		result[sourceComputer].Add(destinationComputer);
	}

	return result;
}
