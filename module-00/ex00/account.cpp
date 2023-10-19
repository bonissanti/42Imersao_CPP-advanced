#include "account.hpp"

Account::Account(int id, int value) : id(id), value(value) {}

int Account::getID(void) const 
{
	return (id);
}

int Account::getValue(void) const
{
	return (value);
}

void Account::setValue(int value)
{
	if (value >= 0)
		this->value = value;
	else
		std::cout << "*** Can't set negative value ***" << std::endl;		
}


void Account::receiveValue(int value)
{
	this->value += value;
}

int Account::getBalance(void) const
{
	return (value);
}

void Account::printAccountDetails()
{
	std::cout << "Account ID: " << id << std::endl;
	std::cout << "Account value: " << value << std::endl;
}