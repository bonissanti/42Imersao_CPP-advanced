#include "worker.hpp"

void Worker::giveShovel(Shovel *shovel_to_take)
{
	if (this->shovel)
		this->shovel = NULL;
	this->shovel = shovel_to_take;
}

void Worker::takeAwayShovel()
{
	if (this->shovel)
		this->shovel = NULL;
}

Worker::~Worker()
{
	if (this->shovel)
		delete this->shovel;
}