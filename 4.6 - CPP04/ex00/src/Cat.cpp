#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"

/*-------------- CONSTRUCTORS --------------*/

/*
** On rajoute Animal("Cat") pour appeler le constructeur d'animal avec le type cat
** On appelle le constructeur d'animal et ensuite le corps du constructeur de cat s'execute
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