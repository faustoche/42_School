#include "Cure.hpp"

/*-------------- CONSTRUCTORS --------------*/

Cure::Cure(){
}

Cure::Cure(const Cure &other){
	*this = other;
}

Cure &Cure::operator=(const Cure &other){
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Cure::~Cure(){
	std::cout << "[CURE] Destructor called" << std::endl;
}

/*-------------- FUNCTIONS --------------*/

void	Cure::use(ICharacter &target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
