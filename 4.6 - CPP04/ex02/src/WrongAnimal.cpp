#include "../includes/WrongAnimal.hpp"

/*-------------- CONSTRUCTORS --------------*/

WrongAnimal::WrongAnimal(void){
	std::cout << "[WrongAnimal] Default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(){
	std::cout << "[WrongAnimal] Constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
	(void)other;
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "[WrongAnimal] Destructor called." << std::endl;
}

/*-------------- FUNCTIONS --------------*/

void	WrongAnimal::makeSound() const{
	std::cout << "Am I really an animal ? It does sound wrong, right?" << std::endl;
}