#include <iostream>
using namespace std;

inline int square(int x)
{
	return x * x;
}

int main()
{
	int a;
	cout << "Enter two numbers: ";
	cin >> a;
	int s = square(a);
	cout << "square: " << s << endl;
	return 0;
}
