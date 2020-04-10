﻿#ifndef PEERSFINDER_H
#define PEERSFINDER_H
#include "AlloctingList.h"
#include "StaticList.h"

class PeersFinder
{
public:
	static StaticList<int> FindPeersRecursive(int source, AllocatingList<int>* network, int computersCount);
	static StaticList<int> FindPeersIterative();
};
#endif // PEERSFINDER_H
