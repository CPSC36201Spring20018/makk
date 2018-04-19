#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include "DebitCard.h"
#include "Balance.h"
#include <string>
#include <list>

using namespace std;

class Account {
private:
	Balance balance;
	DebitCard debitCards[2];
	string name;
	string accountNumber;
	string userID;
	string password;
	string address;
	string phoneNumber;

public:
	Account();	// Default Constructor
	Account(string, string, string, string, string, int);	// Overloaded Constructor
	~Account() { } ;	// Destructor

	// Account information
	void displayAccountInfo();
	void editAccount();
//	void deleteAccount(string);		Most likely will delete this function

	// Balance
	void transferFunds(double);
	void depositFunds(double);

	// Debit 
	void createDebitCard(int);
	void disableDebitCard();
	void enableDebitCard();
	void cancelDebitCard();

	// Getters
	string getName();
	string getAccountNumber();
	string getUserID();
	string getPassword();
	string getAddress();
	string getPhoneNumber();
	double getBalance();
//	string getCard();

	// Setters
	void setName(string);
	void setAccountNumber(string);
	void setUserID(string);
	void setPassword(string);
	void setAddress(string);
	void setPhoneNumber(string);
	void setBalance(double);
//	void setCard(string);
};

#endif