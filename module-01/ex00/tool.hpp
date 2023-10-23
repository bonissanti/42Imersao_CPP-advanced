#ifndef TOOL_HPP
#define TOOL_HPP

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

class Worker;

class Tool
{
	public:
		int number_of_uses;

		Tool() : number_of_uses(0) {}

		virtual void use() = 0;
		virtual std::string getName() = 0;
		virtual ~Tool() {} // virtual destructor
};

#endif