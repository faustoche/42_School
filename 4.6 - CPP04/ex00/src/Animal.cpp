#include "Animal.hpp"

/*-------------- CONSTRUCTORS --------------*/

Animal::Animal(const std::string &type) : type(type){
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

/*-------------- FUNCTIONS --------------*/

void	Animal::makeSound() const{
	std::cout << "Am I supposed to know this animal ?" << std::endl;
}