#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

class Worker;

class Tool
{
	public:
		int number_of_uses;
		Worker *current_worker;

		Tool() : number_of_uses(0), current_worker(NULL) {}

		virtual void use()
		{
			std::cout << "Tool is used" << std::endl;
			number_of_uses++;
		}
		virtual std::string getName()
		{
			return ("Tool");
		}
		virtual ~Tool() {} // virtual destructor
};

class Shovel : public Tool
{
	public:
		Shovel() : Tool() {}

		void use()
		{
			std::cout << "Shovel is used" << std::endl;
			number_of_uses++;
		}
		std::string getName()
		{
			return ("Shovel");
		}
};

class Hammer : public Tool
{
	public:
		Hammer() : Tool() {}

		void use()
		{
			std::cout << "Hammer is used" << std::endl;
			number_of_uses++;
		}
		std::string getName()
		{
			return ("Hammer");
		}
};

class Worker : public Tool
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
		// Position coordonnee;
		// Statistic stat;
		std::vector<Tool *> tools;

	public:
		int id;

		Worker(int id) : id(id) {} //Mudar id para algo incrementado

		void takeTool(Tool *work_tool)
		{
			tools.push_back(work_tool);
			std::cout << "Worker " << id << " is taking " << work_tool->getName() << std::endl;
			// if (work_tool->current_worker)
			// {
			// 	std::cout << "Worker " << id << " is taking " << work_tool->getName() << " from worker " << work_tool->current_worker->id << std::endl;
			// 	return ;
			// }
			// else
			// 	std::cout << "Worker " << id << " is took a " << work_tool->getName() << " from storage" << std::endl;
			// tools.push_back(work_tool);
			// work_tool->current_worker = this;
		}

	

		void giveTool(Tool *tool)
		{
			std::vector<Tool *>::iterator it = std::find(tools.begin(), tools.end(), tool);
			if (it != tools.end())
			{
				tools.erase(it);
				std::cout << "Worker " << id << " is without a tool\n";
			}
		}

		~Worker()
		{
			while (!tools.empty())
			{
				std::cout << "Worker " << id << " is giving back a tool" << std::endl;
				giveTool(tools.back());
			}
		}
};

int main(void)
{
	Shovel *shovel = new Shovel();
	Hammer *hammer = new Hammer();
	Worker *worker1 = new Worker(1);
	Worker *worker2 = new Worker(2);

	worker1->takeTool(shovel);
	worker2->takeTool(shovel);

	worker1->giveTool(shovel);
	worker2->takeTool(hammer);

	worker1->takeTool(hammer);

	delete worker1;
	delete worker2;
	delete hammer;
	delete shovel;

	if (shovel)
		std::cout << "Shovel is not deleted" << std::endl;
	else
		std::cout << "Shovel is deleted" << std::endl;

	// delete shovel;
	return (0);
}




// void takeShovel(Shovel *new_owner)
	// {
	//     if (new_owner->current_worker)
	//     {
	//         std::cout << "Worker " << id << " is taking shovel from worker " << new_owner->current_worker->id << std::endl; 
	//         new_owner->current_worker->shovel = NULL;
	//     }
	//     else
	//         std::cout << "Worker " << id << " is taking shovel from storage" << std::endl;
	//     new_owner->current_worker = this;
	//     shovel = new_owner;
	// }

// void giveShovel()
	// {
	// 	if (shovel)
	// 	{
	// 		std::cout << "Worker " << id << " is given back shovel\n";
	// 		shovel->current_worker = NULL;
	// 		shovel = NULL;
	// 	}
	// 	else
	// 		std::cout << "Worker " << id << " has no shovel" << std::endl;
	// }