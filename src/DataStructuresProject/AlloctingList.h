#ifndef ALLOCATINGLIST_H
#define ALLOCATINGLIST_H
#include <functional>


template <class TItem>
class AllocatingList
{
	// Allocating list template 
private:
	class ListNode
	{
		//Private class for node 
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
		//Ctr for new list
	}

	bool IsEmpty()
	{
		//returns 'true' if list is empty
		return (_tail == nullptr);
	}

	void Add(TItem item)
	{
		//adds new item at the tail of the list and updates the tail
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
		//removes the tail item of the list and updates tail value
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
		// returns tail's data
		return _tail->_data;
	}

	void ForEach(std::function<void(TItem)> function)
	{
		// function receives a function object, Objects needs to get same data type as the list and return void.
		// function goes over all list nodes and runs the function each time with the node data
		ListNode* node = _head;
		while (node != nullptr)
		{
			function(node->_data);
			node = node->_next;
		}
	}

	void ReversedForEach(std::function<void(TItem)> function)
	{ //same as foreach just from tail to head
		ListNode* node = _tail;
		while (node != nullptr)
		{
			function(node->_data);
			node = node->_prev;
		}
	}

	~AllocatingList()
	{// destructor  
		while (!IsEmpty())
		{
			Remove();
		}
	}
};

#endif
