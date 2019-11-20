#include <iostream>

using namespace std;

void func(int& a)
{
	cout << "a is lvalue" << endl;
}

void func(int&& a)
{
	cout << "a is rvalue " << endl;
}

int main()
{
	int x = 10;
	func(x);
	func(10);
	return 0;
}