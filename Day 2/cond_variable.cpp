#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

auto data_chunk = 0;
queue<int> data_queue;
mutex queue_mut;
mutex data_chunk_mut;

condition_variable data_cond;

auto prepare_data()
{
	this_thread::sleep_for(chrono::seconds(rand() % 5 + 1));
	lock_guard<mutex> lg(data_chunk_mut);
	return data_chunk++;
}

auto more_data_to_prepare()
{
	return data_chunk < 20;
}

void data_preperation_thread()
{
	while (more_data_to_prepare())
	{
		auto const data = prepare_data();
		lock_guard<mutex> lg(queue_mut);
		data_queue.push(data);
		data_cond.notify_one();
	}
}

void process(int data)
{
	cout << data << endl;
}


auto is_last_chunk(int data)
{
	return data == 19;
}

void data_processing_thread()
{
	while (true)
	{
		unique_lock<mutex> lock(queue_mut);
		data_cond.wait(lock, [] {return !data_queue.empty(); });
		auto data = data_queue.front();
		data_queue.pop();
		process(data);
		lock.unlock();
		if (is_last_chunk(data))
		{
			break;
		}
	}
}

int main()
{
	thread producer1(data_preperation_thread);
	thread producer2(data_preperation_thread);
	thread consumer(data_processing_thread);
	producer1.join();
	producer2.join();
	consumer.join();
	return 0;
}