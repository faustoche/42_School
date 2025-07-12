#include "Data.hpp"

/*-------------- CONSTRUCTORS --------------*/

Data::Data() : _type("animal"), _member(4){

}

Data::Data(const std::string type, const int member) : _type(type), _member(member){

}

Data::Data(const Data &other) : _type(other._type), _member(other._member){
	(void)other;
}

Data &Data::operator=(const Data &other){
	(void)other;
	return (*this);
}

Data::~Data(){}
