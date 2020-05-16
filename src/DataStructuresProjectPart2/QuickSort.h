
#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Player.h"
class QuickSort
{
private:
	static int Partition(Player* players[], int left, int right);
	static void Sort(Player* players[], int left, int right);
public:
	static void Sort(Player* players[], int count);
	
};
#endif // QUICKSORT_H
