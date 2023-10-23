#include "hammer.hpp"

void Hammer::use()
{
	std::cout << "Hammer is used" << std::endl;
	number_of_uses++;
}

std::string Hammer::getName()
{
	return ("Hammer");
}