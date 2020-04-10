#include "PeersFinder.h"

void FindPeersRecursiveInternal(int source,
                                AllocatingList<int>* network,
                                bool* computerIdToIsVisitedMapping,
                                StaticList<int>& peers)
{
	if (computerIdToIsVisitedMapping[source])
	{
		return;
	}

	peers.Add(source);
	computerIdToIsVisitedMapping[source] = true;

	network[source].ForEach(
		[&](int computer)
		{
			FindPeersRecursiveInternal(computer, network, computerIdToIsVisitedMapping, peers);
		});
}

StaticList<int> PeersFinder::FindPeersRecursive(int source, AllocatingList<int>* network, int computersCount)
{
	bool* computerIdToIsVisitedMapping = new bool[computersCount];
	StaticList<int> peers(computersCount);
	FindPeersRecursiveInternal(source, network, computerIdToIsVisitedMapping, peers);
	delete[] computerIdToIsVisitedMapping;
	return peers;
}
