#include "Ice.hpp"

/*-------------- CONSTRUCTORS --------------*/

Ice::Ice(){
}

Ice::Ice(const Ice &other){
	*this = other;
}

Ice &Ice::operator=(const Ice &other){
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Ice::~Ice(){
	std::cout << "[ICE] Destructor called" << std::endl;
}

/*-------------- FUNCTIONS --------------*/

void	Ice::use(ICharacter &target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
