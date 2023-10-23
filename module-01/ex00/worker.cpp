#include "worker.hpp"
#include "tool.hpp"

void Worker::init_worker()
{
	coordonnee.x = 0;
	coordonnee.y = 0;
	coordonnee.z = 0;
	stat.level = 0;
	stat.exp = 0;
}

Worker* find_worker_with_tool(std::vector<Worker*> workers, Tool* tool)
{
	for (std::vector<Worker*>::iterator it = workers.begin(); it != workers.end(); it++)
	{
		std::vector<Tool *> tools = (*it)->getTools();
		if (std::find(tools.begin(), tools.end(), tool) != tools.end())
			return (*it);
	}
	return (NULL);
}

void Worker::use()
{
	std::cout << "Worker " << id << " is working" << std::endl;
	for (std::vector<Tool *>::iterator it = tools.begin(); it != tools.end(); it++)
		(*it)->use();
	number_of_uses++;
}

std::string Worker::getName()
{
	return ("Worker");
}

Worker::~Worker()
{
	while (!tools.empty())
	{
		std::cout << "Worker " << id << " is giving back a tool" << std::endl;
		giveTool(tools.back());
	}
}

void Worker::takeTool(Tool *work_tool, Worker *otherWorker)
{
	if (std::find(tools.begin(), tools.end(), work_tool) != tools.end())
	{
		std::cout << "Worker " << id << " already has " << work_tool->getName() << std::endl;
		return ;
	}
	if (otherWorker != NULL && std::find(otherWorker->tools.begin(), otherWorker->tools.end(), work_tool) != otherWorker->tools.end())
	{
		std::cout << "Worker " << otherWorker->id << " is giving back the " << work_tool->getName() << " because Worker " << id << " needs it." << std::endl;
        otherWorker->giveTool(work_tool);
	}
	tools.push_back(work_tool);
	std::cout << "Worker " << id << " has " << work_tool->getName() << std::endl;
}

void Worker::giveTool(Tool *tool)
{
	std::vector<Tool *>::iterator it = std::find(tools.begin(), tools.end(), tool);
	if (it != tools.end())
	{
		tools.erase(it);
		std::cout << "Worker " << id << " is without a tool\n";
	}
}

std::vector<Tool *> Worker::getTools()
{
	return (tools);
}
