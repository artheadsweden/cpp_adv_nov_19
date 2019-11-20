#include <iostream>

using namespace std;

class MyClass
{
public:
	MyClass() : value(nullptr)
	{
		cout << "Default constructor" << endl;
	}

	MyClass(int* v) : value(v)
	{
		cout << "Constructor with argument" << endl;
	}

	MyClass(const MyClass& other) : value(other.value)
	{
		cout << "Copy constructor" << endl;
	}

	MyClass(MyClass&& other) : value(nullptr)
	{
		swap(value, other.value);
		cout << "Move constructor" << endl;
	}

	MyClass& operator=(const MyClass& other)
	{
		value = other.value;
		cout << "Copy assignment operator" << endl;
		return *this;
	}

	void print()
	{
		if (value != nullptr) {
			cout << *value << endl;
		}
		else {
			cout << "null" << endl;
		}
	}

private:
	int* value;
};

int main()
{
	int x = 10;
	MyClass m1(&x);
	MyClass m2 = move(m1);
	m1.print();
	m2.print();
	return 0;
}