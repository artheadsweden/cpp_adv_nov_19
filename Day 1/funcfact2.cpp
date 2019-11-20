#include <iostream>

using namespace std;

int main()
{
	auto funcfact = [](int x)
	{
		return [=](int y) {
			return x * y;
		};
	};

	auto f1 = funcfact(2);
	auto f2 = funcfact(3);
	cout << f1(3) << endl;
	cout << f2(3) << endl;
	return 0;
}