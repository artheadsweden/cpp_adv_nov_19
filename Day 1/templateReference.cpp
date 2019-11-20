#include <iostream>
#include <string>
//# include "type.h"

using namespace std;

void process(int& arg)
{
	cout << "lvalue process" << endl;
}

void process(int&& arg)
{
	cout << "rvalue process" << endl;
}

template <typename T>
void temp_func(T&& param)
{
	//process(param);
	process(forward<T>(param));
}

int main()
{
	int x = 10;
	temp_func(x);
	temp_func(13);
	return 0;
}