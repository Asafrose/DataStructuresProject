#ifndef PEERSFINDER_H
#define PEERSFINDER_H
#include "AlloctingList.h"
#include "StaticList.h"

class PeersFinder
{
public:
	//Function finds the peers of given computer using recursion
	//recursion is done with "FindPeersRecursiveInternal"
	static StaticList<int> FindPeersRecursive(int source, AllocatingList<int>* network, int computersCount);

	//Function finds the peers of given computer using iteration with stack
	static StaticList<int> FindPeersIterative(int source, AllocatingList<int>* network, int computersCount);
};
#endif // PEERSFINDER_H
