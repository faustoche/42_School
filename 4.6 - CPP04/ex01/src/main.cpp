#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Brain.hpp"

int	main()
{
	for (int i = 0; i < 100; i++){
		new Dog[50];
		new Cat[50];
		std::cout << "New Animal " << i << " created." << std::endl;
	}
	for (int i = 0; i < 50)
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