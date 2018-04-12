#ifndef _ACCOUNT_H
#define _ACCOUNT_H

//#include "DebitCard.h"
//#include "Balance.h"
#include <string>
#include <list>

using namespace std;

class Account {
private:
	list<Account> accounts;

	string name;
	string account_number;
	string userID;
	string password;
	string address;
	string phone_number;

public:
	Account();	// Default Constructor
	Account(string, string, string, string, string);	// Overloaded Constructor
	~Account() { } ;	// Destructor

	bool add_account(Account);	// Add a new account
	void edit_account(Account);	// Edit an account
	void delete_account(string);	// Delete an account
	Account retrieve_account(string, string);	// Retrieve an account; for controller to find the password

	double transfer_funds(Account, string, double);
	double deposit_funds(Account, double);
	double withdraw_funds(Account, double);

	void display_all_accounts();	// Test function to make sure everything was stored correctly
};

#endif