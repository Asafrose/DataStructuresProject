#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H
#include "Player.h"

class OrderedList 
{
private:
	class ListNode
	{
	public:
		const Player* _data;
		ListNode* _prev;
		ListNode* _next;

		ListNode(const Player* player);
		
	
	};

	ListNode* _head;
	ListNode* _tail;
public:
	OrderedList();
	~OrderedList();

	void Add(const Player* player);

	friend ostream& operator<<(ostream& os, const OrderedList& players);
};
#endif // ORDEREDLIST_H
