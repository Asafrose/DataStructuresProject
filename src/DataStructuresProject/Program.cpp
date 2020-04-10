#include <iostream>

#include "NetworkInputHelper.h"
#include "PeersFinder.h"
#include "StaticList.h"
#include "Stack.h"

int main()
{
    int size;

    Stack<int> stack;
	if(stack.IsEmpty())
	{
        std::cout << "Stack is Empty";
	}
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    std::cout << "top item is : " << stack.Pop();
    std::cout << "top item is : " << stack.Pop();
    std::cout << "top item is : " << stack.Pop();
	
	
    
	
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