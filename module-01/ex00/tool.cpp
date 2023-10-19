#include "tool.hpp"

void Tool::use()
{
	if (this->number_of_uses > 0)
		this->number_of_uses--;
}