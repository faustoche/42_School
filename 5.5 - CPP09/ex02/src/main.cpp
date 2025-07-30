#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cout << "Error" << std::endl;
        return (1);
    }
    try {
        PmergeMe::run(av + 1);
    } catch (...) { // attraper toutes les exceptions? ou bien faire une exception specifique?
        std::cout << "Error" << std::endl;
        return (1);
    }
    return (0);
}
