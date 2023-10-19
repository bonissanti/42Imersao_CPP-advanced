#include "bank.hpp"

void Bank::giveLoan(int id, int value)
{
	std::vector<Account *>::iterator it = std::find_if(clientAccounts.begin(), clientAccounts.end(), FindAccount(id));
	if (it == clientAccounts.end())
	{
		std::cout << "*** Account not found ***" << std::endl;
		return ;
	}
	if ((value < 0) || (value < -2147483648 && value > 2147483647))
	{
		std::cout << "*** Invalid value ***" << std::endl;
		return ;
	}
	else
	{
		if (liquidity < value)
		{
			std::cout << "*** Bank don't have enough money ***" << std::endl;
			return ;
		}
		liquidity -= value;
		(*it)->receiveValue(value);
	}
}

void Bank::deposit(int id, int value)
{
	std::vector<Account *>::iterator it = std::find_if(clientAccounts.begin(), clientAccounts.end(), FindAccount(id));
	if (it == clientAccounts.end())
	{
		std::cout << "*** Account not found ***" << std::endl;
		return ;
	}
	int fee = value * 0.05;
	liquidity += fee;
	(*it)->receiveValue(value - fee);
}

void Bank::withdraw(int id, int value)
{
	std::vector<Account *>::iterator it = std::find_if(clientAccounts.begin(), clientAccounts.end(), FindAccount(id));
	if (it == clientAccounts.end())
	{
		std::cout << "*** Account not found ***" << std::endl;
		return ;
	}
	if ((*it)->getBalance() < value)
	{
		std::cout << "*** Account don't have enough money ***" << std::endl;
		return ;
	}
	(*it)->receiveValue(-value);
}

void Bank::printBankDetails(void)
{
	std::cout << "\nBank Details:" << std::endl;	
	std::cout << "liquidity: " << liquidity << std::endl;
	std::cout << "Accounts: " << std::endl;
	for (std::size_t i = 0; i < clientAccounts.size(); i++)
		clientAccounts[i]->printAccountDetails();
}
