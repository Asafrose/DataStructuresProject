#include "RecursionTerminatorData.h"

RecursionTerminatorData::RecursionTerminatorData(int source, RecursionLine recursionLine) :
_source(source),
_recursionLine(recursionLine)
{
}

int RecursionTerminatorData::GetSource() const
{
	return _source;
}

RecursionLine RecursionTerminatorData::GetRecursionLine() const
{
	return _recursionLine;
}
