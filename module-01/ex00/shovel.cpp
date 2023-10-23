#include "shovel.hpp"

void Shovel::use()
{
	std::cout << "Shovel is used" << std::endl;
	number_of_uses++;
}

std::string Shovel::getName()
{
	return ("Shovel");
}