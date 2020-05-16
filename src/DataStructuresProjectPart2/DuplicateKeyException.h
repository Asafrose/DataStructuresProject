#pragma once
#include "Exception.h"

class DuplicateKeyException : public Exception
{
public:
	DuplicateKeyException();
};
