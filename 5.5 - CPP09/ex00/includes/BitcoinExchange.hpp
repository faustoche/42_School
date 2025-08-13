#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

/*-------------- INCLUDES --------------*/

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include "colors.hpp"


/*-------------- CLASS --------------*/

class BitcoinExchange
{
private:
	std::string _csvPath;
	std::map<std::string, float> _rateByDate;

public:
	BitcoinExchange();
	BitcoinExchange(const std::string database_path);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void chargingDatabase();
	std::string getCSVPath(void) const;
	float getRate(std::string date);

	class CSVOpenException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

bool isValidDate(const std::string& str);
bool isValidValue(const std::string& str);
bool isLeapYear(int year);
bool isValidDateLogic(int year, int month, int day);
float strToFloat(const std::string& str);
void processInputFile(const std::string& filename, BitcoinExchange& btc);

#endif