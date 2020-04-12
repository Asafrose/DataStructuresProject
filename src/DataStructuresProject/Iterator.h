#ifndef ITERATOR_H
#define ITERATOR_H

template <class TItem>
class Iterator
{
public:
	virtual ~Iterator() = default;
	virtual bool MoveNext() = 0;
	virtual TItem Current() = 0;

	void ForEach(void action(TItem data))
	{
		while (MoveNext())
		{
			action(Current());
		}
	}
};
#endif // ITERATOR_H
