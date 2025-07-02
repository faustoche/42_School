#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"

/*-------------- CONSTRUCTORS --------------*/

/* 
** Each Cat need to have a new brain when created
** We allocate a new brain in the heap that we delete in the destructor
*/

Cat::Cat() : Animal("Cat"){
	this->brain = new Brain();
	std::cout << RED << "[CAT] " << RESET << "Constructor called." << std::endl;
}

/* 
** We get the brain object and allocate this new brain
** We cannot do brain = other.brain, it would be a superficial copy
** Differents cats would share the same brain, and it will make problem to destroy them
*/

Cat::Cat(const Cat &other) : Animal(other){
	this->brain = new Brain(*other.brain);
	std::cout << RED << "[CAT] " << RESET << "Copy constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &other){
	if (this != &other){
		Animal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat(){
	delete brain;
	std::cout << RED << "[CAT] " << RESET << "Destructor called." << std::endl;
}

/*-------------- FUNCTIONS --------------*/

void	Cat::makeSound() const {
	std::cout << "I am a world leader. Meow" << std::endl;
}

Brain	*Cat::haveBrain(){
	return (this->brain);
}