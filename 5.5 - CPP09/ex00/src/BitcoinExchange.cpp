#include "BitcoinExchange.hpp"

/*-------------- CONSTRUCTORS --------------*/

BitcoinExchange::BitcoinExchange() : _csvPath("data.csv"){}

BitcoinExchange::BitcoinExchange(std::string csvPath) : _csvPath(csvPath){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _csvPath(other._csvPath){
	this->_rateByDate = other._rateByDate;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
	this->_csvPath = other._csvPath;
	std::map<std::string, float>::iterator it;
	for (it = this->_rateByDate.begin(); it != this->_rateByDate.end(); it++){
		this->_rateByDate[it->first] = it->second;
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

bool isValidDate(std::string str)
{
	std::string test_length = str;
	char *ptr;
	ptr = strtok((char *)test_length.c_str(), "-");
	int counter = 0;
	while (ptr != NULL)
	{
		if (counter == 0 && strlen(ptr) != 4)
			return (false);
		else if (counter > 0 && strlen(ptr) != 2)
			return (false);
		ptr = strtok(NULL, "-");
		counter++;
	}
	if (counter != 3)
		return (false);
	struct tm result;
	if(strptime(str.c_str(), "%Y-%m-%d", &result) == NULL)
		return (false);
	return (true);
}

/*
** convert the chain as a float
** we read. If we can't -> false
*/

bool isValidValue(std::string str)
{
	std::stringstream string(str);
	float value;
	if (!(string >> value) || !string.eof())
		return (false);
	if (value < 0)
		return (false);
	return (true);
}

float strToFloat(std::string str)
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
		std::cout << "Error: could not open file (" << filename << ")" << std::endl;
		return ;
	}
	std::string line;
	int lineNumber = -1;
	while (std::getline(file, line))
	{
		lineNumber++;
		if (lineNumber == 0)
			continue ;
		bool ignore = false;
		std::string date;
		std::string value;
		char *token = std::strtok(const_cast<char*>(line.c_str()), " | ");
		while (token != NULL)
		{
			if (date.empty())
				date = token;
			else if (value.empty())
				value = token;
			else
				ignore = true;
			token = std::strtok(NULL, " | ");
		}
		if (!isValidDate(date) && !ignore)
		{
			std::cout << "Error: Incorrect date format (" << date << ")" << std::endl;
			ignore = true;
		}
		if (!isValidValue(value) && !ignore)
		{
			std::cout << "Error: Incorrect value format (" << value << ")" << std::endl;
			ignore = true;
		}
		if (!ignore && strToFloat(value) > 1000)
		{
			std::cout << "Error: Too large a number (" << value << ")" << std::endl;
			ignore = true;
		}
		if (!ignore)
		{
			float result = strToFloat(value) * btc.getRate(date);
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
	}
	file.close();
}

/*-------------- EXCEPTIONS --------------*/

const char*	BitcoinExchange::CSVOpenException::what(void) const throw()
{
	return ("Error: could not open file");
}
