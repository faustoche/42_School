#ifndef DATA_HPP
#define DATA_HPP

/*-------------- INCLUDES --------------*/

#include "Serializer.hpp"

/*-------------- CLASS --------------*/

class Data
{
public:
	Data();
	Data(const std::string type, const int member);
	Data(const Data &other);
	Data &operator=(const Data &other);
	~Data();

private:
	const std::string _type;
	const int _member;
};

#endif