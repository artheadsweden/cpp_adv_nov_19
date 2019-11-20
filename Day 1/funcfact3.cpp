#include <iostream>
#include <functional>

using namespace std;

function<int(int)> funcfact(int x)
{
	return [=](int y)
	{
		return y * x;
	};
}

int main()
{
	auto f1 = funcfact(2);
	function<int(int)> f2 = funcfact(3);
	cout << f1(3) << endl;
	cout << f2(3) << endl;
	return 0;
}