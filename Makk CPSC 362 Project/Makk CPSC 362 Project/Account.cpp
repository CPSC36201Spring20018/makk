#include "Account.h"

// Needed for pointers
Account::Account() {
	name = "";
	userID = "";
	password = "";
	address = "";
	phoneNumber = "";
	accountNumber = "";
	balance = Balance();
}

// Overloaded constructor to create new accounts
Account::Account(string validID, int key) { 
	userID = validID;
	cout << "Enter a password:" << endl;
	cin >> password;
	cout << "Enter your full name:" << endl;
	cin.ignore();
	getline(cin, name);
	cout << "Enter your full address:" << endl;
	cin.ignore();
	getline(cin, address);
	cout << "Enter your phone number:" << endl;
	cin.ignore();
	getline(cin, phoneNumber);
	string accountNum = "";
	if (key < 10) {
		accountNum.append("000" + to_string(key));
	}
	else if (key < 100) {
		accountNum.append("00" + to_string(key));
	}
	else if (key < 1000) {
		accountNum.append("0" + to_string(key));
	}
	else if (key < 10000) {
		accountNum.append(to_string(key));
	}
	accountNumber = accountNum;
	balance = Balance();
}

// Overloaded Contructor for loading past accounts
Account::Account(string load_name, string load_userID, string load_password, string load_address, string load_phone_number, string load_account_num, list<DebitCard*> load_card_list, double load_balance) {
	name = load_name;
	userID = load_userID;
	password = load_password;
	address = load_address;
	phoneNumber = load_phone_number;
	accountNumber = load_account_num;
	debitCardList = load_card_list;
	balance = Balance(load_balance);
}

Account::~Account() {
	// ADD DELETE BALANCE AND DEBITCARD OBJECTS CODE HERE
}

// Displays info about account
void Account::displayAccountInfo() {
	cout << endl << "Name:  " << this->name << endl
		<< "Username:  " << this->userID << endl
		<< "Password:  " << this->password << endl
		<< "Address:  " << this->address << endl
		<< "Phone number:  " << this->phoneNumber << endl
		<< endl << endl;
}

// Displays welcome info when logged in
void Account::displayWelcomeInfo() {
	cout << endl << endl << "Welcome " << this->name << endl << "Your current balance is: $"
		<< setprecision(2) << fixed << this->balance.getBalance() << endl << endl;
}

// Edit Account Info
void Account::editAccount() {
	string checkPassword;
	char choice;
	char answer;

	cout << "Enter current password:  ";
	cin >> checkPassword;

	if (checkPassword == this->password) {
		while (true) {
			cout << "What would you like to do:\n"
				<< "1: Change Password\n"
				<< "2: Change Phone Number\n"
				<< "3: Cancel editing" << endl;
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
			case '3':
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

// Transfer funds between accounts
double Account::transferFunds() {
	string amount;
	cout << "Enter the amount you want to deposit: " << endl;
	cin >> amount;
	if (atof(amount.c_str()) <= balance.getBalance()) {
		balance.updateBalance(atof(amount.c_str()), '2');	// 2 for withdraw case
	} else {
		amount = "0";
		cout << "Not enough funds in your account to complete transfer.";
	}
	return atof(amount.c_str());
}

// Deposit from external source
void Account::depositFunds() {
	string creditCard;
	string amount;
	cout << "Enter a valid credit card: " << endl;
	cin >> creditCard;
	cout << "Enter the amount you want to deposit: " << endl;
	cin >> amount;
	balance.updateBalance(atof(amount.c_str()), '1');	// 1 for deposit case
}

// Deposit during a transfer
void Account::depositFunds(double amount) {
	balance.updateBalance(amount, '1');
}

// Manages calls to other debit card functions
int Account::manageDebitCards(int key) {
	if (debitCardList.size() > 0) {
		cout << "These are your current Debit Cards: " << endl;
		for (auto const& dCIter : debitCardList) {
			cout << dCIter->getDebitCardNumber() << endl;
		}	
	}
	char userChoice;
	cout << "1: Create Debit Card" << endl
		<< "2: Disable Debit Card" << endl
		<< "3: Enable Debit Card" << endl
		<< "4: Back to Account" << endl;
	cin >> userChoice;
	string checkCardNum;
	switch (userChoice) {
	case '1': key = createDebitCard(key); break;
	case '2':
		cout << "Enter the card number you want to disable: ";
		cin >> checkCardNum;
		for (auto const& dCIter : debitCardList) {
			if (checkCardNum == dCIter->getDebitCardNumber()) {
				dCIter->disableDebitCard();
			}
		}
		break;
	case '3': 
		cout << "Enter the card number you want to enable: ";
		cin >> checkCardNum;
		for (auto const& dCIter : debitCardList) {
			if (checkCardNum == dCIter->getDebitCardNumber()) {
				dCIter->enableDebitCard();
			}
		}
		break;
	case '4': break;
	default: cout << "Unknown choice" << endl; break;
	}
	return key;
}

// Creates a new debit card
int Account::createDebitCard(int key) {
	if (debitCardList.size() < 2) {
		DebitCard* newDebitCard = new DebitCard(key);
		debitCardList.push_back(newDebitCard);
		key++;
	}
	else {
		cout << "Error - Debit Card Limit Exceeded; Account Already Has Two Debit Cards.\n\n";
	}
	return key;
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

list<DebitCard*> Account::getDebitCardList() {
	return this->debitCardList;
}

double Account::getBalance() {
	return balance.getBalance();
}