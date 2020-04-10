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
