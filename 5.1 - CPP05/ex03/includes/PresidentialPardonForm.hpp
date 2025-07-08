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
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();

	void execute(Bureaucrat const &executor) const;
};

#endif