#ifndef ALLOCATINGLIST_H
#define ALLOCATINGLIST_H
#include <functional>

#include "Iterator.h"

// Allocating list class 
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

		TItem Current() override
		{
			return _node->Data;
		}
	};
	

	ListNode* _head;
	ListNode* _tail;


public:
	//Ctr for new list
	AllocatingList() : _head(nullptr), _tail(nullptr)
	{
	}

	//returns 'true' if list is empty
	bool IsEmpty()
	{
		return (_tail == nullptr);
	}

	//adds new item at the tail of the list and updates the tail
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

	//removes the tail item of the list and updates tail value
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

	// returns tail's data
	TItem GetTail()
	{
		return _tail->Data;
	}

	Iterator<TItem>* GetIterator(bool reversed = false)
	{
		return new AllocatingListIterator(reversed ? _tail : _head, !reversed);
	}

	// destructor  
	~AllocatingList()
	{
		while (!IsEmpty())
		{
			Remove();
		}
	}
};

#endif
