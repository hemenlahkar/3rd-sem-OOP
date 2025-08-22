#include <iostream>

using namespace std;

class Triangle {
	int a, b, c;
public:
	Triangle(int x, int y, int z)
	{
		a = x;
		b = y;
		c = z;
	}
	bool isIsosceles()
	{
		if (a == b && a != c)
			return true;
		if (a == c && b != c)
			return true;
		if ( c == b && a != b)
			return true;
		return false;
	}
	bool isEquilateral()
	{
		return a == b && b == c;
	}
	
	void test()
	{
		cout << "Isosceles: " << isIsosceles() << endl;
		cout << "Equilateral: " << isEquilateral() << endl;
	}
};

int main()
{
	Triangle t(4, 4, 3);
	t.test();
	return 0;
}
