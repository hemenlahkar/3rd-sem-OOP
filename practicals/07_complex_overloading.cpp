#include <iostream>
using namespace std;

class Complex{
	double real, imag;
public:
	Complex()
	{
		real = imag = 0;
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
	Complex operator + (Complex &c)
	{
		Complex sum;
		sum.real = this->real + c.real;
		sum.imag = this->imag + c.imag;
		return sum;
	}
	Complex operator * (Complex &c)
	{
		Complex result;
		result.real = this->real * c.real - this->imag * c.imag;
		result.imag = this->imag * c.real + this->real * c.imag;
		return result;
	}
	friend ostream& operator<<(ostream &output, Complex &c)
	{
		if(c.imag < 0)
			output << c.real << c.imag << "i";
		else
			output << c.real << "+" << c.imag << "i";
		return output;
	}
	friend istream& operator>>(istream &input, Complex &c)
	{
		char a;
		input >> c.real;
		input >> a;
		input >> c.imag;
		input.ignore();
		if(a == '-') c.imag = -c.imag;
		return input;
	}

};

int main()
{
	Complex c1, c2, c3;
	int op;
	cout << "Enter the two complex numbers in the form \'a+bi\':";
	cin >> c1 >> c2;
	cout << "You've entered: " << c1 << "  " << c2 << endl;
	cout << "\n1. Addition\n2. Multiplication" << endl;
	cout << "Enter the operation you want to perform: ";
	cin >> op;
	switch(op)
	{
		case 1:
			c3 = c1 + c2;
			cout << c3 << endl;
			break;
		case 2:
			c3 = c1 * c2;
			cout << c3 << endl;
			break;
		default:
			cout << "Invalid operator received!" << endl;
			break;
	}

	return 0;
}
