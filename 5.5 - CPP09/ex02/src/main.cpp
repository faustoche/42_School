#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac <= 2) {
		std::cout << "Error : wrong number of arguments" << std::endl;
		return (1);
	}
	try {
		PmergeMe::run(av + 1);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
