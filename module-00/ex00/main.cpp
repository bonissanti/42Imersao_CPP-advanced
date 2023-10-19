#include "bank.hpp"

int main(void)
{
	Bank bank;

	bank.printBankDetails();
	bank.createAccount(1, 100);
	bank.createAccount(2, 100);
	std::cout << "\n-----Print #1-----" << std::endl;

	bank.printBankDetails();
	bank.modifyAccount(2, 50, "deposit");

	std::cout << "\n-----Print #2-----" << std::endl;
	bank.printBankDetails();
	bank.giveLoan(2, 100);
	bank.printBankDetails();

	std::cout << "\n-----Print #4-----" << std::endl;
	bank.deleteAccount(1);
	bank.printBankDetails();
	std::cout << "\n-----Print #5-----" << std::endl;

	return (0);
}
