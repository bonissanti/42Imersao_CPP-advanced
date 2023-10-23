#ifndef HAMMER_HPP
#define HAMMER_HPP

#include "tool.hpp"

class Worker;
class tool;

class Hammer : public Tool
{
	public:
		Hammer() : Tool() {}

		void use();
		std::string getName();
};

#endif