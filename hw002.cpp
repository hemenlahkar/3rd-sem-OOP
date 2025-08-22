#include <iostream>
using namespace std;
int is_palindrome(string);
int main()
{
	string str;
	cout << "Enter the string: ";
	getline(cin, str);
	if(is_palindrome(str))
		cout << "Given string is a palindrome." << endl;
	else
		cout << "Given string is not a palindrome." << endl;
	return 0;
}

int is_palindrome(string str)
{
	int length = str.size();
	for(int i = 0; i < length/2; i++)
		if(str[i] != str[length - i -1])
			return 0;
	return 1;

}
