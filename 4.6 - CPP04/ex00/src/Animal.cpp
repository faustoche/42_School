#include "Animal.hpp"

/*-------------- CONSTRUCTORS --------------*/

Animal::Animal(){
}

Animal::Animal() : type("Animal"){
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