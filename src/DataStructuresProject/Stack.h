#ifndef STACK_H
#define STACK_H
#include "AlloctingList.h"

template <class TItem>
class Stack
{
private:
	AllocatingList<TItem> _list;
public:

	//returns true is the stack is empty
	bool IsEmpty()
	{
		return _list.IsEmpty();
	}

	// adds item to top of the stack
	void Push(TItem item)
	{
		_list.Add(item);
	}

	// removes and returns the top item in the stack
	TItem Pop()
	{
		TItem item = _list.GetTail();
		_list.Remove();
		return item;
	}

	//returns the top item in the stack without removing it
	TItem Top()
	{
		return _list.GetTail();
	}
};
#endif // STACK_H
