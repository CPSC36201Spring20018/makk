#ifndef _DEBITCARD_H
#define _DEBITCARD_H

#include <iostream>
#include <string>

using namespace std;

class DebitCard {
private:
	string cardNumber;
	bool status;
public:
	DebitCard();
	DebitCard(int);
	DebitCard(string, bool);
	void disableDebitCard();
	void enableDebitCard();
	string getDebitCardNumber();
	bool getStatus();

//	friend ostream& operator<<(ostream& os, const DebitCard& d) {
//		os << d.cardNumber << endl << d.status << endl;
//		return os;
//	}
};

#endif