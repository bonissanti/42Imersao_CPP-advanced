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
		void receiveLoan(int value);
};



