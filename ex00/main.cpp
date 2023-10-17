#include "bank.hpp"

int main(void)
{
	Bank *bank = new Bank();

	bank->printBankDetails();
	bank->createAccount(1, 100);
	bank->createAccount(2, 50);
	
	bank->printBankDetails();
	bank->modifyAccount(1, 50, "deposit");
	bank->modifyAccount(4, 8, "withdraw");

	bank->printBankDetails();
	bank->giveLoan(2, 100);
	bank->printBankDetails();

	bank->deleteAccount(1);
	bank->deleteAccount(2);
	bank->printBankDetails();
	delete bank;
	return (0);
}
