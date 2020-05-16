#include <iostream>

using namespace std;

int main() noexcept(true)
{
	try
	{
		cout << "Hello World!\n";
	}
	catch (...)
	{
		cerr << "Error!";
		exit(1);
	}
}
