#include <iostream>
#include <thread>
#include <string>


using namespace std;

class Worker
{
public:
	Worker(string n) : name(n){}

	void operator()() {
		cout << name << " " << this_thread::get_id() << endl;
	}
private:
	string name;
};

void worker()
{
	cout << "Worker " << this_thread::get_id() << endl;
}

int main()
{
	auto worker2 = []
	{
		cout << "Worker 2 " << this_thread::get_id() << endl;

	};
	thread t1(worker);
	thread t2(worker2);
	thread t3([] {cout << "Worker 3 " << this_thread::get_id() << endl; });
	thread t4(Worker("Number 4"));
	cout << "Main thread " << this_thread::get_id() << endl;
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	return 0;
}