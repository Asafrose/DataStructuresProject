#include <iostream>

#include "NetworkInputHelper.h"
#include "PeersFinder.h"
#include "StaticList.h"

int main()
{
    int size;
    AllocatingList<int>* network = NetworkInputHelper::GetNetwork(size);

    PeersFinder::FindPeersRecursive().ForEach([](int peer) { std::cout << peer << " "; });
	
    PeersFinder::FindPeersIterative().ForEach([](int peer) { std::cout << peer << " "; });
	
    std::cout << "Hello World!\n";
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