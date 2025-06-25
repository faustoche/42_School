#include "Animal.hpp"
#include "Cat.hpp"

/*-------------- CONSTRUCTORS --------------*/

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
	std::cout << "I am a world leader. I am Moulinette. Meow" << std::endl;
}