#ifndef STATICLIST_H
#define STATICLIST_H

template <class TItem>
class StaticList
{
private:
	static constexpr int ListEnd = -1;
	
	class ListNode
	{
	public:
		TItem Data;
		int Next;
	};

	class StaticListIterator final : public Iterator<TItem>
	{
		ListNode* _nodes;
		int _index;
		bool _isStarted;
		
	public:
		StaticListIterator(ListNode* nodes, int index) : _nodes(nodes), _index(index), _isStarted(false)
		{
		}
		StaticListIterator(const StaticListIterator& other) = default;
		~StaticListIterator() = default;
		
		bool MoveNext() override
		{
			if (!_isStarted)
			{
				_isStarted = true;
			}
			else
			{
				_index = _nodes[_index].Next;
			}

			return _index != ListEnd;
		};
		
		TItem Current() override
		{
			return _nodes[_index].Data;
		}
	};

	

	const int _physicalSize;
	ListNode* const _nodes;

	int _size;
	int _head;
	int _tail;
	int _nextLocation;


public:
	// Creates empty static list of size 'size' 
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

	StaticList(StaticList&& other) : StaticList(other)
	{
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

	Iterator<TItem>* GetIterator()
	{
		return new StaticListIterator(_nodes, _head);
	}
};

#endif // STATICLIST_H
