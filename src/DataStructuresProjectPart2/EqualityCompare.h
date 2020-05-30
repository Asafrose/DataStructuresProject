

#ifndef EQUALITYCOMPARE_H
#define EQUALITYCOMPARE_H

//Class used to compare persons by id. the class counts number of comparisons preformed.
class EqualityComparer
{
private:
	int _count;

	//private ctor
	EqualityComparer();
public:
	//Singelton instance
	static EqualityComparer Instance;

	//Compare 2 ids
	//Returns 0 if first == second
	//Returns positive if first > second
	//Returns negative if first < second
	int Compare(int first, int second);

	//Resets comparison counter
	void Reset();
	//Get current comparison count
	int GetCount() const;
};


#endif // EQUALITYCOMPARE_H


