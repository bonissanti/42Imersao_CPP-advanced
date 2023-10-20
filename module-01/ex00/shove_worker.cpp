#include <iostream>
#include <cstring>

class Worker;

class Shovel
{
	public:
		int number_of_uses;
		Worker *current_worker;

		Shovel() : number_of_uses(5), current_worker(NULL) {}

		void use()
		{
			if (number_of_uses > 0)
			{
				std::cout << "Shovel is used" << std::endl;
				number_of_uses--;
			}
			else
				std::cout << "Shovel is broken" << std::endl;
		}
};

class Worker
{
	private:
		// struct Position
		// {
		// 	int x;
		// 	int y;
		// 	int z;
		// };
		// struct Statistic
		// {
		// 	int level;
		// 	int exp;
		// };
		// Position coordenates;
		// Statistic stats;

	public:
		Shovel *shovel;
		int id;

		Worker(int id) : shovel(NULL), id(id) {} //Mudar id para algo incrementado

		void takeShovel(Shovel *new_owner)
		{
		    if (new_owner->current_worker)
		    {
		        std::cout << "Worker " << id << " is taking shovel from worker " << new_owner->current_worker->id << std::endl; 
		        new_owner->current_worker->shovel = NULL;
		    }
		    else
		    {
		        std::cout << "Worker " << id << " is taking shovel from storage" << std::endl;
		    }
		    new_owner->current_worker = this;
		    shovel = new_owner;
		}


		void giveShovel()
		{
			if (shovel)
			{
				std::cout << "Worker " << id << " is given back shovel\n";
				shovel->current_worker = NULL;
				shovel = NULL;
			}
			else
				std::cout << "Worker " << id << " has no shovel" << std::endl;
		}

		~Worker()
		{
			giveShovel();
		}
};

int main(void)
{
	Shovel *shovel = new Shovel();
	Worker *worker1 = new Worker(1);
	Worker *worker2 = new Worker(2);

	worker1->takeShovel(shovel);
	worker2->giveShovel();
	worker2->takeShovel(shovel);

	delete worker1;
	delete worker2;

	if (shovel)
		std::cout << "Shovel is not deleted" << std::endl;
	else
		std::cout << "Shovel is deleted" << std::endl;

	// delete shovel;
	return (0);
}