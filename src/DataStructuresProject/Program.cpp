#include <iostream>

#include "NetworkInputHelper.h"
#include "PeersFinder.h"

using namespace std;

int main()
{
	int size;
	AllocatingList<int>* network = NetworkInputHelper::GetNetwork(size);

	int source;
	cout << "Please enter source computer: ";
	cin >> source;
	cout << "RECURSIVE: The computers that are accessible from computer " << source << " are:";
	PeersFinder::FindPeersRecursive(source, network, size).ForEach([](int computer) { cout << " " << computer; });

	cout << endl << "ITERATIVE: The computers that are accessible from computer " << source << " are:";
	PeersFinder::FindPeersIterative(source, network, size).ForEach([](int computer) { cout << " " << computer; });

    delete[] network;
}

/*
 *  AlloctingList
 *      AllocatingListNode
 *
 *  StaticList
 *      StaticListNode
 *
 *  Stack
 *      AllocatingList
 *
 *  ItemType
 *      
 */
