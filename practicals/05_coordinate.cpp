#include <iostream>
#include<cmath>
using namespace std;

class Point{
	double xordinate, yordinate;
public:
	Point()
	{
		input();
	}
	Point(double x)
	{
		xordinate = x;
	}
	Point(double x, double y)
	{
		xordinate = x;
		yordinate = y;
	}
	void input()
	{
		cout << "Enter x-coordinate: ";
		cin >> xordinate;
		cout << "Enter y-coordinate: ";
		cin >> yordinate;
	}
	void display()
	{
		cout << "(" << xordinate << ", " << yordinate << ")" << endl;
	}
	double dist()
	{
		return hypot(xordinate, yordinate);
	}
	double slope()
	{
		return yordinate / xordinate;
	}
	friend double distance(Point &p1, Point &p2)
	{
		return hypot(p1.xordinate - p2.xordinate, p1.yordinate - p2.yordinate);
	}
};

int main()
{
	Point p1, p2(3, 4);
	p1.display();
	p2.display();
	cout << "Distance of p1 from origin: " << p1.dist() << endl;
	cout << "Distance of p2 from origin: " << p2.dist() << endl;
	cout << "Slope of p1: " << p1.slope() << endl;
	cout << "Slope of p2: " << p2.slope() << endl;
	cout << "Distance between p1 and p2: " << distance(p1, p2) << endl;
	return 0;
}
