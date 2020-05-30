#include <iostream>


#include "OrderedList.h"
#include "Player.h"
#include "QuickSort.h"

using namespace std;

//adds players with key lower than highstKey to an ordered list, prints the list and returns comparison count
int NaivePrint(Player* players[], int count, int highestKey)
{
	EqualityComparer::Instance.Reset();
	OrderedList list;
	for (int i = 0; i < count; ++i)
	{
		if (EqualityComparer::Instance.Compare(players[i]->GetId(), highestKey) < 0)
		{
			list.Add(players[i]);
		}
	}

	cout << list;
	return EqualityComparer::Instance.GetCount();
}

//adds all players to a binary search tree, print tree values until highestKey in-order, returns comparison count
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

//sorts players array with QuickSort, prints players by order until reaching highestKey and returns comparison count
int PrintBySort(Player* players[], int count, int highestKey)
{
	EqualityComparer::Instance.Reset();
	QuickSort::Sort(players, count);

	for (int i = 0; i < count && EqualityComparer::Instance.Compare(players[i]->GetId(), highestKey) < 0; ++i)
	{
		cout << *players[i] << endl;
	}

	return EqualityComparer::Instance.GetCount();
}

//get player array and count from user input
Player** GetPlayers(int& count)
{
	cin >> count;
	Player** result = new Player*[count];
	for (int i = 0; i < count; ++i)
	{
		result[i] = Player::CreatePlayerFromUserInput();
	}
	return result;
}

//main function.
int main()
{
	int count, highestKey;
	Player** players = nullptr;

	try
	{
		players = GetPlayers(count);
		cin >> highestKey;

		const int naivePrint = NaivePrint(players, count, highestKey);
		cout << "--------------------------------------" << endl;
		const int bstPrint = BSTPrint(players, count, highestKey);
		cout << "--------------------------------------" << endl;
		const int printBySort = PrintBySort(players, count, highestKey);

		cout << "--------------------------------------" << endl;

		cout << "NaivePrint: " << naivePrint << " comparisons" << endl;
		cout << "BSTPrint: " << bstPrint << " comparisons" << endl;
		cout << "PrintBySort: " << printBySort << " comparisons" << endl;

		delete[] players;
	}
	catch (Exception exception)
	{
		cout << "Invalid Input: " << exception << endl;
		delete[] players;
		exit(1);
	}
}