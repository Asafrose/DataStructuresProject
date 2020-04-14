#ifndef RECURSIONTERMINATORDATA_H
#define RECURSIONTERMINATORDATA_H
#include "RecurtionState.h"

//Data that will be in the stack to terminate the need for recursion
class RecursionTerminatorData
{
private:
	const int _source{};
	const RecursionState _recursionLine;
public:
	RecursionTerminatorData(int source, RecursionState recursionLine);
	RecursionTerminatorData(const RecursionTerminatorData& other);
	~RecursionTerminatorData();

	//Get source computer
	int GetSource() const;

	//Get the recursion state
	RecursionState GetRecursionLine() const;
	
};
#endif // RECURSIONTERMINATORDATA_H
