#include "Controller.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	Controller controller = Controller();
	bool continueProgram = true;
	
	while (continueProgram) {
		char choice;
		cout << "1. Login" << endl << "2. Create Account" << endl << "3. Quit Program" << endl;
		cout << "Enter what you would like to do: " << endl;
		cin >> choice;
		switch (choice) {
		case '1': controller.Login(); break;
		case '2': controller.CreateAccount(); break;
		case '3': continueProgram = false; break;
		default: cout << "Invalid option." << endl;
		}
	}

	return 0;
}