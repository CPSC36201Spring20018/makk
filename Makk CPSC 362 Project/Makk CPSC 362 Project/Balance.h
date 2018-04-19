#ifndef _BALANCE_H
#define _BALANCE_H

using namespace std;

class Balance
{
private:
	double balance;

public:
	Balance();
	void updateBalance(double, char);
	double checkBalance();
};

#endif