#pragma once

/*-------------- INCLUDES --------------*/

#include "colors.hpp"
#include <iostream>
#include <string>

/*-------------- CLASS --------------*/

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
	void decrementeGrade(int value);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &f);