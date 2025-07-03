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

Bureaucrat::Bureaucrat(const Bureaucrat &other){
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other){
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Destructor called" << std::endl;
}

/*-------------- GETTERS --------------*/

std::string Bureaucrat::getName() const{
	return (this->_name);
}

int	Bureaucrat::getGrade() const{
	return (this->_grade);
}

/*-------------- FUNCTIONS --------------*/




std::ostream &operator<<(std::ostream &out, const Bureaucrat &f) {
	return (out);
}