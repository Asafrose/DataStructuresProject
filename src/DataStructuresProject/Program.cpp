#include <iostream>

#include "NetworkInputHelper.h"
#include "PeersFinder.h"
#include "StaticList.h"
#include "Stack.h"

int main()
{
    int size;
    AllocatingList<int>* network = NetworkInputHelper::GetNetwork(size);
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