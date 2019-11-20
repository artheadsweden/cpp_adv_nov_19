#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>

using namespace std;

void threads()
{
	//int x = 0;
	atomic<int> x = 0;

	auto worker = [&x]
	{
		for (int i = 0; i < 40'000'000; i++)
		{
			x++;
		}
	};
	auto start = chrono::system_clock::now();
	thread t1(worker);
	thread t2(worker);
	thread t3(worker);
	thread t4(worker);
	thread t5(worker);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	auto end = chrono::system_clock::now();
	auto diff = chrono::duration_cast<chrono::seconds>(end - start).count();
	cout << "Threads: " << x << endl;
	cout << "5 thread. It took " << diff << " seconds" << endl;
	
}

void no_threads()
{
	int x = 0;
	auto start = chrono::system_clock::now();
	for (int i = 0; i < 200'000'000; i++) 
	{
		x++;
	}
	auto end = chrono::system_clock::now();
	auto diff = chrono::duration_cast<chrono::seconds>(end - start).count();
	cout << "No threads: " << x << endl;
	cout << "1 thread. It took " << diff << " seconds" << endl;
}

int main()
{
	no_threads();
	threads();
	return 0;
}