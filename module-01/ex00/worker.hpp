#ifndef WORKER_HPP
#define WORKER_HPP

#include "tool.hpp"
#include "hammer.hpp"
#include "shovel.hpp"
#include <vector>
#include <iostream>

class tool;

Worker* find_worker_with_tool(std::vector<Worker*> workers, Tool* tool);

class Worker : public Tool
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
		Position coordonnee;
		Statistic stat;
		std::vector<Tool *> tools;

	public:
		int id;
		void init_worker();

		Worker(int id) : id(id) {} //Mudar id para algo incrementado
		void use();
		void takeTool(Tool *work_tool, Worker *otherWorker);
		void giveTool(Tool *tool);
		std::vector<Tool *> getTools();
		std::string getName();
		~Worker();
};

#endif