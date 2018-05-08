#include "Balance.h"

// Creates initial balance when account is created
Balance::Balance() 
{
	balance = 0.0;
}

// Overloaded constructor for previous balances
Balance::Balance(double load_balance) {
	balance = load_balance;
}

// Withdraw or deposit funds into balance
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

// Returns the current balance of the account
double Balance::getBalance() 
{
	return balance;
}
