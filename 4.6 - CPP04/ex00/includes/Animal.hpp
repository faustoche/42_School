#ifndef		ANIMAL_HPP
# define	ANIMAP_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>

/*-------------- DEFINES --------------*/

#define RESET   "\033[0m"
#define WHITE   "\033[1;97m"
#define FUCHSIA "\033[1;38;5;201m"
#define BLUE_BRIGHT "\033[1;94m"
#define GREEN       "\033[1;32m"
#define MAGENTA     "\033[1;35m"
#define CYAN        "\033[1;36m"
#define RED "\033[1;91m"
#define YELLOW "\033[1;93m"
#define ORANGE      "\033[1;38;5;208m"
#define PINK        "\033[1;38;5;205m"
#define TURQUOISE   "\033[1;38;5;45m"
#define GOLD        "\033[1;38;5;220m"
#define CORAL       "\033[1;38;5;203m"

/*-------------- CLASSES --------------*/

class Animal
{
protected:
	std::string type;

public:
	Animal(); // Constructeur par défault
	Animal(const std::string type);
	Animal(const Animal &other); // Constructeur de recopie
	Animal &operator=(const Animal &other); // Constructeur d'opération
	~Animal(); // Destructeur

	std::string &getType();
	void	makeSound();
};

class Dog : public Animal
{
private:
	

public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();
};

class Cat : public Animal
{
private:
	

public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();
};


#endif