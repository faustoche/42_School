#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*-------------- CONSTRUCTORS --------------*/

Intern::Intern(){
//	std::cout << "Default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
	*this = other;
}


Intern &Intern::operator=(const Intern &other){
	if (this != &other){
		return (*this);
	}
	return (*this);
}

Intern::~Intern(){
	// std::cout << "Destructor called" << std::endl;
}

/*-------------- FUNCTIONS --------------*/

const char *Intern::InternException::what() const throw(){
	return ("I don't know what you're talking about. Please go to desk A78.");
}

AForm *Intern::makeForm(std::string formName, std::string formTarget){
	std::string forms[] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	int i = 0;
	while (i < 3 && forms[i] != formName)
		i++;
	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << formName << std::endl;
		return (new ShrubberyCreationForm(formTarget));
	case 1:
		std::cout << "Intern creates " << formName << std::endl;
		return (new RobotomyRequestForm(formTarget));
	case 2:
		std::cout << "Intern creates " << formName << std::endl;
		return (new PresidentialPardonForm(formTarget));
	default:
		throw Intern::InternException();
	}
	return (0);
}