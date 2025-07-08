#include "Bureaucrat.hpp"

void printHeader(int i, std::string color, std::string reset, std::string testName)
{
	std::cout << color << "\n=======================================================\n" << reset;
	std::cout << WHITE << "      TEST " << i << " : " << testName << RESET << std::endl;
	std::cout << color << "=======================================================\n" << reset << std::endl;
}

int main()
{
	{
		printHeader(1, YELLOW, RESET, "BASIC CONSTRUCTION TESTS");
		try {
			Bureaucrat pierre("Pierre", 75);
			Bureaucrat paul("Paul", 1);
			Bureaucrat jacques("Jacques", 150);
	
			std::cout << pierre.getName() << " has grade " << pierre.getGrade() << std::endl;
			std::cout << paul.getName() << " has grade " << paul.getGrade() << std::endl;
			std::cout << jacques.getName() << " has grade " << jacques.getGrade() << std::endl;
		} catch (std::exception &e) {
			std::cout << "Oh, there's an exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(2, GREEN, RESET, "TOO LOW OR TOO HIGH");
		try {
			Bureaucrat high("TooHigh", 0);
		} catch (std::exception &e) {
			std::cout << "Catching exception for grade 0: " << e.what() << std::endl;
		}
		try {
			Bureaucrat low("TooLow", 151);
		} catch (std::exception &e) {
			std::cout << "Catching exception for grade 151: " << e.what() << std::endl;
		}
	
		try {
			Bureaucrat neg("Negative", -42);
		} catch (std::exception &e) {
			std::cout << "Catching exception for grade -42: " << e.what() << std::endl;
		}

	}
	{
		printHeader(3, PINK, RESET, "INCREMENT DECREMENT");
		try {
			Bureaucrat jennifer("Jennifer", 75);
			std::cout << jennifer << std::endl;
			jennifer.incrementGrade(10);
			std::cout << "Increment of 10: " << jennifer << std::endl;
			jennifer.decrementGrade(20);
			std::cout << "Decrement of 20: " << jennifer << std::endl;
		} catch (std::exception &e) {
			std::cout << "Catching exception: " << e.what() << std::endl;
		}
		try {
			Bureaucrat bestBur("Best bureaucrat", 1);
			std::cout << bestBur << std::endl;
			bestBur.incrementGrade(1);
			std::cout << "After increment: " << bestBur << std::endl;
		} catch (std::exception& e) {
			std::cout << "Catching exception at grade 1 increment: " << e.what() << std::endl;
		}
		try {
			Bureaucrat lastBur("Worst bureaucrat", 150);
			std::cout << lastBur << std::endl;
			lastBur.decrementGrade(1);
			std::cout << "After decrement: " << lastBur << std::endl;
		} catch (std::exception &e) {
			std::cout << "Catching exception at grade 150 decrement: " << e.what() << std::endl;
		}
	}
	{
		printHeader(4, BLUE_BRIGHT, RESET, "JUST CHECKING RANKS");
		Bureaucrat riri("Riri", 45);
		Bureaucrat fifi("Fifi", 2);
		Bureaucrat loulou("Loulou", 149);
		std::cout << riri << std::endl;
		std::cout << fifi << std::endl;
		std::cout << loulou << std::endl;
	}
	return (0);
}