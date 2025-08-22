#include <iostream>
using namespace std;

class Employee {
	int empno;
	char ename[20];
	float basic, hra, da;
public:
	float calculate();
	void getdata();
	void dispdata();
};

float Employee::calculate()
{
	return basic * (1 + hra + da);
}

void Employee::getdata()
{
	cout << "Enter employee no.: ";
	cin >> empno;
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Enter employee name: ";
	cin.getline(ename, 20);
	cout << "Enter basic salary: ";
	cin >> basic;
	cout << "Enter HRA and DA respectively(in %): ";
	cin >> hra >> da;
	hra /= 100;
	da /= 100;
}

void Employee::dispdata()
{
	cout << "\nName: " << ename << endl;
	cout << "Employee no.: " << empno << endl;
	cout << "Basic pay: " << basic << endl;
	cout << "Net pay: " << calculate() << endl;
}

int main()
{
	Employee e1;
	e1.getdata();
	e1.dispdata();

	return 0;
}
