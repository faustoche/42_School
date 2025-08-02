#pragma once

/*-------------- INCLUDES --------------*/

#include <string>
#include <list>
#include <iostream>

/*-------------- CLASS --------------*/

class RPN
{
public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	float result(const std::string expression);

	class BadExpressionException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class DivisionBy0 : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class IncompleteExpressionException : public std::exception {
	public:
		virtual const char *what() const throw();
	}; 
};
