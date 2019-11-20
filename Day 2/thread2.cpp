#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <mutex>

using namespace std;

mutex cout_mutex;

class Worker
{
public:
	Worker(string n) : name(n) {}

	void operator()() 
	{
		for (int i = 0; i <= 3; i++)
		{
			this_thread::sleep_for(chrono::seconds(1));
			{
				// RAII
				lock_guard<mutex> cout_lock(cout_mutex);
				cout << name << " " << this_thread::get_id() << endl;
			}
		}
	}
private:
	string name;
};

int main()
{
	thread t1(Worker("John"));
	thread t2(Worker("Sue"));
	thread t3(Worker("Pete"));
	thread t4(Worker("Anna"));
	thread t5(Worker("Tom"));

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	return 0;
}