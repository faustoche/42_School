#include "../includes/Animal.hpp"

/*-------------- CONSTRUCTORS --------------*/

/* On initialise avec le type animal */

Animal::Animal(void) : type("Animal"){
	std::cout << "[ANIMAL] Default constructor called." << std::endl;
}

/* On initialise le membre type avec le paramètre type */

Animal::Animal(const std::string type) : type(type){
	std::cout << "[ANIMAL] Constructor called." << std::endl;
}

Animal::Animal(const Animal &other){
	*this = other;
}

Animal &Animal::operator=(const Animal &other){
	if (this != &other){
		this->type = other.type;
	}
	return (*this);
}

Animal::~Animal(){
	std::cout << "[ANIMAL] Destructor called." << std::endl;
}

/*-------------- GETTERS --------------*/

std::string	Animal::getType(void) const {
	return (this->type);
}

/*-------------- FUNCTIONS --------------*/

void	Animal::makeSound() const{
	std::cout << "Am I supposed to know this animal ?" << std::endl;
}