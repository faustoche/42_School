#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Brain.hpp"

int	main()
{
	Animal	*pets[100];
	for (int i = 0; i < 100; i++){
		if (i < 50)
			pets[i] = new Cat();
		else
			pets[i] = new Dog();
	}
	std::cout << PINK << "-----------------------------" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		delete pets[i];
	return (0);
}


/* Main fourni dans le sujet */

// int main()
// {
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// delete j;//should not create a leak
// delete i;
// return 0;
// }