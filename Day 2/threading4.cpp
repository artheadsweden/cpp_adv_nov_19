#include <iostream>
#include <thread>
#include <functional>
#include <chrono>
#include <string>

using namespace std;

class ThreadWrapper
{
public:
	explicit ThreadWrapper(function<void()> f, string n) : t(new thread(f)), name (n){}

	~ThreadWrapper()
	{
		if (t->joinable())
		{
			t->join();
			cout << name << " Joined" << endl;
		}
		delete t;
	}

	ThreadWrapper(const ThreadWrapper&) = delete;
	ThreadWrapper& operator=(const ThreadWrapper&) = delete;

private:
	thread* t;
	string name;
};

int main()
{
	ThreadWrapper tw1([]
		{
			cout << "Hi from thread 1" << endl;
			this_thread::sleep_for(chrono::seconds(4));
		},
		"One"
	);
	ThreadWrapper tw2([]
		{
			cout << "Hi from thread 2" << endl;
			this_thread::sleep_for(chrono::seconds(2));
		},
		"Two"
	);

	return 0;
}