#ifndef AFORM_HPP
#define AFORM_HPP

/*-------------- INCLUDES --------------*/

#include "Bureaucrat.hpp"
#include <iomanip>
#include <iostream>

/*--------------- CLASS ----------------*/

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _grade_signed;
	const int _grade_execute;

public:
	AForm();
	AForm(const std::string &name, int grade_signed, int grade_exec);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

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

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowToExecuteException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	std::string getName() const;
	bool getSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif

