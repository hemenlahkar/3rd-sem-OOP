#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Bank{
	string ac_holder_name, ac_no;
	double balance;
	long long base_no = rand() % 10000LL * 1000000LL, serial_no = 0;
public:
	Bank();
	int withdraw();
	int deposit();
	void display();
	double getBalance();
	string getAcNo();
};

Bank::Bank()
{
	cout << "Enter your name: ";
	getline(cin, ac_holder_name);
	balance = 0.0;
	ac_no = to_string(base_no + ++serial_no);
	cout << "Your account has been created with H-Bank." << endl;
	cout << "Your a/c no.: " << ac_no << endl;
}

int Bank::withdraw()
{
	double amount;
	cout << "Enter amount to be withdrawed: ";
	cin >> amount;
	if(amount < 0 || amount > balance)
	{
		cout << "Invalid amount entered!!" << endl;
		return 0;
	}
	balance -= amount;
	cout << "\nYour a/c XXXX" << ac_no.substr(ac_no.length() - 4, 4) << " has been debited with $" << amount << endl;
	return 1;
}

int Bank::deposit()
{
	double amount;
	cout << "Enter amount to be deposited: ";
	cin >> amount;
	if(amount <= 0)
	{
		cout << "Invalid amount entered!" << endl;
		return 0;
	}
	if(amount > 50000)
	{
		cout << "Cannot deposit more than $50000 at once." << endl;
		return 0;
	}
	balance += amount;
	cout << "\nYour a/c XXXX" << ac_no.substr(ac_no.length() - 4, 4) << " has been credited with $" << amount << endl;
	return 1;
}

void Bank::display()
{
	cout << "A/C holder name: " << ac_holder_name << endl;
	cout << "A/C no.: " << ac_no << endl;
	cout << "Balance: $" << balance << endl;
}

double Bank::getBalance()
{
	return balance;
}

string Bank::getAcNo()
{
	return ac_no;
}

void showMenu(Bank &obj)
{
	int option;
	cout << "\nWelcome to H-Bank" << endl;
	while(1)
	{
		cout << "\n[1] Desosit\n[2] Withdraw\n[3] Check Balance\n[4] Print A/C details\n[5] quit" << endl;
		cin >> option;
		switch(option)
		{
			case 1:
				obj.deposit();
				break;
			case 2:
				obj.withdraw();
				break;
			case 3:
				cout << "Current balance: " << obj.getBalance() << endl;
				break;
			case 4:
				obj.display();
				break;
			case 5:
				return;
			default:
				cout << "Invalid option entered. Please try again." << endl;
	
		}
	}

}

int main()
{
	Bank b;
	showMenu(b);
	return 0;
}
