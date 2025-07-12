#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

/*-------------- INCLUDES --------------*/

#include <iomanip>
#include <iostream>
#include <climits>
#include <cmath>
#include "colors.hpp"
#include <cerrno>
#include <cfloat>

/*---------------- CLASS ---------------*/

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

public:
	static void convert(std::string const str);
};

#endif