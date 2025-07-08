#include "Bureaucrat.hpp"
#include "Form.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "colors.hpp"
#include <iostream>

void printHeader(int i, std::string color, std::string reset, std::string testName)
{
	std::cout << color << "\n=======================================================\n" << reset;
	std::cout << WHITE << "      TEST " << i << " : " << testName << RESET << std::endl;
	std::cout << color << "=======================================================\n" << reset << std::endl;
}

int main()
{
	{
		printHeader(1, YELLOW, RESET, "FORM CONSTRUCTION TESTS");
		try {
			Form f1("A38", false, 50, 25);
			std::cout << f1 << std::endl;
		} catch (std::exception &e) {
			std::cout << "Catching exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(2, GREEN, RESET, "FORM BAD GRADES");
		try {
			Form f2("B456", false, 0, 100);
		} catch (std::exception &e) {
			std::cout << "Catching exception pour grade 0 (sign): " << e.what() << std::endl;
		}
		try {
			Form f3("Z8232", false, 100, 151);
		} catch (std::exception &e) {
			std::cout << "Catching exception pour grade 151 (exec): " << e.what() << std::endl;
		}
	}
	{
		printHeader(3, CYAN, RESET, "SIGNING SUCCESS");
		try {
			Bureaucrat jean("Jean", 40);
			Form contract("Contract", false, 50, 30);
			std::cout << jean << std::endl;
			std::cout << contract << std::endl;
			jean.signForm(contract);
			std::cout << contract << std::endl;
		} catch (std::exception &e) {
			std::cout << "Catching exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(4, PINK, RESET, "SIGNING FAILURE");
		try {
			Bureaucrat michel("Michel", 120);
			Form secretForm("Secret Form", false, 50, 30);
			std::cout << michel << std::endl;
			std::cout << secretForm << std::endl;
			michel.signForm(secretForm);
		} catch (std::exception &e) {
			std::cout << "Catching exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(5, BLUE_BRIGHT, RESET, "SIGNING TWICE");
		try {
			Bureaucrat camille("Camille", 10);
			Form certificate("Certificate", false, 20, 15);

			camille.signForm(certificate);
			camille.signForm(certificate);
		} catch (std::exception &e) {
			std::cout << "Catching exception: " << e.what() << std::endl;
		}
	}
	return (0);
}
