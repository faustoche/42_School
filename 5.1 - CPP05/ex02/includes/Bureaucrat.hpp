#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

/*-------------- INCLUDES --------------*/

// #include "colors.hpp"
#include "Form.hpp"
#include <iostream>
#include <fstream>
#include <string>

/*-------------- CLASS --------------*/

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int	_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

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

	std::string	getName() const;
	int	getGrade() const;
	void incrementGrade(int value);
	void decrementGrade(int value);
	void signForm(Form &form);

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &f);

#endif