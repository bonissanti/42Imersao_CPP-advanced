#include "shovel.hpp"

void Shovel::use()
{
	if (this->number_of_uses > 0)
		this->number_of_uses--;
}