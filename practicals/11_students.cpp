#include <iostream>
using namespace std;

class Students{
public:
	int roll_no;
	char sname[20];
};

class Artst : public Students{
public:
	int ph, hs, en, as;
	int ctotal()
	{
		return ph + hs + en + as;
	}
	void takeData()
	{
		cout << "Enter student's name: ";
		cin.getline(sname, 20);
		cout << "Enter roll no.: ";
		cin >> roll_no;
		cout << "Enter marks obtained in Philosophy, History, English and Assamese respectively: ";
		cin >> ph >> hs >> en >> as;
		cin.ignore();
	}
	void showData()
	{
		cout << "\nName\t\t: " << sname << endl;
		cout << "Roll no.\t: " << roll_no << endl;
		cout << "Marksheet:: " << endl;
		cout << "\tPhilosophy\t: " << ph << endl;
		cout << "\tHistory  \t: " << hs << endl;
		cout << "\tEnglish  \t: " << en << endl;
		cout << "\tAssamese \t: " << as << endl;
		cout << "Total Marks: " << ctotal() << endl;
	}
};

class Scst : public Students{
public:
	int sph, ch, ma, en;
	int ctotal()
	{
		return sph + ch + en + ma;
	}
	void takeData()
	{
		cout << "Enter student's name: ";
		cin.getline(sname, 20);
		cout << "Enter roll no.: ";
		cin >> roll_no;
		cout << "Enter marks obtained in Physics, Chemistry, Mathematics and English respectively: ";
		cin >> sph >> ch >> ma >> en;
		cin.ignore();
	}
	void showData()
	{
		cout << "\nName\t\t: " << sname << endl;
		cout << "Roll no.\t: " << roll_no << endl;
		cout << "Marksheet:: " << endl;
		cout << "\tPhysics\t\t: " << sph << endl;
		cout << "\tChemistry\t: " << ch << endl;
		cout << "\tMathematics\t: " << ma << endl;
		cout << "\tEnglish  \t: " << en << endl;
		cout << "Total Marks: " << ctotal() << endl;
	}	
};

int main()
{
	Artst s1;
	Scst s2;
	s1.takeData();
	s2.takeData();
	s1.showData();
	s2.showData();
	return 0;
}

