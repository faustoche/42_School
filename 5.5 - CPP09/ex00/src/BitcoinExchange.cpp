#include "BitcoinExchange.hpp"

/*-------------- CONSTRUCTORS --------------*/

BitcoinExchange::BitcoinExchange() : _csvPath("data.csv"){}

BitcoinExchange::BitcoinExchange(std::string csvPath) : _csvPath(csvPath){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _csvPath(other._csvPath){
	this->_rateByDate = other._rateByDate;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other) {
		this->_csvPath = other._csvPath;
		this->_rateByDate = other._rateByDate;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

/*-------------- FUNCTIONS --------------*/

std::string BitcoinExchange::getCSVPath() const{
	return (this->_csvPath);
}

/*
** Load CSV files data in the rateByDate map
** First we open the CSV file (with c_str so it's compatible with ifstream) and throw exception if needed
** We clear the map in case it already has data
** Read and ignore the forst ligne (header -> data, value) and then we read the whole file
** Linestream: we extract easily 2 parts separated by a comma
** We read until the comma and keep it into date, then getline read the other part and keep the value
** If we don't have the two values, then we throw an error
** If everything alright, we convert to float and keep it in map
*/

void BitcoinExchange::chargingDatabase()
{
	std::ifstream databaseFile(this->_csvPath.c_str());
	if (!databaseFile.is_open())
		throw BitcoinExchange::CSVOpenException();
	this->_rateByDate.clear();
	std::string line;
	std::getline(databaseFile, line);
	while (std::getline(databaseFile, line))
	{
		std::stringstream lineStream(line);
		std::string date;
		std::string value;
		if (!std::getline(lineStream, date, ',') || !std::getline(lineStream, value))
		{
			std::cout << "Error: Malformed line: " << line << std::endl;
			continue ;
		}
		if (!isValidDate(date))
		{
			std::cout << "Error: Invalid date format (" << date << ")" << std::endl;
			continue ;
		}
		if (!isValidValue(value))
		{
			std::cout << "Error: Invalid value format (" << value << ")" << std::endl;
			continue ;
		}
		this->_rateByDate[date] = strToFloat(value);
	}
}

/*
** If the base is empty -> return 0
** Lower_bound return an iterator to the 1st date >= data or end if no data superior
** If no date was found, go back to the previous one 
** If it's the beginning and there is no older date -> return 0
** Return the date we found
*/

float BitcoinExchange::getRate(std::string date)
{
	if (this->_rateByDate.empty())
		return (0);
	std::map<std::string, float>::const_iterator it = this->_rateByDate.lower_bound(date);
	if (it == this->_rateByDate.end() || it->first != date)
	{
		if (it == this->_rateByDate.begin())
			return (0);
		--it;
	}
	return (it->second);
}

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/* Checking for february and if it's a leap year, or over/under logical date */

bool isValidDateLogic(int year, int month, int day)
{
	if (year < 2009)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && isLeapYear(year))
		daysInMonth[1] = 29;
	return (day >= 1 && day <= daysInMonth[month - 1]);
}

/* Check if the length is exactly 10 and if - are at the right position and every other characters are digits*/
/*
** counter help us to count the number of segment (YYYY-MM-JJ)
** We copy str in test_length to modify it with strtok
** the chain become char * to give it to strtok
** while we still have segment to read
** if it's the first one and not 4, return false
** and so on 
** if the counter is less or more than 3, then error
** struct tm is used for strptime
*/

bool isValidDate(const std::string& str)
{
	if (str.length() != 10)
		return (false);
	if (str[4] != '-' || str[7] != '-')
		return (false);
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	int year = std::atoi(str.substr(0, 4).c_str());
	int month = std::atoi(str.substr(5, 2).c_str());
	int day = std::atoi(str.substr(8, 2).c_str());
	return (isValidDateLogic(year, month, day));
}

bool isValidValue(const std::string& str)
{
	if (str.empty())
		return (false);
	std::stringstream string(str);
	float value;
	if (!(string >> value) || !string.eof())
		return (false);
	return (value >= 0);
}

float strToFloat(const std::string& str)
{
	std::stringstream string(str);
	float value;
	if (!(string >> value) || !string.eof())
		return (-1);
	return (value);
}

/*
** Opening the file and convert it for ifstream
** Check if opening works -> error or not
** line keep each line, we skip the header
** we use flag ignore if we see a mistake
** if no mistake, we convert in float, get the rate and give the result
** close the file then
*/

void processInputFile(const std::string& filename, BitcoinExchange& btc)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return ;
	}
	std::string line;
	bool firstLine = true;
	while (std::getline(file, line))
	{
		if (firstLine) {
			firstLine = false;
			continue ;
		}
		size_t pipe = line.find('|');
		if ((pipe == std::string::npos) || (line.find('|', pipe + 1) != std::string::npos))
		{
			std::cout << RED_BOLD << "Error: bad input => " << RESET << line << std::endl;
			continue ;
		}
		std::string datePart = line.substr(0, pipe);
		std::string valuePart = line.substr(pipe + 1);
		size_t dateStart = datePart.find_first_not_of(" \t");
		size_t dateEnd = datePart.find_last_not_of(" \t");
		if (dateStart == std::string::npos)
		{
			std::cout << RED_BOLD << "Error: bad input => " << RESET << line << std::endl;
			continue ;
		}
		std::string date = datePart.substr(dateStart, dateEnd - dateStart + 1);
		if (date.find(' ') != std::string::npos || date.find('\t') != std::string::npos)
		{
			std::cout << RED_BOLD << "Error: bad input => " << RESET << line << std::endl;
			continue ;
		}
		size_t valueStart = valuePart.find_first_not_of(" \t");
		size_t valueEnd = valuePart.find_last_not_of(" \t");
		if (valueStart == std::string::npos)
		{
			std::cout << RED_BOLD << "Error: bad input => " << RESET << line << std::endl;
			continue ;
		}
		std::string value = valuePart.substr(valueStart, valueEnd - valueStart + 1);
		if (valuePart.find('\t') != std::string::npos && !isValidValue(value))
		{
			std::cout << RED_BOLD << "Error: bad input => " << RESET << line << std::endl;
			continue ;
		}
		if (!isValidDate(date))
		{
			std::cout << RED_BOLD << "Error: bad input => " << RESET << date << std::endl;
			continue ;
		}
		if (!isValidValue(value))
		{
			std::cout << RED_BOLD << "Error: bad input => " << RESET << date << std::endl;
			continue ;
		}
		float floatValue = strToFloat(value);
		if (floatValue > 1000)
		{
			std::cout << RED_BOLD << "Error: bad input => " << RESET << date << std::endl;
			continue ;
		}
		float rate = btc.getRate(date);
		if (rate == 0)
		{
			std::cout << RED_BOLD << "Error: no data available for date " << RESET << date << std::endl;
			continue ;
		}
		float result = floatValue * rate;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
	file.close();
}

/*-------------- EXCEPTIONS --------------*/

const char*	BitcoinExchange::CSVOpenException::what(void) const throw()
{
	return ("Error: could not open file");
}