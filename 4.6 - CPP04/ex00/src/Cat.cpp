#include "Animal.hpp"

// Est-ce que je peux utiliser le constructeur pour définir le type d'animal?

/*-------------- CONSTRUCTORS --------------*/

Cat::Cat(){
	this->type = "Cat";
	std::cout << "[CAT] Constructor called." << std::endl;
}

Cat::Cat(const Cat &other){
	*this = other;
}

Cat &Cat::operator=(const Cat &other){
	if (this != &other){
		this->type = other.type;
	}
	return (*this);
}

Cat::~Cat(){
	std::cout << "[CAT] Destructor called." << std::endl;
}

/*-------------- FUNCTIONS --------------*/