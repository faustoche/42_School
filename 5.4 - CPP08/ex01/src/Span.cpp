#include "Span.hpp"

/*-------------- CONSTRUCTORS --------------*/

Span::Span(){}

Span::Span(unsigned int n) : _maxSize(n), _numbers(){}

Span::Span(const Span &other){
	this->_maxSize = other._maxSize;
	this->_numbers = other._numbers;
}

Span &Span::operator=(const Span &other){
	if (this != &other){
		this->_maxSize = other._maxSize;
		this->_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span(){}

int &Span::operator[](unsigned int index){
	if (index >= _numbers.size()){
		throw (std::out_of_range("Index is out of range"));
	}
	return (_numbers[index]);
}

/*-------------- FUNCTIONS --------------*/

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw (SpanFullException());
	else
		_numbers.push_back(number);
}

int Span::shortestSpan()
{
	std::vector<int> sorted_number;
	if (_numbers.size() < 2)
		throw (NotEnoughNumbersException());
	else {
		sorted_number = _numbers;
		std::sort(sorted_number.begin(), sorted_number.end());
	}
	int minSpan = INT_MAX;
	for (unsigned int i = 1; i < sorted_number.size(); i++){
		int currentDiff = sorted_number[i] - sorted_number[i - 1];
		if (currentDiff < minSpan)
			minSpan = currentDiff;
	}
	return (minSpan);
}

int Span::longestSpan()
{
	int diff = 0;
	if (_numbers.size() < 2)
		throw (NotEnoughNumbersException());
	else {
		std::sort(_numbers.begin(), _numbers.end());
	}
	int minNb = _numbers.front();
	int maxNb = _numbers.back();
	return (diff = maxNb - minNb);
}