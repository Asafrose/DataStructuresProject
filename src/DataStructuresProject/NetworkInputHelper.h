#ifndef NETWORKINPUTHELPER_H
#define NETWORKINPUTHELPER_H
#include "AlloctingList.h"

class NetworkInputHelper
{
public:
	//Function receives a prt to int, creates an array of allocating list , updates the prt value with Array size and returns the array.
	//Each item in the array holds the allocating list of connections with the corresponding computer as source
	static AllocatingList<int>* GetNetwork(int& size);
};
#endif // NETWORKINPUTHELPER_H
