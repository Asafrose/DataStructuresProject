#include "RecursionTerminatorData.h"

RecursionTerminatorData::RecursionTerminatorData(int source, RecursionLine recursionLine) :
_source(source),
_recursionLine(recursionLine)
{// ctor 
}

int RecursionTerminatorData::GetSource() const
{ // returns source computer 
	return _source;
}

RecursionLine RecursionTerminatorData::GetRecursionLine() const
{ // returns recursion line. 
	return _recursionLine;
}
