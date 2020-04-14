#include "PeersFinder.h"
#include "RecursionTerminatorData.h"
#include "Stack.h"

//recursive function to find the peers of given computer 'source' on given network using bool array 'computerIdToIsVisitedMapping'
//returning Static allocation list Peers
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

	Iterator<int>* iterator = network[source].GetIterator();
	while (iterator->MoveNext())
	{
		FindPeersRecursiveInternal(iterator->Current(), network, computerIdToIsVisitedMapping, peers);
	}
	delete iterator;
}

//function finds the Peers of given computer using recursive
//recursion is done with "FindPeersRecursiveInternal"
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

//function finds Peers of given computer 'Source' on 'network' array with 'computersCount' amount of computers
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

				Iterator<int>* iterator = network[current.GetSource()].GetIterator(true);
				while (iterator->MoveNext())
				{
					stack.Push(RecursionTerminatorData(iterator->Current(), Start));
				}
				delete iterator;
			}
		}
	}

	delete[] computerIdToIsVisitedMapping;
	return peers;
}
