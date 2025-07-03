#pragma once

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <iomanip>

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

	class GradeTooHighException : public exception
	{
	public:
		GradeTooHighException();
		GradeTooHighException(const GradeTooHighException &other);
		GradeTooHighException &operator=(const GradeTooHighException &other);
		~GradeTooHighException();
	};

	class GradeTooLowException : public exception
	{
	public:
		GradeTooLowException();
		GradeTooLowException(const GradeTooLowException &other);
		GradeTooLowException &operator=(const GradeTooLowException &other);
		~GradeTooLowException();
	};

	std::string	getName() const;
	int	getGrade() const;
	void incrementGrade(); // augmente grade donc diminu numero
	void decrementeGrade(); // diminue grade donc augmente numero

};

class exception
{
public:
	exception() throw();
	exception (const exception&) throw();
	exception &operator=(const exception&) throw();
	virtual ~exception() throw();
	virtual const char *what() const throw();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &f);