#ifndef _BALANCE_H
#define _BALANCE_H

using namespace std;

class Balance
{
private:
	double balance;

public:
	Balance();
	Balance(double);
	void updateBalance(double, char);
	double getBalance();

//	friend ostream& operator<<(ostream& os, const Balance& b) {
//		os << b.balance << endl;
//		return os;
//	}
};

#endif