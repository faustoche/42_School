#ifndef SPAN_HPP
#define SPAN_HPP

/*-------------- INCLUDES --------------*/

#include "colors.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdexcept>

/*-------------- CLASS --------------*/

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

public:
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void	addNumber(int number);
	int		shortestSpan();
	int		longestSpan();

	template<typename InputIterator>
	void	addNumber(InputIterator begin, InputIterator end)
	{
		size_t rangeSize = std::distance(begin, end);
		if (_numbers.size() + rangeSize > _maxSize)
			throw (SpanFullException());
		_numbers.insert(_numbers.end(), begin, end);
	};

	class SpanFullException : public std::exception
	{
		public:
			virtual const char *what() const throw(){
				return ("Container is already full");
			}
	};

	class NotEnoughNumbersException : public std::exception
	{
		public:
			virtual const char *what() const throw(){
				return ("Need at least 2 numbers");
			}
	};

	int &operator[](unsigned int index);
};

#endif