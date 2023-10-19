# ifndef TOOL_HPP
# define TOOL_HPP

class Tool
{
	public:
		int number_of_uses;
		Tool() : number_of_uses(5) {};
		virtual void use();
};

# endif