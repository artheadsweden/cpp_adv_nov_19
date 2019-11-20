#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name = "Anna";
	auto f = [n = move(name)]()
	{
		cout << "Inside lambda " << n << endl;
	};
	f();
	cout << "Outside lambda " << name << endl;
	return 0;
}