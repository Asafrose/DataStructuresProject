#pragma once
#ifndef ALLOCATINGLIST_H
#define ALLOCATINGLIST_H


template <class TItem>
class AllocatingList
{
private:


	template <class TItem>
	class ListNode
	{
	private:
		TItem _data;
		ListNode<TItem>* _next;
		ListNode<TItem>* _prev;
		friend AllocatingList<TItem>;

		ListNode(TItem data) : _data(data), _next(nullptr), _prev(nullptr)
		{
		}
	};

	ListNode<TItem>* _head;
	ListNode<TItem>* _tail;


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
		ListNode<TItem>* new_node = new ListNode<TItem>(item);
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
		ListNode<TItem>* temp = _tail;
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


		free(temp);
	}

	TItem GetTail()
	{
		if (_tail != nullptr)
		{
			return _tail->_data;
		}
	}

	void ForEach(void function(TItem item))
	{
		ListNode<TItem>* node = _head;
		while (node != nullptr)
		{
			function(node->_data);
			node = node->_next;
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
