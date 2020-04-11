#ifndef STACK_H
#define STACK_H
#include "AlloctingList.h"

template <class TItem>
class Stack
{
private:
	AllocatingList<TItem> _list;
public:
	
	bool IsEmpty()
	{
		//returns true is the stack is empty
		return _list.IsEmpty();
	}
	void Push(TItem item)
	{
		// ads item to top of the stack
		_list.Add(item);
	}
	TItem Pop()
	{
		// removes and returns the top item in the stack
		TItem item = _list.GetTail();
		_list.Remove();
		return item;
		
	}
	TItem Top()
	{
		//returns the top item in the stack without removing it
		return _list.GetTail();
	}
};
#endif // STACK_H
