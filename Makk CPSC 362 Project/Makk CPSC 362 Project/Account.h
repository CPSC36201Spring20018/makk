#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include "DebitCard.h"
#include "Balance.h"
#include <string>
#include <list>
#include <iostream>
#include <iomanip>

using namespace std;

class Account {
private:
	Balance balance;
	list <DebitCard*> debitCardList;
	string name;
	string accountNumber;
	string userID;
	string password;
	string address;
	string phoneNumber;

public:
	Account();
	Account(int);
	Account(string, string, string, string, string, string, list<DebitCard*>, double);
	~Account();
	void displayAccountInfo();
	void displayWelcomeInfo();
	void editAccount();
	double transferFunds();
	void depositFunds();
	void depositFunds(double);
	int manageDebitCards(int);
	int createDebitCard(int);
	string getName();
	string getAccountNumber();
	string getUserID();
	string getPassword();
	string getAddress();
	string getPhoneNumber();
	list<DebitCard*> getDebitCardList();
	double getBalance();


//	friend ostream& operator<<(ostream& os, const Account& a) {
//		os << a.name << endl << a.accountNumber << endl << a.userID << endl << a.password << endl
//			<< a.address << endl << a.phoneNumber << endl;
//		os << a.debitCardList.size() << endl;
//		for (int i = 0; i < a.debitCardList.size(); i++) {
//			DebitCard* tempCard = a.debitCardList.front();
//			a.debitCardList.pop_front();
//			os << tempCard;
//		}
//		os << a.balance;
//		return os;
//	}

	// Extraction operator
//	friend istream& operator>>(istream& is, Account& a)
//	{
		// read in individual members of s
//		is
//		return is;
//	}

};

#endif