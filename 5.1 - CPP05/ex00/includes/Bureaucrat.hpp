#pragma once

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <iomanip>

/*-------------- CLASS --------------*/
class Bureaucrat
{
private:
	std::string name;
	int	grade; // from 0 to 150

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(Bureaucrat &other);
	~Bureaucrat();

	std::string	&getName() const;
	int	&getGrade() const;
	// member function to increment
	// member function de decrement

};