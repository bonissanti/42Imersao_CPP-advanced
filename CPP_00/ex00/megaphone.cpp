#include <iostream>
#include <string>


//implementation of ft_toupper c++ style

std::string ft_toupper(std::string str)
{
	size_t i = 0;

	while (i < str.length())
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
	return (str);
}

int main(int argc, char *argv[])
{
	int i = 0;
	
	if (argc > 1)
	{
		while (++i < argc)
		{
			std::string str(argv[i]);
				std::cout << ft_toupper(str);
			std::cout << " ";
		}
		std::cout <<  std::endl;
	}
	else {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	}
	return (0);
}