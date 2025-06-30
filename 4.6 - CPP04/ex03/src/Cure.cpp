#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"

/*-------------- CONSTRUCTORS --------------*/

Cure::Cure(){
	type = "cure";
}

Cure::Cure(const Cure &other){
	(void)other;
	return ;
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
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure	*Cure::clone() const{
	return (new Cure(*this));
}