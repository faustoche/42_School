#include "RPN.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	RPN revpolnot = RPN();
	try {
		std::cout << revpolnot.result(av[1]) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
