#include <iostream>
using namespace std;

int factorial(int);

int main()
{
	int n, result;
	cout << "Enter the number: ";
	cin >> n;
	result = factorial(n);
	if(result == -1)
	{
		cout << "Invalid input" << endl;
		return -1;
	}
	cout << n << "! = " << result << endl;
	return 0;
}

int factorial(int n)
{
	if(n < 0) return -1;
	if(n == 0 || n == 1) return 1;
	int result = 1;
	for(int i = 2; i <= n; i++)
		result *= i;
	return result;
}
