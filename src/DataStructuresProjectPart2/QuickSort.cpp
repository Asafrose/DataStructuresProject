#include "QuickSort.h"
#include "EqualityCompare.h"

void QuickSort::Sort(Player* players[], int count)
{
	Sort(players, 0, count - 1);
}

void QuickSort::Sort(Player* players[], int left, int right)
{
	if (left < right)
	{
		int pivot = Partition(players, left, right);
		Sort(players, left, pivot - 1);
		Sort(players, pivot + 1, right);
	}
}

int QuickSort::Partition(Player* players[], int left, int right)
{
	bool pivotOnLeft = true;

	while (left != right)
	{
		if (EqualityComparer::Instance.Compare(players[left]->GetId(), players[right]->GetId()) > 0)
		{
			swap(players[left], players[right]);
			pivotOnLeft = !pivotOnLeft;
		}

		if (pivotOnLeft)
		{
			right--;
		}
		else
		{
			left++;
		}
	}

	return right;
}
