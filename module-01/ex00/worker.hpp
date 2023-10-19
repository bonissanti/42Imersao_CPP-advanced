#include <iostream>
#include <cstring>
#include "shovel.hpp"

# ifndef WORKER_HPP
# define WORKER_HPP

class Worker
{
	private:
		struct Position
		{
			int x;
			int y;
			int z;
		};
		struct Statistic
		{
			int level;
			int exp;
		};

	public:
		Position coordenate;
		Statistic stats;
		Shovel *shovel;
		Worker() : shovel(NULL) {};
		void giveShovel(Shovel *shovel_to_take);
		void takeAwayShovel();
		~Worker();
};

# endif


