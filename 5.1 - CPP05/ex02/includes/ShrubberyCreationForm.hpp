#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

/*--------------- INCLUDES ----------------*/

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*--------------- CLASS ----------------*/

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &target, int signed_grade, int exec_grade);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	void execute(const Bureaucrat &exec) const;
};

#endif