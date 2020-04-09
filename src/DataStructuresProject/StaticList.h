#ifndef STATICLIST_H
#define STATICLIST_H

template <class TItem>
class StaticList
{
private:
	class ListNode
	{
	public:
		TItem Data;
		int Next;
	};

	static constexpr int ListEnd = -1;

	const int _physicalSize;
	ListNode* const _nodes;

	int _size;
	int _head;
	int _tail;
	int _nextLocation;


public:
	StaticList(int size) : _physicalSize(size), _nodes(new ListNode[_physicalSize])
	{
		_size = 0;
		_head = ListEnd;
		_tail = ListEnd;
		_nextLocation = 0;

		for (int i = 0; i < _physicalSize - 1; ++i)
		{
			_nodes[i]._next = i + 1;
		}

		_nodes[_physicalSize - 1]._next = ListEnd;
	}

	~StaticList()
	{
		delete[] _nodes;
	}

	void Add(TItem item)
	{
		_nodes[_nextLocation]._data = item;
		const int newNextLocation = _nodes[_nextLocation]._next;
		_nodes[_nextLocation]._next = ListEnd;

		if (_tail != ListEnd)
		{
			_nodes[_tail]._next = _nextLocation;
		}
		if (_head == ListEnd)
		{
			_head = _nextLocation;
		}

		_tail = _nextLocation;
		_nextLocation = newNextLocation;
	}

	void ForEach(void action(TItem item))
	{
		int current = _head;
		while (current != ListEnd)
		{
			action(_nodes[current]._data);
			current = _nodes[current]._next;
		}
	}
};

#endif // STATICLIST_H
