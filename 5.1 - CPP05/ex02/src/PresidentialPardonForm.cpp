#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

/*-------------- CONSTRUCTORS --------------*/

PresidentialPardonForm::PresidentialPardonForm() : _target("unnamed"){
	std::cout << "Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target, int signed_grade, int exec_grade) : AForm("PresidentialPardonForm", false, 25, 5), _target(target){
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other){
	this->_target = other._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if (this != &other){
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "Destructor called" << std::endl;
}

/*-------------- FUNCTIONS --------------*/

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeRequiredToExecute())
		throw AForm::GradeTooLowToExecuteException();
	std::cout << _target << " has been forgiven by Zaphod Beeblebrox." << std::endl;
}
