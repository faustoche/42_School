#include "easyfind.hpp"

void printHeader(int i, std::string color, std::string reset, std::string testName)
{
	std::cout << color << "\n==================================================\n" << reset;
	std::cout << WHITE << "   TEST " << i << " : " << testName << RESET << std::endl;
	std::cout << color << "==================================================\n" << reset << std::endl;
}

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw (ValueNotFoundException());
	return (it);
}

int main(void)
{
	{
		int myInt[] = { 4, 5, 9, 45, 79, 98, 8582};
		std::vector<int> vect(myInt, myInt + sizeof(myInt) / sizeof(int));
		int testValues[] = {23, 435, 578, 23, 234, 47, 58, 0, 9876, 5, 4, 645643, 35};
		int testSize = sizeof(testValues) / sizeof(int);
		printHeader(1, GREEN, RESET, "TESTING SOME RANDOM VALUES");
		std::cout << WHITE << "My containers values: " << RESET << std::endl << std::endl;
		for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
			std::cout << " " << *it;
		std::cout << std::endl << std::endl;
		std::cout << WHITE << "Doing some try and catch: " << RESET << std::endl;
		for (int i = 0; i < testSize; ++i)
		{
			try {
				std::vector<int>::iterator it = easyfind(vect, testValues[i]);
				std::cout << GREEN << "Value found     : " << *it << RESET << std::endl;
			}
			catch (const std::exception &e){
				std::cout << RED << e.what() << " : " << testValues[i] << RESET << std::endl;
			}
		}
	}
	{
		printHeader(2, YELLOW, RESET, "TESTING AN EMPTY CONTAINER");
		std::vector<int> empty;
		try {
			easyfind(empty, 42);
		}
		catch (const std::exception &e){
			std::cout << "Empty container: " << e.what() << std::endl;
		}
	}
	{
		printHeader(3, CYAN, RESET, "TESTING DUPLICATES IN CONTAINER");
		int arr[] = {10, 20, 30, 20, 10, 20};
		std::vector<int> duplicates(arr, arr + sizeof(arr) / sizeof(int));
		std::cout << WHITE << "My containers values: " << RESET << std::endl;
		for (std::vector<int>::iterator it = duplicates.begin(); it != duplicates.end(); ++it)
			std::cout << " " << *it;
		std::cout << std::endl << std::endl;
		try {
			std::vector<int>::iterator it = easyfind(duplicates, 20);
			std::cout << GREEN << "Value found     : " << *it << RESET << std::endl;
		}
		catch (const std::exception &e){
			std::cout << RED << e.what() << " : " << 20 << RESET << std::endl;
		}
	}
	{
		printHeader(4, GOLD, RESET, "TESTING SINGLE ELEMENT CONTAINER");
		std::vector<int> single(1, 123);
		std::cout << WHITE << "My containers values: " << RESET << std::endl;
		for (std::vector<int>::iterator it = single.begin(); it != single.end(); ++it)
			std::cout << " " << *it;
		std::cout << std::endl << std::endl;
		try {
			std::vector<int>::iterator it = easyfind(single, 123);
			std::cout << GREEN << "Value found     : " << *it << RESET << std::endl;
			easyfind(single, 42);
		}
		catch (const std::exception &e){
			std::cout << RED << e.what() << " : " << 42 << RESET << std::endl;
		}
	}
	{
		printHeader(5, MAGENTA, RESET, "TESTING MAX VALUES");
		std::vector<int> limits;
		limits.push_back(INT_MIN);
		limits.push_back(0);
		limits.push_back(INT_MAX);
		int testValues[] = {INT_MIN, -1, 0, INT_MAX, 42};
		std::cout << WHITE << "My containers values: " << RESET << std::endl;
		for (std::vector<int>::iterator it = limits.begin(); it != limits.end(); ++it)
			std::cout << " " << *it;
		std::cout << std::endl << std::endl;
		for (int i = 0; i < 5; ++i)
		{
			try {
				std::vector<int>::iterator it = easyfind(limits, testValues[i]);
				std::cout << GREEN << "Value found     : " << *it << RESET << std::endl;
			}
			catch (const std::exception &e){
				std::cout << RED << e.what() << " : " << testValues[i] << RESET << std::endl;
			}
		}
	}
	{
		printHeader(6, RED, RESET, "TESTING WITH LIST CONTAINERS");
		std::list<int> listVect;
		listVect.push_back(1);
		listVect.push_back(2);
		listVect.push_back(3);
		listVect.push_back(42);
		listVect.push_back(5);
		std::cout << WHITE << "My containers values: " << RESET << std::endl;
		for (std::list<int>::iterator it = listVect.begin(); it != listVect.end(); ++it)
			std::cout << " " << *it;
		std::cout << std::endl << std::endl;
		try {
			std::list<int>::iterator it = easyfind(listVect, 42);
			std::cout << GREEN << "Value found     : " << *it << RESET << std::endl;
		}
		catch (const std::exception &e){
			std::cout << RED << e.what() << " : " << 42 << RESET << std::endl;
		}
		try {
			easyfind(listVect, 99);
		}
		catch (const std::exception &e){
			std::cout << RED << e.what() << " : " << 99 << RESET << std::endl;
		}
	}
	return (0);
}
