#include "Balance.h"

//creates initial balance when account is created
Balance::Balance() 
{
	balance = 0.0;
}

//this function will withdraw or deposit
void Balance::updateBalance(double amount, char option) 
{
	if (option == '1') 
	{
		balance += amount;
	}
	else if (option == '2')
	{
		balance -= amount;
	}
	else if (option == '3')
	{
		balance = amount;
	}
}

//this function returns the current balance of the account
double Balance::checkBalance() 
{
	return balance;
}
