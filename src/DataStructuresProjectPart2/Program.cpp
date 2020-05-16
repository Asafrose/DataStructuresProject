#include <iostream>


#include "OrderedList.h"
#include "Player.h"
#include "QuickSort.h"

using namespace std;

int NaivePrint(Player* players[], int count, int highestKey)
{
	EqualityComparer::Instance.Reset();
	OrderedList list;
	for (int i = 0; i < count; ++i)
	{
		if (EqualityComparer::Instance.Compare(players[i]->GetId(),highestKey) < 0)
		{
			list.Add(players[i]);
		}
	}
	
	cout << list;
	return EqualityComparer::Instance.GetCount();
}

int BSTPrint(Player* players[], int count, int highestKey)
{
	EqualityComparer::Instance.Reset();
	BinarySearchTree<Player*> tree;
	for (int i = 0; i < count; ++i)
	{
		tree.Insert(players[i]->GetId(), players[i]);
	}

	tree.PrintUntilKey(highestKey);
	return EqualityComparer::Instance.GetCount();
}

int PrintBySort(Player* players[], int count, int highestKey)
{
	EqualityComparer::Instance.Reset();
	QuickSort::Sort(players, count);

	for (int i = 0; i < count && EqualityComparer::Instance.Compare(players[i]->GetId(),highestKey) < 0; ++i)
	{
		cout << *players[i] << endl;
	}

	return EqualityComparer::Instance.GetCount();
}

Player** GetPlayers(int& count)
{
	cin >> count;
	Player** result = new Player * [count];
	for (int i = 0; i < count; ++i)
	{
		result[i] = Player::CreatePlayerFromUserInput();
	}
	return result;
}

int main()
{
	int count, highestKey;
	Player** players = nullptr;
	
	try
	{
		players = GetPlayers(count);
		cin >> highestKey;

		int naivePrint = NaivePrint(players, count, highestKey);
		int bstPrint = BSTPrint(players, count, highestKey);
		int printBySort = PrintBySort(players, count, highestKey);

		cout << "NaivePrint: " << naivePrint << " comparisons";
		cout << "BSTPrint: " << bstPrint << " comparisons";
		cout << "PrintBySort: " << printBySort << " comparisons";
	}
	catch (Exception exception)
	{
		cout << "Invalid Input: " << exception << endl;
		delete[] players;
		exit(1);
	}
	
}

// Player
// OrderedList
// BinarySearchTree
// 
