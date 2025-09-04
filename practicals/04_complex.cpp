#include <iostream>
using namespace std;

class Complex{
	double real, imag;
public:
	Complex()
	{
		input();
	}
	Complex(double r)
	{
		real = r;
		imag = 0;
	}
	Complex(double r, double i)
	{
		real = r;
		imag = i;
	}
	void input()
	{
		cout << "Enter the real part: ";
		cin >> real;
		cout << "Enter the imaginary part: ";
		cin >> imag;
	}
	void display()
	{
		cout << real << " + i" << imag << endl;
	}
	double rpart()
	{
		return real;
	}
	double ipart()
	{
		return imag;
	}
	void add(Complex &c)
	{
		this->real += c.real;
		this->imag += c.imag;
	}
	void mul(Complex &c)
	{
		double r = this->real;
		this->real = this->real * c.real - this->imag * c.imag;
		this->imag = this->imag * c.real + r * c.imag;
	}
};

int main()
{
	Complex c1, c2(3, 4);
	c1.display();
	c2.display();
	c1.add(c2);
	c1.display();
	c1.mul(c2);
	c1.display();
	return 0;
}
