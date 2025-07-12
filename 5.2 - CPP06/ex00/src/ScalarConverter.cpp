#include "ScalarConverter.hpp"

/*-------------- CONSTRUCTORS --------------*/

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
	(void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

/*-------------- FUNCTIONS --------------*/

enum TYPE {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
};

static bool isInt(std::string str){
	if (str.empty())
		return (false);
	int i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	for (; str[i]; i++){
		if (!isdigit(str[i]))
			return (false);
	}
	std::string digit = str;
	if (digit[0] == '+' || digit[0] == '-')
		digit = digit.substr(1);
	if (digit.length() > 10)
		return (false);
	return (true);
}

static void convertDouble(std::string str){
	errno = 0;
	char* end;
	double dbl = strtod(str.c_str(), &end);
	if (*end != '\0'){
		std::cout << WHITE << "  char: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << "   int: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << " float: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << "double: " << RED << "Impossible" << RESET << std::endl;
		return;
	}
	if (errno == ERANGE) {
		std::cout << WHITE << "  char: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << "   int: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << " float: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << "double: " << RED << "Impossible" << RESET << std::endl;
		return;
	}
	if (dbl != dbl || dbl == std::numeric_limits<double>::infinity() || dbl == -std::numeric_limits<double>::infinity()){
		std::cout << WHITE << "  char: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE <<"   int: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE <<" float: " << RESET << static_cast<float>(dbl) << "f" << std::endl;
		std::cout << WHITE <<"double: " << RESET << dbl << std::endl;
		return ;
	}
	if (dbl < INT_MIN || dbl > INT_MAX) {
		std::cout << WHITE << "  char: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << "   int: " << RED << "Impossible" << RESET << std::endl;
	} else {
		int i = static_cast<int>(dbl);
		if ((i < 0 || i > 127))
			std::cout << WHITE << "  char: " << RED << "Impossible" << RESET << std::endl;
		else if (!isprint(i))
			std::cout << WHITE << "  char: " << RED << "Non displayable" << RESET << std::endl;
		else
			std::cout << WHITE << "  char: '" << RESET << static_cast<char>(i) << "'" << std::endl; 
		std::cout << WHITE << "   int: " << RESET << i << std::endl;
	}
	if (dbl < -FLT_MAX || dbl > FLT_MAX) {
		std::cout << WHITE << " float: " << RED << "Impossible" << RESET << std::endl;
	} else {
		std::cout << WHITE << " float: " << RESET << static_cast<float>(dbl) << "f" << std::endl;
	}
	
	std::cout << WHITE << "double: " << RESET << dbl << std::endl;
}

static void convertFloat(std::string str){
	errno = 0;
	char* end;
	float flt = strtof(str.c_str(), &end);
	if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')){
		std::cout << WHITE << "  char: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << "   int: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << " float: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << "double: " << RED << "Impossible" << RESET << std::endl;
		return;
	}
	if (errno == ERANGE) {
		std::cout << WHITE << "  char: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << "   int: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << " float: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << "double: " << RED << "Impossible" << RESET << std::endl;
		return;
	}
	if (flt != flt || flt == std::numeric_limits<float>::infinity() || flt == -std::numeric_limits<float>::infinity()){
		std::cout << WHITE << "  char: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << "   int: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << " float: " << RESET << flt << "f" << std::endl;
		std::cout << WHITE << "double: " << RESET << static_cast<double>(flt) << std::endl;
		return;
	}
	if (flt < INT_MIN || flt > INT_MAX) {
		std::cout << WHITE << "  char: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << "   int: " << RED << "Impossible" << RESET << std::endl;
	} else {
		int i = static_cast<int>(flt);
		if ((i < 0 || i > 127))
			std::cout << WHITE << "  char: " << RED << "Impossible" << RESET << std::endl;
		else if (!isprint(i))
			std::cout << WHITE << "  char: " << RED << "Non displayable" << RESET << std::endl;
		else
			std::cout << WHITE << "  char: '" << RESET << static_cast<char>(i) << "'" << std::endl;
		std::cout << WHITE << "   int: " << RESET << i << std::endl;
	}
	std::cout << WHITE << " float: " << RESET << flt << "f" << std::endl;
	std::cout << WHITE << "double: " << RESET << static_cast<double>(flt) << std::endl;
}

static void convertInt(std::string str){
	errno = 0;
	char *endptr;
	long nb = strtol(str.c_str(), &endptr, 10);
	if (*endptr != '\0' || errno == ERANGE || nb < INT_MIN || nb > INT_MAX){
		std::cout << WHITE << "  char: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << "   int: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << " float: " << RED << "Impossible" << RESET << std::endl;
		std::cout << WHITE << "double: " << RED << "Impossible" << RESET << std::endl;
		return;
	}
	int i = static_cast<int>(nb);
	if (i < 0 || i > 127)
		std::cout << WHITE << "  char: " << RED << "Impossible" << RESET << std::endl;
	else if (!isprint(i))
		std::cout << WHITE << "  char: " << RED << "Non displayable" << RESET << std::endl;
	else
		std::cout << WHITE << "  char: '" << RESET << static_cast<char>(i) << "'" << std::endl;
	std::cout << WHITE << "   int: " << RESET << i << std::endl;
	std::cout << WHITE << " float: " << RESET << static_cast<float>(nb) << "f" << std::endl;
	std::cout << WHITE << "double: " << RESET << static_cast<double>(nb) << std::endl;
}

static void convertChar(char c){
	if (!isprint(c))
		std::cout << WHITE << "  char: " << RED << "Impossible" << RESET << std::endl;
	else
		std::cout << WHITE << "  char: '" << RESET << c << "'" << std::endl;
	std::cout << WHITE << "   int: " << RESET << static_cast<int>(c) << std::endl;
	std::cout << WHITE << " float: " << RESET << static_cast<float>(c) << "f" << std::endl;
	std::cout << WHITE << "double: " << RESET << static_cast<double>(c) << std::endl;
}

TYPE getType(std::string str){
	if (str.empty())
		return (NONE);
	if (str.length() == 1 && !isdigit(str[0]) && isascii(str[0])){
			return (CHAR);
	}
	if (str == "+inf" || str == "-inf" || str == "inf" || str == "nan")
		return (DOUBLE);
	if (str == "+inff" || str == "-inff" || str == "inff" || str == "nanf")
		return (FLOAT);
	if (str.length() > 1 && str[str.length() - 1] == 'f') {
		std::string temp = str.substr(0, str.length() - 1);
		char *endptr;
		errno = 0;
		strtof(temp.c_str(), &endptr);
		if (*endptr == '\0' && errno != ERANGE)
			return (FLOAT);
	}
	if (str.find('.') != std::string::npos) {
		char *endptr;
		errno = 0;
		strtod(str.c_str(), &endptr);
		if (*endptr == '\0' && errno != ERANGE)
			return (DOUBLE);
	}
	if (isInt(str))
	{
		char *endptr;
		errno = 0;
		long value = strtol(str.c_str(), &endptr, 10);
		if (errno == ERANGE || value < INT_MIN || value > INT_MAX)
			return (DOUBLE);
		return (INT);
	}
	char *endptr;
	errno = 0;
	strtod(str.c_str(), &endptr);
	if (*endptr == '\0' && errno != ERANGE)
		return (DOUBLE);
	
	return (NONE);
}


void ScalarConverter::convert(std::string const str){
	std::cout << std::fixed << std::setprecision(1);
	switch (getType(str)){
		case CHAR:
			convertChar(str[0]);
			break;
		case INT:
			convertInt(str);
			break;
		case FLOAT:
			convertFloat(str);
			break;
		case DOUBLE:
			convertDouble(str);
			break;
		default:
			std::cout << WHITE << "  char: " << RED << "Impossible" << RESET << std::endl;
			std::cout << WHITE << "   int: " << RED << "Impossible" << RESET << std::endl;
			std::cout << WHITE << " float: " << RED << "Impossible" << RESET << std::endl;
			std::cout << WHITE << "double: " << RED << "Impossible" << RESET << std::endl;
			break;
	}
}
