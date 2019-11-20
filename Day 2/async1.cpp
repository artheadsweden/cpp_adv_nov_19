#include <iostream>
#include <future>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

int twice(int x)
{
	cout << "x * 2 = " << x * 2 << endl;
	this_thread::sleep_for(chrono::seconds(rand() % 3 + 1));
	return x * 2;
}

int main()
{
	vector<future<int>> futures;
	for (int i = 0; i < 10; i++)
	{
		futures.push_back(async(twice, i));
	}
	for (auto& f : futures)
	{
		cout << f.get() << endl;
	}
	return 0;
}