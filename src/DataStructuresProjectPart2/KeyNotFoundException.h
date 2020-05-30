#pragma once
#include "Exception.h"

//exception indicating that a certain key was not found in a dictionary
class KeyNotFoundException final : public Exception
{
public:
	KeyNotFoundException();
};
