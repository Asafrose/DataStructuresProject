
#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Player.h"

//static class for sorting arrays using quick sort
class QuickSort
{
private:
	//Partition implementation
	static int Partition(Player* players[], int left, int right);
	//internal Sort using left and right indicators
	static void Sort(Player* players[], int left, int right);
public:
	//public sort API
	static void Sort(Player* players[], int count);
	
};
#endif // QUICKSORT_H
