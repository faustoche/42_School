#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

/*-------------- CONSTRUCTORS --------------*/

Bureaucrat::Bureaucrat() : _name("unnamed"), _grade(150){
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name (name) {
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade){
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other){
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(){
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &f) {
	out << f.getName() << ", bureaucrat grade " << f.getGrade();
	return (out);
}

/*-------------- GETTERS --------------*/

std::string Bureaucrat::getName() const{
	return (this->_name);
}

int	Bureaucrat::getGrade() const{
	return (this->_grade);
}

/*-------------- FUNCTIONS --------------*/

void	Bureaucrat::incrementGrade(int value){
	if (_grade - value < 1)
		throw (Bureaucrat::GradeTooHighException());
	_grade -= value;
}

void	Bureaucrat::decrementGrade(int value){
	if (_grade + value > 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade += value;
}

void	Bureaucrat::signForm(AForm &form){
	if (this->_grade > form.getGradeRequiredToSign()){
		std::cout << this->_name << " couldn't sign " << form.getName() << " because it's grade is too low" << std::endl;
	} else if (form.getSigned()) {
		std::cout << this->_name << " couldn't sign " << form.getName() << " because it's already signed" << std::endl;
	} else {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade is too low");
}

void Bureaucrat::executeForm(AForm const &form) const{
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e){
		std::cout << this->_name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
	}
}