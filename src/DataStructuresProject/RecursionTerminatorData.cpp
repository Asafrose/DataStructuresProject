#include "RecursionTerminatorData.h"

RecursionTerminatorData::RecursionTerminatorData(int source, RecursionState recursionLine) :
	_source(source),
	_recursionLine(recursionLine)
{
}

RecursionTerminatorData::RecursionTerminatorData(const RecursionTerminatorData& other):
	RecursionTerminatorData(other.GetSource(), other.GetRecursionLine())
{
}

RecursionTerminatorData::~RecursionTerminatorData() = default;

int RecursionTerminatorData::GetSource() const
{
	return _source;
}

RecursionState RecursionTerminatorData::GetRecursionLine() const
{
	return _recursionLine;
}
