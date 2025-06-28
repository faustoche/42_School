#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

int	main()
{
	//AAnimal	a;
	Cat	moulinette;
	Dog	chieng;
	AAnimal *animal1 = new Dog();
	AAnimal *animal2 = new Cat();

	//a.makeSound();
	moulinette.makeSound();
	chieng.makeSound();
	animal1->makeSound();
	animal2->makeSound();

	delete animal1;
	delete animal2;
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