#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H
#include "Player.h"

//Class representing a linked list that is always ordered by player id
class OrderedList
{
private:
	//internal linked list node class
	class ListNode
	{
	public:
		const Player* _data;
		ListNode* _prev;
		ListNode* _next;

		//ctor
		ListNode(const Player* player);
	};

	ListNode* _head;
	ListNode* _tail;
public:
	//ctor
	OrderedList();
	//dtor
	~OrderedList();

	//add a player to a list
	void Add(const Player* player);

	//ostream operator
	friend ostream& operator<<(ostream& os, const OrderedList& players);
};
#endif // ORDEREDLIST_H
