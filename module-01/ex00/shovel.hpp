#include <iostream>
#include <cstring>

# ifndef SHOVEL_HPP
# define SHOVEL_HPP



class Shovel
{
	public:
		int number_of_uses;
		Shovel() : number_of_uses(5) {};
		void use();
};

# endif