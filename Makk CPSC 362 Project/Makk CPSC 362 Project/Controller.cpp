#include "Controller.h"

Controller::Controller() {
	// If no database, open textfile and load previous list
	ifstream accountFile;
	accountFile.open("accounts.txt");
	while (!accountFile.eof) {
		Account* loadAccount = new Account;
		accountFile >> loadAccount;
		accountList.push_back(loadAccount);
	}
	accountFile.close();
	// Else if file is empty don't do anything, empty list already exists
}

Controller::~Controller() {
	// If no database, open textfile and save current list
	ofstream accountFile;
	accountFile.open("accounts.txt");
	Account* saveAccount;
	while (accountList.size() > 0) {
		saveAccount = accountList.front();
		accountFile << saveAccount;
		accountList.pop_front();
		delete saveAccount;
	}
	// Deallocate accounts to prevent memory leaks
	for (int i = (accountList.size() - 1); i >= 0; i--) {
		Account* accountPointer = accountList.pop_back;
		delete accountPointer;
	}
}

bool Controller::Login() {
	// Hook up textbox to GUI for user input
	string userName = "";
	string userPassword = "";

	list<Account*>::iterator accountIter;
	for (accountIter = accountList.begin(); accountIter != accountList.end(); accountIter++) {
		if (userName == accountIter.getname()) {
			if (userPassword == accountIter.getPass()) {
				// "Login" - set GUI controlled account to this account object, provide call for GUI page change
			}		
		}
	}
}

bool Controller::Logout() {
	// set GUI controlled account to null, provide call fo GUI page change

}

bool Controller::CreateAccount() {
	Account* newAccount = new Account();
	if newAccount.createAccount() { // If create account was successful append account to list and return true
		accountList.push_back(newAccount);
		return true;
	} else { // Else don't append account to list and return false
		return false;
	}
}