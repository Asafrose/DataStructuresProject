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
		return _list.IsEmpty();
	}
	void Push(TItem item)
	{
		_list.Add(item);
	}
	TItem Pop()
	{
		TItem item = _list.GetTail();
		_list.Remove();
		return item;
		
	}
	TItem Top()
	{
		return _list.GetTail();
	}
};
#endif // STACK_H
