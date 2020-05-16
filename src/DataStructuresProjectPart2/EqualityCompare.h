

#ifndef EQUALITYCOMPARE_H
#define EQUALITYCOMPARE_H


class EqualityComparer
{
private:
	int _count;

	EqualityComparer();
public:
	static EqualityComparer Instance;
	int Compare(int first, int second);
	
	void Reset();
	int GetCount();
};


#endif // EQUALITYCOMPARE_H


