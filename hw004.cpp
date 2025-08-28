#include <iostream>
using namespace std;

class MyClass{
	int a, b, c;
public:
	MyClass(int x, int y, int z)
	{
		a = x;
		b = y;
		c = z;
	}
	friend void display(MyClass);
};

void display(MyClass obj)
{
	cout << "Accessing private members: " << endl;
	cout << "A = " << obj.a << "\tB = " << obj.b << "\tC = " << obj.c << endl;
}

int main()
{
	MyClass obj(34, 45, 67);
	display(obj);
	return 0;
}
