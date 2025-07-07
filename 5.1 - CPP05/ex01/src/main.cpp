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
			Form f1("Formulaire A38", false, 50, 25);
			std::cout << f1 << std::endl;
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	{
		printHeader(2, GREEN, RESET, "FORM BAD GRADES");

		try {
			Form f2("Trop Haut", false, 0, 100);
		} catch (std::exception &e) {
			std::cout << "Exception pour grade 0 (sign): " << e.what() << std::endl;
		}

		try {
			Form f3("Trop Bas", false, 100, 151);
		} catch (std::exception &e) {
			std::cout << "Exception pour grade 151 (exec): " << e.what() << std::endl;
		}
	}

	{
		printHeader(3, CYAN, RESET, "SIGNING SUCCESS");

		try {
			Bureaucrat b1("Jean", 40);
			Form f4("Contrat", false, 50, 30);

			std::cout << b1 << std::endl;
			std::cout << f4 << std::endl;

			b1.signForm(f4);

			std::cout << f4 << std::endl;
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	{
		printHeader(4, PINK, RESET, "SIGNING FAILURE");

		try {
			Bureaucrat b2("Michel", 120);
			Form f5("Secret Form", false, 50, 30);

			std::cout << b2 << std::endl;
			std::cout << f5 << std::endl;

			b2.signForm(f5);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	{
		printHeader(5, BLUE_BRIGHT, RESET, "SIGNING TWICE");

		try {
			Bureaucrat b3("Claire", 10);
			Form f6("Certificat", false, 20, 15);

			b3.signForm(f6);
			b3.signForm(f6); // déjà signé
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	return 0;
}
