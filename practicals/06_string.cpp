#include <iostream>
using namespace std;

class String{
public:
	char *p;
	int size;
	String()
	{
		p = nullptr;
		size = 0;
	}
	String(const char *str)
	{
		int length;
		for(length = 0; str[length] != 0; length++);
		size = length;
		p = new char[size + 1];
		for(int i = 0; i <= length; i++)
			p[i] = str[i];
	}
	~String()
	{
		delete p;
	}
	int length()
	{
		return size;
	}
	void display()
	{
		for(int i = 0; i < size; i++)
			cout << p[i];
		cout << endl;
	}
	friend int compare(String &s1, String &s2)
	{
		int i;
		for(i = 0; s1.p[i] != 0 && s2.p[i] != 0; i++)
		{
			if(s1.p[i] > s2.p[i]) return 1;
			if(s1.p[i] < s2.p[i]) return -1;
		}
		if(s1.p[i] == 0 && s2.p[i] != 0) return -1;
		if(s2.p[i] == 0 && s1.p[i] != 0) return 1;
		return 0;
	}
	int copy(String &s2)
	{
		this->size = s2.length();
		this->p = new char[this->size + 1];
		if(this->p == nullptr)
		{
			cout << "Insufficient memory" << endl;
			return 0;
		}
		for(int i = 0; i <= this->size; i++)
			this->p[i] = s2.p[i];
		return 1;
	}
	void reverse()
	{
		for(int i = 0; i < size/2; i++)
		{
			char temp = p[i];
			p[i] = p[size - i - 1];
			p[size - i - 1] = temp;
		}
	}
	
};

int main()
{
	String s1("Hello"), s2("World");
	s1.display();
	s2.display();
	s1.reverse();
	s1.display();
	cout << "Comparision of s1 and s2: " << compare(s1, s2) << endl;
	String s3;
	s3.copy(s1);
	s1.display();
	s2.display();
	s3.display();
	return 0;
}
