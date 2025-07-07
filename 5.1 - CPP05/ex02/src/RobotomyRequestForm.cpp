#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Form.hpp"

/*-------------- CONSTRUCTORS --------------*/

RobotomyRequestForm::RobotomyRequestForm() : _target("unnamed"){
	std::cout << "Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target, int signed_grade, int exec_grade) : AForm("RobotomyRequestForm", 72, 45), _target(target){
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target){
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	if (this != &other){
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "Destructor called" << std::endl;
}

/*-------------- FUNCTIONS --------------*/

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeRequiredToExecute())
		throw AForm::GradeTooLowToExecuteException();
	std::cout << "Vrrrrr… vrrrrr…" << std::endl;
	std::cout << "Brrrrr… brrrrr…" << std::endl;
	std::cout << "Vrrrrrrrrrrrrrrr…" << std::endl;
	std::cout << "Bzzzzzzzz…" << std::endl;
	std::cout << "Zzzzzzzzz…" << std::endl;
	int random = std::rand() % 2;
	if (random == 0)
		std::cout << _target << " has been robotized with success!" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
