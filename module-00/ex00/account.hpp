#include <iostream>
#include <cstring>

class Account 
{
	private:
		int id;
		int value;

	public:
		Account(int id, int value);
		int getID(void) const;
		int getValue(void) const;
		void setValue(int value);
		void printAccountDetails();
		void receiveValue(int value);
		int getBalance(void) const;
};

struct FindAccount
{
	int id;
	FindAccount(int id) : id(id) {}
	bool operator()(Account *account) const
	{
		return (account->getID() == id);
	}
};
