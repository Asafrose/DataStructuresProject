#ifndef ALLOCATINGLIST_H
#define ALLOCATINGLIST_H
#include <functional>


template <class TItem>
class AllocatingList
{
private:
	class ListNode
	{
	private:
		TItem _data;
		ListNode* _next;
		ListNode* _prev;
		friend AllocatingList<TItem>;

		ListNode(TItem data) : _data(data), _next(nullptr), _prev(nullptr)
		{
		}
	};

	ListNode* _head;
	ListNode* _tail;


public:
	AllocatingList() : _head(nullptr), _tail(nullptr)
	{
	}

	bool IsEmpty()
	{
		return (_tail == nullptr);
	}

	void Add(TItem item)
	{
		ListNode* new_node = new ListNode(item);
		if (_tail == nullptr)
		{
			_head = new_node;
			_tail = new_node;
		}
		else
		{
			new_node->_prev = _tail;
			_tail->_next = new_node;
			_tail = new_node;
		}
	}

	void Remove()
	{
		ListNode* temp = _tail;
		if (_tail->_prev != nullptr)
		{
			_tail->_prev->_next = nullptr;
			_tail = _tail->_prev;
			temp->_prev = nullptr;
		}
		else
		{
			_tail = nullptr;
			_head = nullptr;
		}

		delete temp;
	}

	TItem GetTail()
	{
		return _tail->_data;
	}

	void ForEach(std::function<void(TItem)> function)
	{
		ListNode* node = _head;
		while (node != nullptr)
		{
			function(node->_data);
			node = node->_next;
		}
	}

	void ReversedForEach(std::function<void(TItem)> function)
	{
		ListNode* node = _tail;
		while (node != nullptr)
		{
			function(node->_data);
			node = node->_prev;
		}
	}

	~AllocatingList()
	{
		while (!IsEmpty())
		{
			Remove();
		}
	}
};

#endif
