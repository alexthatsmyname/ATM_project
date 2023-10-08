#include <iostream>
#include <cstdlib>

using namespace std;

class pin {
private:
	int pinCode;
public:
	void setPinFromUser() {
		cout << "Set your PIN: ";
		cin >> pinCode;
	}
	int getPinFromUser() {
		int enteredPin;
		cout << "Enter your PIN: ";
		cin >> enteredPin;
		return enteredPin;
	}
	int getPinCode() {
		return pinCode;
	}
};

string selectCurrency() {
	int option;
	string currency = "0";
	do
	{
		cout << "1. RON" << endl;
		cout << "2. EUR" << endl;
		cout << "3. USD" << endl;
		cout << "4. HUF" << endl;
		cout << "Enter your Option: ";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "You've selected the Romanian Leu.";
			currency = "RON";
			break;
		case 2:
			cout << "You've selected the Euro.";
			currency = "EUR";
			break;
		case 3:
			cout << "You've selected the American Dollar.";
			currency = "USD";
			break;
		case 4:
			cout << "You've selected the Hungarian Forint.";
			currency = "HUF";
			break;
		default:
			cout << "Invalid option. Please try again." << endl;
		}
	} while (currency == "0");
	return currency;
}

int depositMoney(string currency) {
	int sum;
	cout << "Please enter the amount you want to deposit in " << currency << ":";
	cin >> sum;
	return sum;
}

int withdrawMoney(string currency, int balance) {
	int withdraw;
	cout << "Please enter the amount you want to withdra in" << currency << ":";
	cin >> withdraw;
	if (withdraw > balance)
	{
		cout << "The withdraw exceeds the balance.";
		return 0;
	}
	else
		return withdraw;
}

void switchCurrency(float balance) {
	int ok = 1;
	int option;
	do {
		cout << "1. Switch to EUR." << endl;
		cout << "2. Switch to USD." << endl;
		cout << "3. Switch to HUF." << endl;
		cout << "Enter your option: ";
		cin >> option;
		switch (option)
		{
		case 1:
			balance = balance / 4.96f;
			cout << "Your balance in EUR is: " << balance;
			ok = 0;
			break;
		case 2:
			balance = balance / 4.70f;
			cout << "Your balance in USD is: " << balance;
			ok = 0;
			break;
		case 3:
			balance = balance / 0.012f;
			cout << "Your balance in HUF is: " << balance;
			ok = 0;
			break;
		default:
			cout << "Option is invalid. Please try again!" << endl;
		}
	} while (ok == 1);
}

int main()
{
	pin userPinCode;
	userPinCode.setPinFromUser();
	float balance = 0;
	float withdraw, deposit;
	int option;
	string currency;
	const int maxAttempts = 3;
	int attempts = 0;
	int enterPin = userPinCode.getPinFromUser();
	do
	{
		if (enterPin == userPinCode.getPinCode())
		{
			cout << " PIN accepted. Welcome!" << endl;
			cout << "-------------------" << endl;
			cout << "    ATM Machine    " << endl;
			cout << "-------------------" << endl;
			cout << "0. Select currency." << endl;
			cout << "1. Deposit money." << endl;
			cout << "2. Withdraw money." << endl;
			cout << "3. Check balance." << endl;
			cout << "4. Switch currency." << endl;
			cout << "5. Exit." << endl;
			cout << "Enter your option: ";
			cin >> option;
			switch (option)
			{
			case 0:
				currency = selectCurrency();
				break;
			case 1:
				deposit = depositMoney(currency);
				cout << "You have deposited " << deposit << " " << currency << "!" << endl;
				balance = balance + deposit;
				break;
			case 2:
				withdraw = withdrawMoney(currency, balance);
				cout << "You have withdrawed " << withdraw << " " << currency << "!" << endl;
				balance = balance - withdraw;
				break;
			case 3:
				cout << "Your balance is: " << balance << " " << currency << "!" << endl;
				break;
			case 4:
				switchCurrency(balance);
				break;
			case 5:
				exit(0);
				break;
			default:
				cout << "Invalid option. Please try again." << endl;
			}
		}
		else
		{
			attempts++;
			if (attempts == maxAttempts)
			{
				cout << "Maximum attempts reached. Card is blocked!";
				exit(0);
			}
		}
	} while (1);

	return 0;
}