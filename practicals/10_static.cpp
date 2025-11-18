#include <iostream>
#include <cstring>

using namespace std;

class Student{
	static int count;
	int roll_no;
	char name[20];
public:
	Student()
	{
		count++;
		roll_no = -1;
	}
	Student(const char *str, int roll)
	{
		count++;
		roll_no = roll;
		strcpy(name, str);
	}
	void input()
	{
		cout << "Enter the name of the student: ";
		cin.getline(name, 20);
		cout << "Enter the roll no.: ";
		cin >> roll_no;
		cin.ignore();
	}
	void output()
	{
		cout << "\nName: " << name << endl;
		cout << "Roll no.: " << roll_no << endl;
		cout << "Total no. of students = " << count << endl;
	}
};

int Student::count = 0;

int main()
{
	Student s1, s2, s3("Hemen", 6);
	s1.input();
	s2.input();
	s1.output();
	s2.output();
	s3.output();
	return 0;
}

