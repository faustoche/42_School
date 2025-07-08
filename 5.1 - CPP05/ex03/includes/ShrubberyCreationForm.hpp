#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

/*--------------- INCLUDES ----------------*/

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*--------------- CLASS ----------------*/

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();

	void execute(Bureaucrat const &executor) const;
};

#endif