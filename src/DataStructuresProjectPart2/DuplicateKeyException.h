#pragma once
#include "Exception.h"

//Exception indicating a duplicate key in a dictionary
class DuplicateKeyException final : public Exception
{
public:
	//ctor
	DuplicateKeyException();
};
