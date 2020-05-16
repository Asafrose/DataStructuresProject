
#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

using namespace std;

class Exception
{
	string _message;
public:

	Exception(const string& message);
	virtual ~Exception() = default;

	string GetMessage() const;

	friend ostream& operator<<(ostream& os, const Exception& exception);
};
#endif // EXCEPTION_H
