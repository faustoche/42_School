#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

/*-------------- INCLUDES --------------*/

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*-------------- CLASS --------------*/

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target, int _signed_grade, int _exec_grade);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	void execute(const Bureaucrat &exec) const;
};

#endif