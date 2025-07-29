#include "BitcoinExchange.hpp"

/*-------------- CONSTRUCTORS --------------*/

BitcoinExchange::BitcoinExchange() : _database_path("data.csv"){}

BitcoinExchange::BitcoinExchange(std::string database_path) : _database_path(database_path){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database_path(other._database_path){
	this->_database = other._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
	this->_database_path = other._database_path;
	std::map<std::string, float>::iterator it;
	for (it = this->_database.begin(); it != this->_database.end(); it++){
		this->_database[it->first] = it->second;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

std::string BitcoinExchange::databasePath() const{
	return (this->_database_path);
}

void BitcoinExchange::constructDatabase(){
	std::string line;
	std::ifstream databaseFile(this->_database_path.c_str());
	if (!databaseFile.is_open())
		throw BitcoinExchange::WrongDataFile();
	this->_database.clear();
	int ctr = -1;
	while (getline(databaseFile, line)){
		ctr++;
		if (ctr == 0)
			continue;
		bool ignore = false;
		char *ptr;
		ptr = strtok((char *)line.c_str(), ",");
		std::string date;
		std::string value;
		while (ptr != NULL){
			if (date.empty())
				date = ptr;
			else if (value.empty())
				value = ptr;
			else
				ignore = true;
			ptr = strtok(NULL, ",");
		}
		if (!checkDateFormat(date) && !ignore){
			std::cerr << "Error: Incorrect date format (" << date << ")" << std::endl;
			ignore = true;
		}
		if (!checkValue(value) && !ignore){
			std::cerr << "Error: Incorrect value format (" << value << ")" << std::endl;
			ignore = true;
		}
		if (!ignore) {
			this->_database[date] = strToFloat(value);
		}
	}
	databaseFile.close();
	return;
}

float BitcoinExchange::getRate(std::string date)
{
	if (this->_database.size() == 0)
		return 0;

	if (this->_database.find(date) == this->_database.end()) {
		std::map<std::string, float>::iterator it;

		std::string best_date;

		for (it = this->_database.begin(); it != this->_database.end(); ++it) {
			int comp = date.compare(it->first);
			if (comp == -1)
			{
				if (it != this->_database.begin())
					it--;

				best_date = it->first;
				break;
			}
		}
		if (best_date.empty())
		{
			it--;
			best_date = it->first;
		}

		return this->_database[best_date];
	}
	return this->_database[date];
}

const char*	BitcoinExchange::WrongDataFile::what(void) const throw()
{
	return ("Error: could not open file");
}

bool checkDateFormat(std::string str)
{
	// Check field length
	std::string test_length = str;
	char *ptr;
	ptr = strtok((char *)test_length.c_str(), "-");

	int ctr = 0;
	while (ptr != NULL)
	{
		if (ctr == 0 && strlen(ptr) != 4)
			return false;
		else if (ctr > 0 && strlen(ptr) != 2)
			return false;

		ptr = strtok(NULL, "-");
		ctr++;
	}
	if (ctr != 3)
		return false;

	// Check format
	struct tm result;
	if(strptime(str.c_str(), "%Y-%m-%d", &result) == NULL)
		return false;

	return true;
}

bool checkValue(std::string str)
{
	std::stringstream s(str);
	float f;

	if (!(s >> f) || !s.eof())
		return false;

	if (f < 0)
		return false;
	return true;
}

float strToFloat(std::string str)
{
	std::stringstream s(str);
	float f;

	if (!(s >> f) || !s.eof())
		return -1;

	return f;
}

