#include "../includes/Bureaucrat.hpp"

/*-------------- CONSTRUCTORS --------------*/

Bureaucrat::Bureaucrat() : _name("unnamed"){
	_grade = 0;
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

void	Bureaucrat::decrementeGrade(int value){
	if (_grade + value > 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade += value;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade is too low");
}