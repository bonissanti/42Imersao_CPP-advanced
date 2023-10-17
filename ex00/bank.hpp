#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include "account.hpp"

class Bank
{
	private:
		int liquidity;
		std::vector<Account *> clientAccounts;
	
	public:
		Bank() : liquidity(200000) {}
		void createAccount(int id, int value);
		void deleteAccount(int id);
		void modifyAccount(int id, int value, std::string type);
		void printBankDetails(void);
		void giveLoan(int id, int value);
		void deposit(int id, int value);
		void withdraw(int id, int value);
};