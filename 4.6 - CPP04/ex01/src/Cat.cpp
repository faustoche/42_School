#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"

/*-------------- CONSTRUCTORS --------------*/

/* 
** Chaque CAT doit avoir un nouveau brain à la création
** On alloue un nouveau brain dans la heap qu'on delete dans le destructeur
** 
*/

Cat::Cat() : Animal("Cat"){
	this->brain = new Brain();
	std::cout << RED << "[CAT] " << RESET << "Constructor called." << std::endl;
}

/* 
** On obtiens ici l'objet braim et on alloue ce nouveau brain
** On ne peut pas faire brain = other.brain car ça serait une copie superficielle
** Les différents cat partageraient le méme brain, et on ne peux odnc pas les détruitre
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