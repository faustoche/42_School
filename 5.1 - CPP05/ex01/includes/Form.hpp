#ifndef FORM_HPP
#define FORM_HPP

/*-------------- INCLUDES --------------*/

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iomanip>
#include <iostream>

/*--------------- CLASS ----------------*/

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _grade_signed;
	const int _grade_execute;

public:
	Form();
	Form(const std::string &name, bool isSigned, const int grade_signed, const int grade_exec);
	Form(const Form &other);
	Form &operator=(const Form &other);
	virtual ~Form();

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class AlreadySignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	std::string getName() const;
	bool getSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;
	void beSigned(const Bureaucrat &Bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif

