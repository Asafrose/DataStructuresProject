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
			_nodes[i].Next = i + 1;
		}

		_nodes[_physicalSize - 1].Next = ListEnd;
	}

	StaticList(StaticList& other) :
		_physicalSize(other._physicalSize),
		_nodes(new ListNode[_physicalSize]),
		_size(other._size),
		_head(other._head),
		_tail(other._tail),
		_nextLocation(other._nextLocation)
	{
		for (int i = 0; i < _physicalSize; ++i)
		{
			_nodes[i] = other._nodes[i];
		}
	}

	~StaticList()
	{
		delete[] _nodes;
	}

	void Add(TItem item)
	{
		_nodes[_nextLocation].Data = item;
		const int newNextLocation = _nodes[_nextLocation].Next;
		_nodes[_nextLocation].Next = ListEnd;

		if (_tail != ListEnd)
		{
			_nodes[_tail].Next = _nextLocation;
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
			action(_nodes[current].Data);
			current = _nodes[current].Next;
		}
	}
};

#endif // STATICLIST_H
