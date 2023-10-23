#ifndef SHOVEL_HPP
#define SHOVEL_HPP

#include "tool.hpp"

class Worker;
class tool;

class Shovel : public Tool
{
	public:
		Shovel() : Tool() {}

		void use();
		std::string getName();
};

#endif