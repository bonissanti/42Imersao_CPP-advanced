// #include "account.hpp"
#include "bank.hpp"
#include <string>

int main(void)
{
	Bank bank;

	bank.createAccount(1, 100);
	bank.createAccount(2, 50);
	bank.createAccount(3, 150);

	bank.printBankDetails();	
	bank.giveLoan(1, 500);
	bank.giveLoan(3, -1000);

	printf("\n");

	// bank.modifyAccount(1, 2000);
	// bank.modifyAccount(2, 2000);

	bank.printBankDetails();
	return (0);
}
