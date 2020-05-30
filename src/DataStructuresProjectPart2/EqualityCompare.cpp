#include "EqualityCompare.h"

EqualityComparer EqualityComparer::Instance;

EqualityComparer::EqualityComparer() : _count(0)
{
}

int EqualityComparer::Compare(int first, int second)
{
	_count++;
	return first - second;
}

void EqualityComparer::Reset()
{
	_count = 0;
}

int EqualityComparer::GetCount() const
{
	return _count;
}
