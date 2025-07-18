#include "BitcoinExchange.hpp"

/*-------------- CONSTRUCTORS --------------*/

DatesPrices::DatesPrices(){}

DatesPrices::DatesPrices(std::string database) : _database(database){

}

DatesPrices::DatesPrices(const DatesPrices &other){
	this->_database = other._database;
}

DatesPrices &DatesPrices::operator=(const DatesPrices &other){
	if (this != &other){
		this->_database = other._database;
	}
	return (*this);
}

DatesPrices::~DatesPrices(){}

