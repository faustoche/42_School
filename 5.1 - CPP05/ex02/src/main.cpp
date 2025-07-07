#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

void printHeader(int i, std::string color, std::string reset, std::string testName)
{
	std::cout << color << "\n===========================================================\n" << reset;
	std::cout << WHITE << "      TEST " << i << " : " << testName << RESET << std::endl;
	std::cout << color << "=============================================================\n" << reset << std::endl;
}

int main()
{
	{
		printHeader(1, YELLOW, RESET, "FORM CONSTRUCTION TESTS");
		try {
			ShrubberyCreationForm home("home");
			std::cout << home << std::endl;
			RobotomyRequestForm robot("robot_target");
			std::cout << robot << std::endl;
			PresidentialPardonForm criminal("criminal");
			std::cout << criminal << std::endl;
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(2, GREEN, RESET, "FORM BAD GRADES");
		try {
			ShrubberyCreationForm f1("test");
		} catch (std::exception &e) {
			std::cout << "Exception for grade 0 (sign): " << e.what() << std::endl;
		}
		try {
			RobotomyRequestForm f2("test");
		} catch (std::exception &e) {
			std::cout << "Exception for grade 151 (exec): " << e.what() << std::endl;
		}
	}
	{
		printHeader(3, BLUE_BRIGHT, RESET, "BUREAUCRAT CREATION");
		try {
			Bureaucrat john("John", 50);
			std::cout << john << std::endl;
			Bureaucrat alice("Alice", 1);
			std::cout << alice << std::endl;
			Bureaucrat bob("Bob", 150);
			std::cout << bob << std::endl;
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(4, RED, RESET, "BUREAUCRAT BAD GRADES");
		try {
			Bureaucrat high("TooHigh", 0);
		} catch (std::exception &e) {
			std::cout << "Exception pour grade 0: " << e.what() << std::endl;
		}
		try {
			Bureaucrat low("TooLow", 151);
		} catch (std::exception &e) {
			std::cout << "Exception pour grade 151: " << e.what() << std::endl;
		}
	}
	{
		printHeader(5, MAGENTA, RESET, "FORM SIGNING TESTS");
		try {
			ShrubberyCreationForm form("garden");
			Bureaucrat boss("Boss", 1);
			Bureaucrat intern("Intern", 150);
			std::cout << "Before signature:" << std::endl;
			std::cout << form << std::endl;
			std::cout << "\nInterne is trying to sign:" << std::endl;
			intern.signForm(form);
			std::cout << "\nBoss is trying to sign:" << std::endl;
			boss.signForm(form);
			std::cout << "\nAfter signature:" << std::endl;
			std::cout << form << std::endl;
			std::cout << "\nTrying to sign again:" << std::endl;
			boss.signForm(form);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(6, CYAN, RESET, "FORM EXECUTION TESTS - SHRUBBERY");
		try {
			ShrubberyCreationForm form("home");
			Bureaucrat boss("Boss", 1);
			Bureaucrat worker("Worker", 140);
			std::cout << "Trying to execute without signature:" << std::endl;
			worker.executeForm(form);
			std::cout << "\nSigning the form:" << std::endl;
			boss.signForm(form);
			std::cout << "\nTrying to execute with signature:" << std::endl;
			worker.executeForm(form);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(7, GREEN, RESET, "FORM EXECUTION TESTS - ROBOTOMY");
		try {
			RobotomyRequestForm form("target");
			Bureaucrat boss("Boss", 1);
			boss.signForm(form);
			std::cout << "\nTrying to execute Robotomy form:" << std::endl;
			boss.executeForm(form);
			std::cout << "\nTrying again (randomly):" << std::endl;
			boss.executeForm(form);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(8, YELLOW, RESET, "FORM EXECUTION TESTS - PRESIDENTIAL PARDON");
		try {
			PresidentialPardonForm form("criminal");
			Bureaucrat president("President", 1);
			Bureaucrat minister("Minister", 10);
			std::cout << "Trying to execute with insuffisant grade:" << std::endl;
			president.signForm(form);
			minister.executeForm(form);
			std::cout << "\nTrying to execute with suffisant grade:" << std::endl;
			president.executeForm(form);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(9, RED, RESET, "GRADE INCREMENT/DECREMENT TESTS");
		try {
			Bureaucrat test("Test", 75);
			std::cout << "Original: " << test << std::endl;
			test.incrementGrade(25);
			std::cout << "After increment of 25: " << test << std::endl;
			test.decrementGrade(10);
			std::cout << "After decrement of 10: " << test << std::endl;
			std::cout << "\nTrying to increment too much:" << std::endl;
			test.incrementGrade(100);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(10, BLUE_BRIGHT, RESET, "COPY CONSTRUCTOR AND ASSIGNMENT TESTS");
		try {
			ShrubberyCreationForm original("original");
			Bureaucrat signer("Signer", 1);
			signer.signForm(original);
			std::cout << "Original: " << original << std::endl;
			ShrubberyCreationForm copy(original);
			std::cout << "Copy: " << copy << std::endl;
			ShrubberyCreationForm tmp("temporary");
			tmp = original;
			std::cout << "Temporary: " << tmp << std::endl;
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	return (0);
}