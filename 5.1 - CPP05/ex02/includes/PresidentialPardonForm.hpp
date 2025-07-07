#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

/*-------------- INCLUDES --------------*/

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*-------------- CLASS --------------*/

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target, int signed_grade, int exec_grade);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	void execute(Bureaucrat const &executor) const;
};

#endif