#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		if (ac > 2)
			std::cout << "Error: too many arguments." << std::endl;
		else
			std::cout << "Error: could not open file." << std::endl;
		return (1);
	}

	BitcoinExchange btc("input/data.csv");

	try
	{
		btc.chargingDatabase();
	}
	catch (BitcoinExchange::CSVOpenException &e)
	{
		std::cout << e.what() << " (" << btc.getCSVPath() << ")" << std::endl;
		return (1);
	}

	processInputFile(av[1], btc);
	return (0);
}
