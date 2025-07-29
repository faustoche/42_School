#include "rpn.hpp"

rpn::rpn(){}
rpn::~rpn(){}

rpn::rpn(const rpn &other){
	*this = other;
}

rpn &rpn::operator=(const rpn &other){
	(void)other;
	return (*this);
}

float rpn::result(const std::string expression)
{
	std::list<float> elems;

	bool is_space = false;
	for (std::string::const_iterator it = expression.begin(); it != expression.end(); it++)
	{
		if (*it != ' ' && !is_space && elems.size() != 0)
			throw rpn::BadExpressionException();
		is_space = *it == ' ';
		if (*it == ' ')
			continue;
		if (isdigit(*it))
			elems.push_back(*it - '0');
		else
		{
			if (elems.size() < 2)
				throw rpn::BadExpressionException();
			float l1 = elems.back();
			elems.pop_back();
			float l2 = elems.back();
			elems.pop_back();
			switch (*it)
			{
			case '+':
				elems.push_back(l2 + l1);
				break;
			case '-':
				elems.push_back(l2 - l1);
				break;
			case '/':
				if (l1 == 0)
					throw rpn::DivisionBy0();
				elems.push_back(l2 / l1);
				break;
			case '*':
				elems.push_back(l2 * l1);
				break;
			default:
				throw rpn::BadExpressionException();
				break;
			}
		}
	}
	if (elems.size() != 1)
		throw rpn::RemainingTerms();

	return elems.front();
}

const char*	rpn::BadExpressionException::what(void) const throw()
{
	return ("Error: malformed expression");
}

const char*	rpn::DivisionBy0::what(void) const throw()
{
	return ("Error: division by 0 is not allowed");
}

const char*	rpn::RemainingTerms::what(void) const throw()
{
	return ("Error: remainging terms");
}
