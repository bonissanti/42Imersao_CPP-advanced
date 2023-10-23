#include "workshop.hpp"

void Workshop::registerWorker(Worker *worker)
{
	workers.push_back(worker);
	std::cout << "Worker " << worker->id << " is registered the workshop" << std::endl;
}

void Workshop::releaseWorker(Worker *worker)
{
	std::vector<Worker *>::iterator it = std::find(workers.begin(), workers.end(), worker);
	if (it != workers.end())
	{
		workers.erase(it);
		std::cout << "Worker " << worker->id << " is released the workshop" << std::endl;
	}
}

void Workshop::executeWork()
{
	for (std::vector<Worker *>::iterator it = workers.begin(); it != workers.end(); it++)
		(*it)->use();
}