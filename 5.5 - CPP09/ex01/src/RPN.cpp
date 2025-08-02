#include "RPN.hpp"

/*-------------- CONSTRUCTORS --------------*/

RPN::RPN(){}
RPN::~RPN(){}

RPN::RPN(const RPN &other){
	*this = other;
}

RPN &RPN::operator=(const RPN &other){
	(void)other;
	return (*this);
}

/*-------------- FUNCTIONS --------------*/

/*
** We are using a stack list as last in first out
** is space helps to check if numbers or operators are with space or not
** if not a space and at least 1 element
** if its a number, conversion in int and keep it in the pile
** at least 2 elements needed to do operation
** we get the last 2 element of operators stack, remove them from the pile
** we add back result in the pile
*/

float RPN::result(const std::string expression)
{
	std::list<float> elements;

	bool is_space = false;
	for (std::string::const_iterator it = expression.begin(); it != expression.end(); it++)
	{
		if (*it != ' ' && !is_space && elements.size() != 0)
			throw (RPN::BadExpressionException());
		is_space = *it == ' ';
		if (*it == ' ')
			continue ;
		if (isdigit(*it))
			elements.push_back(*it - '0');
		else
		{
			if (elements.size() < 2)
				throw (RPN::BadExpressionException());
			float l1 = elements.back();
			elements.pop_back();
			float l2 = elements.back();
			elements.pop_back();
			switch (*it)
			{
			case '+':
				elements.push_back(l2 + l1);
				break ;
			case '-':
				elements.push_back(l2 - l1);
				break ;
			case '/':
				if (l1 == 0)
					throw (RPN::DivisionBy0());
				elements.push_back(l2 / l1);
				break ;
			case '*':
				elements.push_back(l2 * l1);
				break ;
			default:
				throw (RPN::BadExpressionException());
				break ;
			}
		}
	}
	if (elements.size() != 1)
		throw (RPN::IncompleteExpressionException());
	return (elements.front());
}

/*-------------- EXCEPTIONS --------------*/

const char*	RPN::BadExpressionException::what(void) const throw()
{
	return ("Error: bad expression");
}

const char*	RPN::DivisionBy0::what(void) const throw()
{
	return ("Error: division by 0 is not allowed");
}

const char*	RPN::IncompleteExpressionException::what(void) const throw()
{
	return ("Error: incomplet expression");
}
