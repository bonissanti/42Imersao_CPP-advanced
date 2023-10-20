#include "worker.hpp"
#include "shovel.hpp"

int main()
{
	Worker *worker = new Worker();
	Shovel *shovel = new Shovel();

	worker->giveShovel(shovel);
	worker->takeAwayShovel();
	delete worker;

	if (shovel->number_of_uses > 0)
		std::cout << "Shovel still has uses" << std::endl;
	else
		std::cout << "Shovel has no uses" << std::endl;
	
	delete shovel;
	if (shovel->number_of_uses > 0)
		std::cout << "Shovel still has uses" << std::endl;
	else
		std::cout << "Shovel has no uses" << std::endl;
	return (0);
}