#ifndef ALLOCATINGLIST_H
#define ALLOCATINGLIST_H
#include <functional>

#include "Iterator.h"

//Class that implements list with dynamic amount of items
template <class TItem>
class AllocatingList
{
private:
	//Private nested class for list node
	class ListNode
	{
	public:
		TItem Data;
		ListNode* Next;
		ListNode* Prev;

		ListNode(TItem data) : Data(data), Next(nullptr), Prev(nullptr)
		{
		}
	};

	//Derived class from iterator to iterate over an allocating list
	class AllocatingListIterator final : public Iterator<TItem>
	{
	private:
		ListNode* _node;
		bool _moveForward;
		bool _isStarted;

	public:
		AllocatingListIterator(ListNode* node, bool moveForward) : _node(node), _moveForward(moveForward), _isStarted(false)
		{
		}
		AllocatingListIterator(const AllocatingListIterator& other) = default;
		~AllocatingListIterator() = default;

		//move to the next item in the iteration
		bool MoveNext() override
		{
			if (!_isStarted)
			{
				_isStarted = true;
			}
			else
			{
				_node =
					_moveForward
					? _node->Next
					: _node->Prev;
			}

			return _node != nullptr;
		}

		//the current item in the iteration
		TItem Current() override
		{
			return _node->Data;
		}
	};
	

	ListNode* _head;
	ListNode* _tail;


public:
	AllocatingList() : _head(nullptr), _tail(nullptr)
	{
	}

	//Returns weather there are no items in the list
	bool IsEmpty()
	{
		return (_tail == nullptr);
	}

	//Adds an item to the end of the list
	void Add(TItem item)
	{
		ListNode* newNode = new ListNode(item);
		if (_tail == nullptr)
		{
			_head = newNode;
			_tail = newNode;
		}
		else
		{
			newNode->Prev = _tail;
			_tail->Next = newNode;
			_tail = newNode;
		}
	}

	//Removes an item from the end of the list
	void Remove()
	{
		ListNode* temp = _tail;
		if (_tail->Prev != nullptr)
		{
			_tail->Prev->Next = nullptr;
			_tail = _tail->Prev;
			temp->Prev = nullptr;
		}
		else
		{
			_tail = nullptr;
			_head = nullptr;
		}

		delete temp;
	}

	//Gets the last item of the list
	TItem GetTail()
	{
		return _tail->Data;
	}

	//Gets the iterator for the allocating list
	Iterator<TItem>* GetIterator(bool reversed = false)
	{
		return new AllocatingListIterator(reversed ? _tail : _head, !reversed);
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
