
#include "DebitCard.h"

// Constructor for pointers
DebitCard::DebitCard() {
	cardNumber = "nil";
	status = false;
}

// Overloaded constructor for new debit cards
DebitCard::DebitCard(int key) {
	string cardNum = "";
	if (key < 10) {
		cardNum.append("000" + to_string(key));
	}
	else if (key < 100) {
		cardNum.append("00" + to_string(key));
	}
	else if (key < 1000) {
		cardNum.append("0" + to_string(key));
	}
	else if (key < 10000) {
		cardNum.append(to_string(key));
	}
	cardNumber = cardNum;
	status = true;
}

DebitCard::DebitCard(string card_number, bool s_status) {
	cardNumber = card_number;
	status = s_status;
}

// Enable the debit card
void DebitCard::enableDebitCard() {
	if (!status) {
		status = true;
		cout << "Debit Card with number " + cardNumber + " has been enabled.";
	}
	else {
		cout << "Debit Card with number " + cardNumber + " is already enabled.";
	}
}

// Disable the debit card
void DebitCard::disableDebitCard() {
	if (status) {
		status = false;
		cout << "Debit Card with number " + cardNumber + " has been disabled";
	}
	else {
		cout << "Debit Card with number " + cardNumber + " is already disabled.";
	}
}

// Getters
string DebitCard::getDebitCardNumber() {
	return cardNumber;
}

bool DebitCard::getStatus() {
	return status;
}