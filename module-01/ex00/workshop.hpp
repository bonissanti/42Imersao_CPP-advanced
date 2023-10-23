#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include "worker.hpp"

class Worker;

class Workshop
{
	private:
		std::vector<Worker *> workers;

	public:
		void registerWorker(Worker *worker);
		void releaseWorker(Worker *worker);
		void executeWork();
};

#endif