#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

void printHeader(int i, std::string color, std::string reset, std::string testName)
{
	std::cout << color << "\n=============================================================\n" << reset;
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
			std::cout << "Catching exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(2, BLUE_BRIGHT, RESET, "BUREAUCRAT CREATION");
		try {
			Bureaucrat john("John", 50);
			std::cout << john << std::endl;
			Bureaucrat alice("Alice", 1);
			std::cout << alice << std::endl;
			Bureaucrat bob("Bob", 150);
			std::cout << bob << std::endl;
		} catch (std::exception &e) {
			std::cout << "Catching exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(3, RED, RESET, "BUREAUCRAT BAD GRADES");
		try {
			Bureaucrat high("TooHigh", 0);
		} catch (std::exception &e) {
			std::cout << "Catching exception pour grade 0: " << e.what() << std::endl;
		}
		try {
			Bureaucrat low("TooLow", 151);
		} catch (std::exception &e) {
			std::cout << "Catching exception pour grade 151: " << e.what() << std::endl;
		}
	}
	{
		printHeader(4, MAGENTA, RESET, "FORM SIGNING TESTS");
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
			std::cout << "Catching exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(5, CYAN, RESET, "FORM EXECUTION TESTS - SHRUBBERY");
		try {
			ShrubberyCreationForm form("home");
			Bureaucrat boss("Boss", 1);
			Bureaucrat worker("Worker", 140);
			Bureaucrat executor("Executor", 130);
			std::cout << "Trying to execute without signature:" << std::endl;
			worker.executeForm(form);
			std::cout << "\nSigning the form:" << std::endl;
			boss.signForm(form);
			std::cout << "\nTrying to execute with signature:" << std::endl;
			worker.executeForm(form);
			std::cout << "\nTrying to execute with sufficient grade:" << std::endl;
			executor.executeForm(form);
		} catch (std::exception &e) {
			std::cout << "Catching exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(6, GREEN, RESET, "FORM EXECUTION TESTS - ROBOTOMY");
		try {
			RobotomyRequestForm form("target");
			Bureaucrat boss("Boss", 1);
			boss.signForm(form);
			std::cout << "\nTrying to execute Robotomy form (randomly):" << std::endl;
			boss.executeForm(form);
			std::cout << "\nTrying again (randomly):" << std::endl;
			boss.executeForm(form);
		} catch (std::exception &e) {
			std::cout << "Catching exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(7, YELLOW, RESET, "FORM EXECUTION TESTS - PRESIDENTIAL PARDON");
		try {
			PresidentialPardonForm form("criminal");
			Bureaucrat president("President", 1);
			Bureaucrat minister("Minister", 10);
			std::cout << "Trying to execute with insufficient grade:" << std::endl;
			president.signForm(form);
			minister.executeForm(form);
			std::cout << "\nTrying to execute with sufficient grade:" << std::endl;
			president.executeForm(form);
		} catch (std::exception &e) {
			std::cout << "Catching exception: " << e.what() << std::endl;
		}
	}
	{
		printHeader(8, RED, RESET, "GRADE INCREMENT/DECREMENT TESTS");
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
			std::cout << "Catching exception: " << e.what() << std::endl << std::endl;
		}
	}
	return (0);
}