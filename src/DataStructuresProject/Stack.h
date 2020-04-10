#ifndef STACK_H
#define STACK_H
#include "AlloctingList.h"

template <class TItem>
class Stack
{
private:
	AllocatingList<TItem> _list;
public:
	bool IsEmpty();
	void Push(TItem item);
	TItem Pop();
	TItem Top();
};
#endif // STACK_H
