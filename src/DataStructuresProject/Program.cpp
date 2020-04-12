#include <iostream>

#include "NetworkInputHelper.h"
#include "PeersFinder.h"

using namespace std;

void PrintPeers(StaticList<int> peers)
{
	Iterator<int>* iterator = peers.GetIterator();
	iterator->ForEach([](int computer) { cout << " " << computer; });
	delete iterator;
}

int main()
{
	int size;
	AllocatingList<int>* network = NetworkInputHelper::GetNetwork(size);

	int source;
	cin >> source;
	
	if ((source > size -1)||(source<1))
	{
		cout << "no such computer " << source;
		exit(1);
	}
	
	PrintPeers(PeersFinder::FindPeersRecursive(source, network, size));
	cout << endl;
	PrintPeers(PeersFinder::FindPeersIterative(source, network, size));

    delete[] network;
}
