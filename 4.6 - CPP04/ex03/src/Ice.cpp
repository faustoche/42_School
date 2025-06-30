#include "Ice.hpp"
#include "../includes/ICharacter.hpp"

/*-------------- CONSTRUCTORS --------------*/

Ice::Ice(){
	type = "ice";
}

Ice::Ice(const Ice &other) : AMateria(other){
}

Ice &Ice::operator=(const Ice &other){
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Ice::~Ice(){
	//std::cout << "[ICE] Destructor called" << std::endl;
}

/*-------------- FUNCTIONS --------------*/

void	Ice::use(ICharacter &target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice	*Ice::clone() const{
	return (new Ice(*this));
}