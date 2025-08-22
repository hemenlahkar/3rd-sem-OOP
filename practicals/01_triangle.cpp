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
};

int main()
{
	Triangle t(4, 4, 3);
	cout << "For triangle (4, 4, 3):" << endl;
	cout << "Isosceles: " << (t.isIsosceles() ? "true" : "false") << endl;
	cout << "Equilateral: " << (t.isEquilateral() ? "true" : "false") << endl;
	return 0;
}
