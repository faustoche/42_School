#include "AMateria.hpp"

/*-------------- CONSTRUCTORS --------------*/

AMateria::AMateria() : type("no type yet"){
}

AMateria::AMateria(std::string const &type) : type(type){
}

AMateria::AMateria(const AMateria &other){
}

AMateria &AMateria::operator=(const AMateria &other){
	if (this != &other)
		this->type = other.type;
	return (*this);
}

AMateria::~AMateria(){
	std::cout << "[AMATERIA] Destructor called" << std::endl;
}

/*-------------- GETTER --------------*/

std::string const &AMateria::getType() const{
	return (this->type);
}

/*-------------- FUNCTIONS --------------*/

void	AMateria::use(ICharacter &target){
	//renvois ice ou cure
}

