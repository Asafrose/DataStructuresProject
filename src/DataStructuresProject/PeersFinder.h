#ifndef PEERSFINDER_H
#define PEERSFINDER_H
#include "StaticList.h"

class PeersFinder
{
public:
	static StaticList<int> FindPeersRecursive();
	static StaticList<int> FindPeersIterative();
};
#endif // PEERSFINDER_H
