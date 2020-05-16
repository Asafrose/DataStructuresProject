#include <sstream>
#include "Exception.h"

Exception::Exception(const string& message) : _message(message)
{
}

string Exception::GetMessage() const
{
	return _message;
}

ostream& operator<<(ostream& os, const Exception& exception)
{
	os << exception._message;

	return os;
}
