#ifndef ITERATOR_H
#define ITERATOR_H

//Abstract base class for iteration over collections
template <class TItem>
class Iterator
{
public:
	virtual ~Iterator() = default;

	//Move to the next item in the iteration
	virtual bool MoveNext() = 0;

	//The current item in the iteration
	virtual TItem Current() = 0;

	//For each item in the collection preform an action
	void ForEach(void action(TItem data))
	{
		while (MoveNext())
		{
			action(Current());
		}
	}
};
#endif // ITERATOR_H
