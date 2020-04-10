#include "PeersFinder.h"
#include "RecursionTerminatorData.h"
#include "Stack.h"

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
	for (int i = 0; i < computersCount; ++i)
	{
		computerIdToIsVisitedMapping[i] = false;
	}

	StaticList<int> peers(computersCount);
	FindPeersRecursiveInternal(source, network, computerIdToIsVisitedMapping, peers);
	delete[] computerIdToIsVisitedMapping;
	return peers;
}

StaticList<int> PeersFinder::FindPeersIterative(int source, AllocatingList<int>* network, int computersCount)
{
	bool* computerIdToIsVisitedMapping = new bool[computersCount];
	for (int i = 0; i < computersCount; ++i)
	{
		computerIdToIsVisitedMapping[i] = false;
	}
	StaticList<int> peers(computersCount);
	Stack<RecursionTerminatorData> stack;

	stack.Push(RecursionTerminatorData(source, Start));
	while (!stack.IsEmpty())
	{
		RecursionTerminatorData current = stack.Pop();
		if (current.GetRecursionLine() == Start)
		{
			if (!computerIdToIsVisitedMapping[current.GetSource()])
			{
				peers.Add(current.GetSource());
				computerIdToIsVisitedMapping[current.GetSource()] = true;
				stack.Push(RecursionTerminatorData(current.GetSource(), AfterRecursion));

				network[current.GetSource()].ReversedForEach(
					[&](int computer)
					{
						stack.Push(RecursionTerminatorData(computer, Start));
					});
			}
		}
	}

	delete[] computerIdToIsVisitedMapping;
	return peers;
}
