#ifndef STACK_H
#define STACK_H
#include "AlloctingList.h"

//Class implementing the ADT stack with dynamic number of items
template <class TItem>
class Stack
{
private:
	//The underlying list used to implement the stack
	AllocatingList<TItem> _list;
public:

	//Returns weather there are no items in the stack
	bool IsEmpty()
	{
		return _list.IsEmpty();
	}

	//Adds item to top of the stack
	void Push(TItem item)
	{
		_list.Add(item);
	}

	//Removes and returns the top item in the stack
	TItem Pop()
	{
		TItem item = _list.GetTail();
		_list.Remove();
		return item;
	}

	//Returns the top item in the stack without removing it
	TItem Top()
	{
		return _list.GetTail();
	}
};
#endif // STACK_H
