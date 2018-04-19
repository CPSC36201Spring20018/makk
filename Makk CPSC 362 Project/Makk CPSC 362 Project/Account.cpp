#include "Account.h"
#include <iostream>
#include <iomanip>

Account::Account() { 
	name = "";
	accountNumber = "";
	userID = "";
	password = "";
	address = "";
	phoneNumber = "";
	balance = Balance();
	debitCards[2] = { DebitCard() };
}

Account::Account(string new_name, string new_userID, string new_password, string new_address, string new_phone_number, int new_account_num) {
	name = new_name;
	userID = new_userID;
	password = new_password;
	address = new_address;
	phoneNumber = new_phone_number;
	
	// TESTING PURPOSES
	// There is definitely a better way to do this; will cause issues
	// when deleting an account; ask Alex for explanation
	string accountNum = "MAKK";
	if (new_account_num < 10) {
		accountNum.append("000" + to_string(new_account_num + 1));
	}
	else if (new_account_num < 100) {
		accountNum.append("00" + to_string(new_account_num + 1));
	}
	else if (new_account_num < 1000) {
		accountNum.append("0" + to_string(new_account_num + 1));
	}
	else if (new_account_num < 10000) {
		accountNum.append(to_string(new_account_num + 1));
	}
	accountNumber = accountNum;

	balance = Balance();	// Set balance to 0 via constructor
}

void Account::depositFunds(double amount) {
	balance.updateBalance(amount, '1');	// 1 for deposit case
}

void Account::transferFunds(double amount) {
	balance.updateBalance(amount, '2');	// 2 for withdraw case
}

void Account::displayAccountInfo() {
	cout << "Name:  " << this->name << endl
		<< "Account Number:  " << this->accountNumber << endl
		<< "Username:  " << this->userID << endl
		<< "Password:  " << this->password << endl
		<< "Address:  " << this->address << endl
		<< "Phone number:  " << this->phoneNumber << endl
		<< "Balance:  $" << setprecision(2) << fixed << this->balance.checkBalance()
		<< endl << endl;
}

void Account::editAccount() {
	string checkPassword;
	char choice;
	char answer;

	cout << "Enter current password:  ";
	cin >> checkPassword;

	if (checkPassword == this->password) {
		while (true) {
			cout << "What would you like to do:\n"
				<< "1) Change Password\n"
				<< "2) Change Phone Number\n\n";
			cin >> choice;
			cout << endl;

			switch (choice) {
			case '1':
				cout << "Enter new password:  ";
				cin >> this->password;
				break;
			case '2':
				cout << "Enter new phone number:  ";
				cin >> this->phoneNumber;
				break;
			default:
				cout << "Invalid option\n";
			}
			cout << endl
				<< "Would you like to change anything else (Y / N):  ";
			cin >> answer;
			if (toupper(answer) != 'Y') {
				break;
			}
		}
	}
}

void Account::createDebitCard(int cardNum) {
	if (debitCards[0].doesCardExist() == false) {
		debitCards[0].setDebitCard(cardNum);
	}
	else if (debitCards[1].doesCardExist() == false) {
		debitCards[1].setDebitCard(cardNum);
	}
	else {
		cout << "Error - Debit Card Limit Exceeded\n\n";
	}
}

void Account::disableDebitCard() {
	cout << "Choose card to disable:\n\n";
	if (debitCards[0].doesCardExist() == false) {

	}
}

void Account::enableDebitCard() {
	
}


void Account::cancelDebitCard() {

}

// Getters
string Account::getName() {
	return this->name;
}

string Account::getAccountNumber() {
	return this->accountNumber;
}

string Account::getUserID() {
	return this->userID;
}

string Account::getPassword() {
	return this->password;
}

string Account::getAddress() {
	return this->address;
}

string Account::getPhoneNumber() {
	return this->phoneNumber;
}

double Account::getBalance() {
	return this->balance.checkBalance();
}

// Setters
void Account::setName(string name) {
	this->name = name;
}

void Account::setAccountNumber(string accountNumber) {
	this->accountNumber = accountNumber;
}

void Account::setUserID(string userID) {
	this->userID = userID;
}

void Account::setPassword(string password) {
	this->password = password;
}

void Account::setAddress(string address) {
	this->address = address;
}

void Account::setPhoneNumber(string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Account::setBalance(double amount) {
	this->balance.updateBalance(amount, '3');
}