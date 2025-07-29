#pragma once

#include <string>
#include <list>
#include <iostream>

class rpn
{
public:
	rpn();
	rpn(const rpn &other);
	rpn &operator=(const rpn &other);
	~rpn();

	float result(const std::string expression);

	class BadExpressionException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class DivisionBy0 : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class RemainingTerms : public std::exception {
	public:
		virtual const char *what() const throw();
	}; 
};
