#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

/*--------------- INCLUDES ----------------*/

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

/*--------------- CLASS ----------------*/

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target, int signed_grade, int exec_grade);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	void execute(const Bureaucrat &exec) const;
};

#endif