#include "Form.hpp"
#include "Bureaucrat.hpp"

/*-------------- CONSTRUCTORS --------------*/

Form::Form() : _name("unnamed"), _signed(false), _grade_signed(150), _grade_execute(150){
	std::cout << "Default constructor called" << std::endl;
}

Form::Form(const std::string &name, bool isSigned, const int grade_signed, const int grade_exec)
: _name(name), _signed(isSigned), _grade_signed(grade_signed), _grade_execute(grade_exec)
{
	if (grade_signed < 1 || grade_exec < 1)
		throw GradeTooHighException();
	if (grade_signed > 150 || grade_exec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
: _name(other._name), _signed(other._signed),
  _grade_signed(other._grade_signed), _grade_execute(other._grade_execute)
{
	std::cout << "Form " << _name << " copied" << std::endl;
}


// Form::Form(const Form &other){
// 	_name = other.getName();
// 	_grade_signed = other.getGradeRequiredToSign();
// 	_grade_execute = other.getGradeRequiredToExecute();

// 	std::cout << "Form " << other.getName();
// 	if (other.getSigned())
// 		std::cout << " (signed) with required grade ";
// 	else
// 		std::cout << " (not signed) with required grade ";
// 	std::cout << "for  signing: " << other.getGradeRequiredToSign() << " and for executing: " << other.getGradeRequiredToExecute() << " copied" << std::endl;
// }

Form &Form::operator=(const Form &other){
	if (this != &other)
		this->_signed = other._signed; // seuls les non-const peuvent être copiés
	return *this;
}


// Form &Form::operator=(const Form &other){
// 	this->_signed = other._signed;
// 	std::cout << "Form " << other.getName();
// 	if (other.getSigned())
// 		std::cout << " (signed) with required grade ";
// 	else
// 		std::cout << " (not signed) with required grade ";
// 	std::cout << "for  signing: " << other.getGradeRequiredToSign() << " and for executing: " << other.getGradeRequiredToExecute() << " copied with assignment operator" << std::endl;
// }

Form::~Form(){
	std::cout << "Form " << this->_name;
	if (this->_signed)
		std::cout << " (signed) with required grade ";
	else
		std::cout << " (not signed) with required grade ";
	std::cout << "for  signing: " << this->_grade_signed << " and for executing: " << this->_grade_execute << " destructed" << std::endl;
}

/*-------------- GETTERS --------------*/

std::string Form::getName() const{
	return (this->_name);
}

bool Form::getSigned() const {
	return (this->_signed);
}

int Form::getGradeRequiredToSign() const {
	return (this->_grade_signed);
}

int Form::getGradeRequiredToExecute() const {
	return (this->_grade_execute);
}

/*-------------- FUNCTIONS --------------*/

void Form::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > this->_grade_signed)
		throw Form::GradeTooLowException();
	if (this->getSigned())
		throw Form::AlreadySignedException();
	this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw(){
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw(){
	return ("Grade is too low!");
}

const char *Form::AlreadySignedException::what() const throw(){
	return ("Form is already signed!");
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << "Form: " << f.getName()
		<< ", signed: " << (f.getSigned() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeRequiredToSign()
		<< ", grade to execute: " << f.getGradeRequiredToExecute();
	return out;
}
