#include "Account.h"
#include <iostream>

Account::Account() { 
	name = "";
	account_number = "";
	userID = "";
	password = "";
	address = "";
	phone_number = "";
}

Account::Account(string new_name, string new_userID, string new_password, string new_address, string new_phone_number) {
	name = new_name;
	userID = new_userID;
	password = new_password;
	address = new_address;
	phone_number = new_phone_number;
}

bool Account::add_account(Account account) {
	list<Account>::iterator it;
	Account check_accounts;

	for (it = accounts.begin(); it != accounts.end(); it++) {
		check_accounts = *it;

		if (check_accounts.userID == account.userID) {
			return false;	// Returns false if the username to be created already exists
		}
	}

	account.account_number = "MAKK";

	if (accounts.size() < 9) {
		account.account_number.append("000" + to_string(accounts.size() + 1));
	}
	else if (accounts.size() < 99) {
		account.account_number.append("00" + to_string(accounts.size() + 1));
	}
	else if (accounts.size() < 999) {
		account.account_number.append("0" + to_string(accounts.size() + 1));
	}
	else if (accounts.size() < 9999) {
		account.account_number.append(to_string(accounts.size() + 1));
	}

	accounts.push_back(account);

	return true;	// Returns true if username is unique and adds a new account to the list of accounts
}

void Account::edit_account(Account account) {	// Needs work; implemented this style to make sure it worked
	list<Account>::iterator delete_it;
	Account replace_account;
	int choice;

	cout << "What would you like to change: \n"
		<< "1) Account holder's name\n"
		<< "2) Username\n"
		<< "3) Password\n"
		<< "4) Address\n"
		<< "5) Phone Number\n";
	cin >> choice;

	switch (choice) {
	case 1:
		cout << "Name:  ";
		cin >> account.name;
		break;
	case 2:
		cout << "Username:  ";
		cin >> account.userID;
		break;
	case 3:
		cout << "Password:  ";
		cin >> account.password;
		break;
	case 4:
		cout << "Address:  ";
		cin >> account.address;
		break;
	case 5:
		cout << "Phone Number:  ";
		cin >> account.phone_number;
		break;
	default:
		cout << "Invalid Option\n";
	}

	for (list<Account>::iterator it = accounts.begin(); it != accounts.end(); it++) {
		replace_account = *it;

		if (replace_account.account_number == account.account_number) {
			delete_it = it;
			accounts.erase(delete_it);
			accounts.push_back(account);
			break;
		}
	}

	cout << endl << account.name << endl << account.userID << endl << account.password << endl << account.address << endl << account.phone_number << endl << endl;
}

void Account::delete_account(string username) {
	list<Account>::iterator delete_it;
	Account account_to_delete;
	string re_pw;

	cout << "Re-enter password:  ";
	cin >> re_pw;

	for (list<Account>::iterator it = accounts.begin(); it != accounts.end(); it++) {
		account_to_delete = *it;

		if ((account_to_delete.userID == username) && (account_to_delete.password == re_pw)) {
			cout << "Account has been deleted.\n\n";
			delete_it = it;
			accounts.erase(delete_it);
			break;
		}
		else if ((account_to_delete.userID == username) && (account_to_delete.password != re_pw)) {
			cout << "Incorrect password.\n\n";
			break;
		}
	}

	if (account_to_delete.userID != username) {
		cout << "Username was not found - could not delete the specified account.\n\n";
	}
}

Account Account::retrieve_account(string username, string password) {
	list<Account>::iterator it;
	bool exists = false;
	Account account;
	Account empty_account;

	for (it = accounts.begin(); it != accounts.end(); it++) {
		account = *it;

		if ((account.userID == username) && (account.password == password)) {
			return account;
		}
		else if ((account.userID == username) && (account.password != password)) {
			exists = true;
			break;
		}
	}

	if (exists) {
		cout << "Password for " + account.userID << " is incorrect.\n";
	}
	else {
		cout << "Account not found.\n";
	}

	return empty_account;	// This returns an actual account - Make a conditional check to see if this userID is the same as the one you typed
							// If it isn't, just reiterate the conditional statement to check the list again. "if (account.userID == name)"
}

/*
double Account::transfer_funds(Account current_account, string to_username, double amount) {
	list<Account>::iterator it;
	// Balance balance;
	Account check_account;

	for (it = accounts.begin(); it != accounts.end(); it++) {
		check_account = *it;

		if (check_account.userID == to_username) {
			// balance.update_balance(amount, 1, current_account.userID);	// 1 is withdraw
			// balance.update_balance(amount, 2, to_username);				// 2 is deposit
			break;
		}
	}

	// return balance.get_balance(current_account.userID);
}

double Account::deposit_funds(Account account, double amount) {
	// Balance balance;

	// balance.updateBalance(2, account.userID, amount);

	// return balance.getBalance(account.userID);
}

double Account::withdraw_funds(Account account, double amount) {
	// Balance balance;

	// balance.updateBalance(1, account.userID, amount);

	// return balance.getBalance(account.userID);
}
*/

void Account::display_all_accounts() {
	list<Account>::iterator it;
	Account output_account;

	for (it = accounts.begin(); it != accounts.end(); it++) {
		output_account = *it;
		cout << "Account holder's name:  " << output_account.name << endl
			<< "Account number:  " << output_account.account_number << endl
			<< "Username:  " << output_account.userID << endl
			<< "Password:  " << output_account.password << endl
			<< "Address:  " << output_account.address << endl
			<< "Phone number:  " << output_account.phone_number << endl << endl;
	}
}