#include "account.hpp"

Account::Account(int id, int value) : id(id), value(value) {}

/*
** When const is used in the declaration of a member function, it specifies that this function is a "read-only".
** In other words, the function is not allowed to modify any data members of the class.
** The function getID() and getValue() is a getter, it returns the value of the private member id.
*/

int Account::getID(void) const 
{
	return (id);
}

int Account::getValue(void) const
{
	return (value);
}

/*
** The function setValue() is a setter, it sets the value of the private member value. This is used to modify the value 
** of the private member value. In this case, we use 'this' to refer to the object itself, in other words, the object
** 
*/

void Account::setValue(int value)
{
	if (value >= 0)
		this->value = value;
	else
		std::cout << "Can't set negative value" << std::endl;		
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