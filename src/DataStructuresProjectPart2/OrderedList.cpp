#include "OrderedList.h"
#include "EqualityCompare.h"

#include <ostream>

OrderedList::ListNode::ListNode(const Player* player): _data(player), _prev(nullptr), _next(nullptr)
{
}


OrderedList::OrderedList(): _head(new ListNode(nullptr)), _tail(new ListNode(nullptr))
{
	_head->_next = _tail;
	_tail->_prev = _head;
}

OrderedList::~OrderedList()
{
	ListNode* index = _head->_next;
	while(index!=_tail)
	{
		ListNode* tmp = index;
		index = index->_next;
		delete tmp;
	}
}

void OrderedList::Add(const Player* player)
{
	
	ListNode* newNode = new ListNode(player);
	
	ListNode* index = _head->_next;
	while (index != _tail)
	{
		if (EqualityComparer::Instance.Compare(index->_data->GetId() , player->GetId()) > 0)
		{
			
			index->_prev->_next = newNode;
			newNode->_prev = index->_prev;
			index->_prev = newNode;
			newNode->_next = index;
			return;
		}
		index = index->_next;
	}

	_tail->_prev->_next = newNode;
	newNode->_prev = _tail->_prev;
	_tail->_prev = newNode;
	newNode->_next = _tail;
}

ostream& operator<<(ostream& os, const OrderedList& players)
{
	OrderedList::ListNode* index = players._head->_next;
	while(index!=players._tail)
	{
		os << *index->_data << endl;
		index = index->_next;
	}
	return os;
}
