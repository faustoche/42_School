#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*-------------- CONSTRUCTORS --------------*/

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
	std::cout << "[WrongCat] Constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other.type){
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other){
	if (this != &other){
		this->type = other.type;
	}
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout << "[WrongCat] Destructor called." << std::endl;
}

/*-------------- FUNCTIONS --------------*/

void	WrongCat::makeSound() const {
	std::cout << "I am a world leader. I am Moulinette. Meow" << std::endl;
}