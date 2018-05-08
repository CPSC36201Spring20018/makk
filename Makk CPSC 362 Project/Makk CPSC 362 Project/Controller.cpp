#include "Controller.h"

Controller::Controller() {
	// Open textfile and load previous list

	ifstream accountFile;
	if (ifstream("accounts.txt")) {
		accountFile.open("accounts.txt");
		accountFile >> keyGen;
			while (!accountFile.eof()) {
				string name;
				string accountNo;
				string id;
				string password;
				string address;
				string phone;
				int numOfCards;
				string cardNum;
				bool cardStat;
				double balance;
				list<DebitCard*> cardList;
				accountFile.ignore();
				getline(accountFile, name);
				accountFile >> accountNo >> id >> password;
				accountFile.ignore();
				getline(accountFile, address);
				accountFile >> phone >> numOfCards;
				for (int i = 0; i < numOfCards; i++) {
					accountFile >> cardNum >> cardStat;
					DebitCard* card = new DebitCard(cardNum, cardStat);
					cardList.push_back(card);
				}
				accountFile >> balance;
				Account* loadAccount = new Account(name, id, password, address, phone, accountNo, cardList, balance);
				accountList.push_back(loadAccount);
			}
		accountFile.close();
	} else {
		keyGen = 1;
	}

//	keyGen = 0;
	// Else; file is empty don't do anything, empty list already exists
}

// Save account data and delete pointers
Controller::~Controller() {
	ofstream accountFile;
	accountFile.open("accounts.txt");
	Account* saveAccount;
	accountFile << keyGen << endl;
	while (accountList.size() > 0) {
		saveAccount = accountList.front();
		accountFile << saveAccount->getName() << endl << saveAccount->getAccountNumber() << endl
			<< saveAccount->getUserID() << endl << saveAccount->getPassword() << endl
			<< saveAccount->getAddress() << endl << saveAccount->getPhoneNumber() << endl;
		list<DebitCard*> outList = saveAccount->getDebitCardList();
		accountFile << outList.size() << endl;
		int loopArray = outList.size();
		for (int i = 0; i < loopArray; i++) {
			DebitCard* printCard = outList.front();
			outList.pop_front();
			accountFile << printCard->getDebitCardNumber() << endl << printCard->getStatus() << endl;
			delete printCard;
		}
		accountFile << saveAccount->getBalance();
		if (accountList.size() != 1) {
			accountFile << endl;
		}
		accountList.pop_front();
		delete saveAccount;
	}
	accountFile.close();
}

// User logs into account and accesses account
void Controller::Login() {
	string userName;
	string userPassword;
	bool logOut = false;
	bool nameNotFound;
	bool passNotFound;
	Account* accountLoggedIn;
	cout << "Enter your user ID: " << endl;
	cin >> userName;
	cout << "Enter your password: " << endl;
	cin >> userPassword;
	if (accountList.size() > 0) {
		for (auto const& accountIter : accountList) {
			if (userName == accountIter->getUserID()) {
				nameNotFound = false;
				if (userPassword == accountIter->getPassword()) {
					passNotFound = false;
					accountLoggedIn = accountIter;
					while (!logOut) {
						char userChoice;
						accountLoggedIn->displayWelcomeInfo();
						cout << "1: Display Account Information" << endl
							<< "2: Edit Account Information" << endl
							<< "3: Deposit Funds Into Account" << endl
							<< "4: Transfer Funds" << endl
							<< "5: Manage Debit Cards" << endl
							<< "6: Logout" << endl;
						cin >> userChoice;
						string transferUserId;
						double transferBalance;
						bool transfered = false;
						switch (userChoice) {
						case '1': accountLoggedIn->displayAccountInfo(); break;
						case '2': accountLoggedIn->editAccount(); break;
						case '3': accountLoggedIn->depositFunds(); break;
						case '4': 
							cout << "Enter the userID of the person you want to transfer funds to: " << endl;
							cin >> transferUserId;
							transferBalance = accountLoggedIn->transferFunds(); 
							for (auto const& iter : accountList) {
								if (transferUserId == iter->getUserID()) {
									iter->depositFunds(transferBalance);
									transfered = true;
								}
							}
							if (!transfered) {
								accountLoggedIn->depositFunds(transferBalance);
								cout << "Transfer failed, recipient not found." << endl;
							}
							break;
						case '5': keyGen = accountLoggedIn->manageDebitCards(keyGen); break;
						case '6': logOut = true; break;
						default: cout << "Unknown Choice" << endl; break;
						}
					}
				} else {
					passNotFound = true;
				}
			} else {
				nameNotFound = true;
			}
		}
		if (nameNotFound) {
			cout << "Username not found in system." << endl << endl;
		} else if (passNotFound) {
			cout << "Incorrect password entered." << endl << endl;
		}
	} else {
		cout << endl << "Error: No accounts in system." << endl << endl;
	}
}

// Create a new account
void Controller::CreateAccount() {
	bool nameTaken = false;
	string id;
	cout << "Enter a user ID:" << endl;
	do {
		nameTaken = false;
		cin.ignore();
		getline(cin, id);
		for (auto const& iter : accountList) {
			if (id == iter->getUserID()) {
				cout << "That user ID has already been taken. Please enter a new one: " << endl;
				nameTaken = true;
			}
		}
	} while (nameTaken);
	Account* newAccount = new Account(id, keyGen);
	accountList.push_back(newAccount);
	keyGen++;
}