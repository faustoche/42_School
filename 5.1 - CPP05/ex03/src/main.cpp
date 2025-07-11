#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Intern.hpp"

void printHeader(int i, std::string color, std::string reset, std::string testName)
{
	std::cout << color << "\n================================================================\n" << reset;
	std::cout << WHITE << "   TEST " << i << " : " << testName << RESET << std::endl;
	std::cout << color << "================================================================\n" << reset << std::endl;
}

int main()
{
	{
		printHeader(1, MAGENTA, RESET, "INTERN IS TRYING TO WORK : SHRUBBERY CREATION FORM");
		try {
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("shrubbery creation", "christmas tree");
			delete rrf;
		} catch (const Intern::InternException &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		printHeader(2, GREEN, RESET, "INTERN IS TRYING TO WORK : ROBOTOMY REQUEST");
		try {
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			delete rrf;
		} catch (const Intern::InternException &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		printHeader(3, YELLOW, RESET, "INTERN IS TRYING TO WORK : PRESIDENTIAL PARDON");
		try {
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("presidential pardon", "king");
			delete rrf;
		} catch (const Intern::InternException &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		printHeader(4, PINK, RESET, "INTERN IS TRYING TO WORK : UNKNOWN FORM");
		try {
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("blougiboulga", "casimir");
			delete rrf;
		} catch (const Intern::InternException &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}