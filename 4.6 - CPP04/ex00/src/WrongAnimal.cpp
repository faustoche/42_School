#include "../includes/WrongAnimal.hpp"

/*-------------- CONSTRUCTORS --------------*/

WrongAnimal::WrongAnimal(void) : type("Animal"){
	std::cout << "[WrongAnimal] Default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : type(type){
	std::cout << "[WrongAnimal] Constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
	if (this != &other){
		this->type = other.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "[WrongAnimal] Destructor called." << std::endl;
}

/*-------------- GETTERS --------------*/

std::string	WrongAnimal::getType(void) const {
	return (this->type);
}

/*-------------- FUNCTIONS --------------*/

void	WrongAnimal::makeSound() const{
	std::cout << "Am I really an animal ? It does sound wrong, right?" << std::endl;
}