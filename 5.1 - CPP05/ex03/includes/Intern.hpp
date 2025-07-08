#ifndef INTERN_HPP
#define INTERN_HPP

/*-------------- INCLUDES --------------*/

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*-------------- CLASS --------------*/

class Intern
{
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	virtual ~Intern();

	class InternException : std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	
	AForm *makeForm(std::string formName, std::string formTarget);
};

#endif