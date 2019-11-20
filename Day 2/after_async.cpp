#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <future>


using namespace std;

string fetchFromDB(string recvData)
{
	this_thread::sleep_for(chrono::seconds(5));
	return "DB_" + recvData;
}

string fetchFromFile(string recvData)
{
	this_thread::sleep_for(chrono::seconds(4));
	return "File_" + recvData;
}

int main()
{
	auto start = chrono::system_clock::now();
	future<string> future_dbData = async(launch::async, fetchFromDB, "Data");
	future<string> future_fileData = async(launch::async, fetchFromFile, "Data");

	string dbData = future_dbData.get();
	string fileData = future_fileData.get();
	auto end = chrono::system_clock::now();
	auto diff = chrono::duration_cast<chrono::seconds>(end - start).count();
	cout << "Time taken: " << diff << " seconds" << endl;
	cout << dbData << "::" << fileData << endl;


	return 0;
}