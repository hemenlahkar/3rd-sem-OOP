#include <iostream>
using namespace std;

class Circle{
	float radius;
public:
	float area();
	float perimeter();
	void getData();
	void displayData();
};

float Circle::area(){
	return 3.14 * radius * radius;
}

float Circle::perimeter(){
	return 2 * 3.14 * radius;
}

void Circle::getData(){
	cout << "Enter radius of the circle: ";
	cin >> radius;
}

void Circle::displayData(){
	cout << "\nRadius: " << radius << endl;
	cout << "Area: " << area() << endl;
	cout << "Perimeter: " << perimeter() << endl;
}

int main()
{
	Circle c1;
	c1.getData();
	c1.displayData();
	return 0;
}
