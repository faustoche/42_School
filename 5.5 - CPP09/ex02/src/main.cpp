#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cout << "Error" << std::endl;
        return (1);
    }
    try {
        PmergeMe::run(av + 1);
    } catch (...) {
        std::cout << "Error" << std::endl;
        return (1);
    }
    return (0);
}
