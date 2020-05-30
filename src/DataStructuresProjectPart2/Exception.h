
#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

using namespace std;

//Base class for exceptions
class Exception
{
	string _message;
public:
	//ctor
	Exception(const string& message);
	//dtor
	virtual ~Exception() = default;

	//gets message for the exception
	string GetMessage() const;

	//ostream operator
	friend ostream& operator<<(ostream& os, const Exception& exception);
};
#endif // EXCEPTION_H
