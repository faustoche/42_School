#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Brain.hpp"

// int	main()
// {
// 	const	Animal *dog = new Dog();
// 	const	Animal *randomAnimal = new Animal();
// 	const	Animal *cat = new Cat();
// 	const	WrongAnimal	*randomWrongAnimal = new WrongAnimal();
// 	const	WrongAnimal	*badCat = new WrongCat();
// 	{
// 		std::cout << CORAL << "\n*----- TEST 1 : DOG -----*" << RESET << std::endl << std::endl;
// 		std::cout << "I am " << dog->getType() << " and here is the song of my people :" << std::endl;
// 		dog->makeSound();
// 		std::cout << "\n";
// 	}
// 	{
// 		std::cout << GREEN << "\n*----- TEST 2 : CAT -----*" << RESET << std::endl << std::endl;
// 		std::cout << "I am " << cat->getType() << " and here is the song of my people :" << std::endl;
// 		cat->makeSound();
// 		std::cout << "\n";
// 	}
// 	{
// 		std::cout << BLUE_BRIGHT << "\n*----- TEST 3 : RANDOM ANIMAL -----*" << RESET << std::endl << std::endl;
// 		std::cout << "I am " << randomAnimal->getType() << " and here is the song of my people :" << std::endl;
// 		randomAnimal->makeSound();
// 		std::cout << "\n";
// 	}
// 	{
// 		std::cout << PINK << "\n*----- TEST 4 : WRONG ANIMAL -----*" << RESET << std::endl << std::endl;
// 		std::cout << "I am " << randomWrongAnimal->getType() << " and here is the song of my people :" << std::endl;
// 		randomWrongAnimal->makeSound();
// 		std::cout << "\n";
// 	}
// 	{
// 		std::cout << YELLOW << "\n*----- TEST 5 : WRONG CAT -----*" << RESET << std::endl << std::endl;
// 		std::cout << "I am " << badCat->getType() << " and here is the song of my people :" << std::endl;
// 		badCat->makeSound();
// 		std::cout << "\n";
// 	}
// 	delete dog;
// 	delete randomAnimal;
// 	delete cat;
// 	delete randomWrongAnimal;
// 	delete badCat;
// 	return (0);
// }

/* Main fourni dans le sujet */

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;
return 0;
}