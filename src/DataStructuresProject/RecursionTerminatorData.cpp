#include "RecursionTerminatorData.h"

// ctor 
RecursionTerminatorData::RecursionTerminatorData(int source, RecursionLine recursionLine) :
	_source(source),
	_recursionLine(recursionLine)
{
}

// returns source computer 
int RecursionTerminatorData::GetSource() const
{
	return _source;
}

// returns recursion line. 
RecursionLine RecursionTerminatorData::GetRecursionLine() const
{
	return _recursionLine;
}
