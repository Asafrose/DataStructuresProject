#ifndef NETWORKINPUTHELPER_H
#define NETWORKINPUTHELPER_H
#include "AlloctingList.h"

class NetworkInputHelper
{
public:
	static AllocatingList<int>* GetNetwork(int& size);
};
#endif // NETWORKINPUTHELPER_H
