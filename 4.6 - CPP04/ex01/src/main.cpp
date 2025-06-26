#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	const	Animal *dog = new Dog();
	const	Animal *randomAnimal = new Animal();
	const	Animal *cat = new Cat();
	{
		std::cout << CORAL << "\n*----- TEST 1 : DOG -----*" << RESET << std::endl << std::endl;
		std::cout << "I am " << dog->getType() << " and here is the song of my people :" << std::endl;
		dog->makeSound();
		std::cout << "\n";
	}
	{
		std::cout << GREEN << "\n*----- TEST 2 : CAT -----*" << RESET << std::endl << std::endl;
		std::cout << "I am " << cat->getType() << " and here is the song of my people :" << std::endl;
		cat->makeSound();
		std::cout << "\n";
	}
	{
		std::cout << BLUE_BRIGHT << "\n*----- TEST 3 : RANDOM ANIMAL -----*" << RESET << std::endl << std::endl;
		std::cout << "I am " << randomAnimal->getType() << " and here is the song of my people :" << std::endl;
		randomAnimal->makeSound();
		std::cout << "\n";
	}
	delete dog;
	delete randomAnimal;
	delete cat;
	return (0);
}

/* Main fourni dans le sujet */

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound();
// 	j->makeSound();
// 	meta->makeSound();
// 	return 0;
// }
