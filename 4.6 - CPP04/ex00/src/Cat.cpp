#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"

/*-------------- CONSTRUCTORS --------------*/

/*
** Adding Animal("Cat") to call the animal constructor with the type cat
** Calling animal constructor and then content of cat constructor is executed
*/

Cat::Cat() : Animal("Cat"){
	std::cout << "[CAT] Constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other.type){
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

void	Cat::makeSound() const {
	std::cout << "I am a world leader. Meow" << std::endl;
}