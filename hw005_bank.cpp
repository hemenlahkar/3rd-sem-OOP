#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int serial_no = 0;
long long base_no = rand() % 10000LL * 1000000LL;

class Bank{
	string ac_holder_name, ac_no;
	double balance;
public:
	int withdraw();
	int deposit();
	void display();
	double getBalance();
	string getAcNo();
	void createAccount();
};

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

int showMenu(Bank &obj)
{
	int option;
	cout << "\nWelcome to H-Bank" << endl;
	while(1)
	{
		cout << "\n[1] Deposit\n[2] Withdraw\n[3] Check Balance\n[4] Print A/C details\n[5] Logout\n[6] Quit" << endl;
		cin >> option;
		cin.ignore();
		switch(option)
		{
			case 1:
				obj.deposit();
				break;
			case 2:
				obj.withdraw();
				break;
			case 3:
				cout << "Current balance: $" << obj.getBalance() << endl;
				break;
			case 4:
				obj.display();
				break;
			case 5:
				return 2;
			case 6:
				return 0;
			default:
				cout << "Invalid option entered. Please try again." << endl;
	
		}
	}

}

void Bank::createAccount()
{
	cout << "Enter your name: ";
	getline(cin, ac_holder_name);
	balance = 0.0;
	ac_no = to_string(base_no + ++serial_no);
	cout << "Your account has been created successfully with H-Bank." << endl;
	cout << "Your a/c no.: " << ac_no << endl;
}

int main()
{
	Bank b[10];
	int no_of_users;
	cout << "How many users are there? ";
	cin >> no_of_users;
	cin.ignore();
	for(int i = 0; i < no_of_users; i++)
		b[i].createAccount();
	string ac_no_input;
login:
	cout << "\nEnter your account no: ";
	getline(cin, ac_no_input);
	if(ac_no_input.length() < 5)
	{
		cout << "Invalid a/c no.!!" << endl;
		goto login;
	}
	int index = stoi(ac_no_input.substr(ac_no_input.length() - 4, 4)) - 1;
	if(b[index].getAcNo() == ac_no_input)
	{
		cout << "You've successfully logged in." << endl;
		if(showMenu(b[index]) == 2)
			goto login;
	}
	else
	{
		cout << "No account found!!" << endl;
		goto login;
	}
	
	return 0;
}
