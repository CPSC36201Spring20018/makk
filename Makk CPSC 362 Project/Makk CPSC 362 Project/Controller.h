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
	int keyGen;
public:
	Controller();
	~Controller();
	void Login();
	void CreateAccount();
};

#endif