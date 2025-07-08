#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*-------------- CONSTRUCTORS --------------*/

AForm::AForm() : _name("unnamed"), _signed(false), _grade_signed(150), _grade_execute(150){
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int grade_signed, int grade_exec)
: _name(name), _grade_signed(grade_signed), _grade_execute(grade_exec)
{
	if (grade_signed < 1 || grade_exec < 1)
		throw GradeTooHighException();
	if (grade_signed > 150 || grade_exec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
: _name(other._name), _signed(other._signed),
  _grade_signed(other._grade_signed), _grade_execute(other._grade_execute)
{
	std::cout << "Form " << _name << " copied" << std::endl;
}

AForm &AForm::operator=(const AForm &other){
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

AForm::~AForm(){
}

/*-------------- GETTERS --------------*/

std::string AForm::getName() const{
	return (this->_name);
}

bool AForm::getSigned() const {
	return (this->_signed);
}

int AForm::getGradeRequiredToSign() const {
	return (this->_grade_signed);
}

int AForm::getGradeRequiredToExecute() const {
	return (this->_grade_execute);
}

/*-------------- FUNCTIONS --------------*/

const char *AForm::GradeTooHighException::what() const throw(){
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw(){
	return ("Grade is too low!");
}

const char *AForm::AlreadySignedException::what() const throw(){
	return ("Form is already signed!");
}

const char *AForm::FormNotSignedException::what() const throw(){
	return ("Form is not signed yet!");
}

const char *AForm::GradeTooLowToExecuteException::what() const throw(){
	return ("Grade is too low to execute whatever!");
}

void AForm::beSigned(const Bureaucrat &bureaucrat){
	if (this->_signed)
		return ;
	if (bureaucrat.getGrade() > this->_grade_signed)
		throw (GradeTooLowException());
	_signed = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "Form: " << f.getName()
		<< ", signed: " << (f.getSigned() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeRequiredToSign()
		<< ", grade to execute: " << f.getGradeRequiredToExecute();
	return out;
}
