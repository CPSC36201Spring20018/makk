#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "Account.h"
#include <list>
#include <string>
#include <fstream>

using namespace std;

class Controller {
private:
	list <Account*> accountList;
public:
	Controller();
	~Controller();
	bool Login();
	bool Logout();
	bool CreateAccount();
};

#endif