#include <iostream>

using namespace std;

int main()
{
	int x = 10;
	int y = 20;

	auto func = [&](int a, int b) 
	{
		return x + y + a + b;
	};

	cout << func(1, 2) << endl;
	x = 5;
	y = 6;
	cout << func(1, 2) << endl;



	return 0;
}