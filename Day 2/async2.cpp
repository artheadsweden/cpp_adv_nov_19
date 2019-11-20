#include <iostream>
#include <numeric>
#include <vector>
#include <future>
#include <string>

using namespace std;

int accumulate_block(int* data, size_t count, string name)
{
	cout << name << endl;
	return accumulate(data, data + count, 0);
}

int main()
{
	vector<int> v1{ 1, 2, 3, 4, 5 };
	vector<int> v2{ 6, 7, 8, 9, 10 };
	future<int> result1(async(launch::deferred, accumulate_block, v1.data(), v1.size(), "deffered"));
	future<int> result2(async(launch::async, accumulate_block, v2.data(), v2.size(), "async"));
	cout << result1.get() << endl;
	cout << result2.get() << endl;
	return 0;
}