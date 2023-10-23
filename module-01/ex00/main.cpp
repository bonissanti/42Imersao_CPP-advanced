#include "tool.hpp"
#include "worker.hpp"
#include "workshop.hpp"

int main(void)
{
	Workshop workshop;

	Worker *worker1 = new Worker(1);
	Worker *worker2 = new Worker(2);
	Hammer *hammer = new Hammer();
	Shovel *shovel = new Shovel();

	std::cout << std::endl << " --- Taking tools --- " << std::endl << std::endl;
	worker1->takeTool(hammer, NULL);
	worker2->takeTool(hammer, worker1);
	worker1->giveTool(hammer);
	worker2->takeTool(hammer, NULL);
	worker1->takeTool(shovel, NULL);
	
	std::cout << std::endl << " --- Start of the work --- " << std::endl << std::endl;
	workshop.registerWorker(worker1);
	workshop.registerWorker(worker2);
	workshop.executeWork();

	std::cout << std::endl << " --- End of the work --- " << std::endl << std::endl;
	delete worker1;
	delete worker2;

	std::cout << std::endl << " --- Deleting tools --- " << std::endl << std::endl;	

	delete hammer;
	hammer = NULL;
	delete shovel;
	shovel = NULL;

	if (hammer || shovel)
		std::cout << "Shovel and hammer are not deleted" << std::endl;
	else
		std::cout << "Shovel and hammer are deleted" << std::endl;
	
	return (0);
}

// int main(void)
// {
// 	Shovel *shovel = new Shovel();
// 	Hammer *hammer = new Hammer();
// 	Worker *worker1 = new Worker(1);
// 	Worker *worker2 = new Worker(2);

// 	std::vector<Worker *> workers;
// 	workers.push_back(worker1);
// 	workers.push_back(worker2);

// 	worker1->takeTool(shovel);
// 	worker2->takeTool(shovel);

// 	worker1->giveTool(shovel);
// 	worker2->takeTool(hammer);

// 	worker1->takeTool(hammer);

// 	Worker *workerWithShovel = find_worker_with_tool(workers, shovel);
// 	if (workerWithShovel)
// 		std::cout << "Worker " << workerWithShovel->id << " has a shovel" << std::endl;
// 	else
// 		std::cout << "No worker has a shovel" << std::endl;

// 	Worker *workerWithHammer = find_worker_with_tool(workers, hammer);
// 	if (workerWithHammer)
// 		std::cout << "Worker " << workerWithHammer->id << " has a hammer" << std::endl;
// 	else
// 		std::cout << "No worker has a hammer" << std::endl;

// 	delete worker1;
// 	delete worker2;
// 	delete hammer;
// 	delete shovel;

// 	if (shovel)
// 		std::cout << "Shovel is not deleted" << std::endl;
// 	else
// 		std::cout << "Shovel is deleted" << std::endl;

// 	// delete shovel;
// 	return (0);
// }
