#include <iostream>
using namespace std;

class Employee{
public:
	char name[20];
	virtual void input() = 0;
	virtual double calculateSalary() = 0;
	void display(){
		cout << "Name: " << name << endl;
		cout << "Salary: " << calculateSalary() << endl;
	}
};

class Manager : public Employee{
public:
	double fixed_salary, bonus;
	void input(){
		cout << "Enter employee name: ";
		cin.getline(name, 20);
		cout << "Enter fixed salary: ";
		cin >> fixed_salary;
		cout << "Enter bonus: ";
		cin >> bonus;
		cin.ignore();
	}
	double calculateSalary()
	{
		return fixed_salary + bonus;
	}
};

class Worker : public Employee{
public:
	double per_hour_pay, hours_worked;
	void input(){
		cout << "Enter employee name: ";
		cin.getline(name, 20);
		cout << "Enter per hour pay: ";
		cin >> per_hour_pay;
		cout << "Enter hours worked: ";
		cin >> hours_worked;
		cin.ignore();
	}
	double calculateSalary()
	{
		return per_hour_pay * hours_worked;
	}
};

int main()
{
	Manager m;
	Worker w;
	Employee *e;
	e = &m;
	e->input();
	e->display();
	e = &w;
	e->input();
	e->display();
	return 0;
}
