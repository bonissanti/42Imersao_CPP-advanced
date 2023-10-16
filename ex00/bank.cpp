#include "bank.hpp"

void Bank::createAccount(int id, int value)
{
	auto it = clientAccounts.begin();
	while (it != clientAccounts.end())
	{
		if ((*it)->getID() == id)
		{
			std::cout << "Account already exists" << std::endl;
			return ;
		}
		it++;
	}
	clientAccounts.push_back(new Account(id, value));
}

void Bank::deleteAccount(int id)
{
	auto it = clientAccounts.begin();
	while (it != clientAccounts.end())
	{
		if ((*it)->getID() == id)
		{
			clientAccounts.erase(it);
			return ;
		}
		it++;
	}
	std::cout << "Account not found" << std::endl;
}

//  Refatorar modifyAccount para usar giveLoan

void Bank::modifyAccount(int id, int value)
{
	auto it = clientAccounts.begin();
	while (it != clientAccounts.end())
	{
		if ((*it)->getID() == id)
		{
			(*it)->setValue(value);
			return ;
		}
		it++;
	}
	std::cout << "Account not found" << std::endl;
}

void Bank::giveLoan(int id, int value)
{
	auto it = std::find_if(clientAccounts.begin(), clientAccounts.end(), [&](Account *account) { return (account->getID() == id); });
	if (it == clientAccounts.end())
	{
		std::cout << "Account not found" << std::endl;
		return ;
	}
	if (value < 0)
	{
		std::cout << "Can't give negative loan" << std::endl;
		return ;
	}
	else
	{
		if (liquidity < value)
		{
			std::cout << "Bank don't have enough liquidity" << std::endl;
			return ;
		}
		liquidity -= value;
		(*it)->receiveLoan(value);
	}
}


void Bank::printBankDetails(void)
{
	std::cout << "Bank Details:" << std::endl;	
	std::cout << "liquidity: " << liquidity << std::endl;
	std::cout << "Accounts: " << std::endl;
	for (auto &clientAccount : clientAccounts)
		clientAccount->printAccountDetails();
}