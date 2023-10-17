#include "bank.hpp"

void Bank::createAccount(int id, int value)
{
	std::size_t i = 0;
	if ((value < 0) || (value < -2147483648 && value > 2147483647))
	{
		std::cout << "Invalid value" << std::endl;
		return ;
	}
	while (i < clientAccounts.size())
	{
		if (clientAccounts[i]->getID() == id)
		{
			std::cout << "Account already exists" << std::endl;
			return ;
		}
		i++;
	}
	int fee = value * 0.05;
	liquidity += fee;
	clientAccounts.push_back(new Account(id, value - fee));
}

void Bank::deleteAccount(int id)
{
	std::size_t i = 0;
	while (i < clientAccounts.size())
	{
		if (clientAccounts[i]->getID() == id)
		{
			delete clientAccounts[i];
			clientAccounts.erase(clientAccounts.begin() + i);
			return ;
		}
		i++;
	}
	std::cout << "*** Account not found ***" << std::endl;
}

void Bank::modifyAccount(int id, int value, std::string type)
{
	if (type == "deposit" || type == "withdraw")
	{
		if (value < 0)
		{
			std::cout << "*** Invalid value ***" << std::endl;
			return ;
		}
		std::vector<Account *>::iterator it = std::find_if(clientAccounts.begin(), clientAccounts.end(), FindAccount(id));
		if (it == clientAccounts.end())
		{
			std::cout << "*** Account not found ***" << std::endl;
			return ;
		}
		if (type == "deposit")
			deposit(id, value);
		else if (type == "withdraw")
			withdraw(id, value);
	}
	else
		std::cout << "** Invalid operation ***" << std::endl;
}
