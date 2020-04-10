#ifndef RECURSIONTERMINATORDATA_H
#define RECURSIONTERMINATORDATA_H
#include "RecurtionLine.h"

class RecursionTerminatorData
{
private:
	const int _source;
	const RecursionLine _recursionLine;
public:
	RecursionTerminatorData(int source, RecursionLine recursionLine);
	RecursionTerminatorData(const RecursionTerminatorData& other) = default;

	int GetSource() const;
	RecursionLine GetRecursionLine() const;
	
};
#endif // RECURSIONTERMINATORDATA_H
