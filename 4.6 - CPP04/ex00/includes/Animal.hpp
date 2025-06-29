#ifndef		ANIMAL_HPP
# define	ANIMAL_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>
#include "colors.hpp"

/*-------------- CLASSES --------------*/

/*
** Variable type pour stocker le type d'animal (dog ou cat)
** On utilise protected pour que les classes héritantes puissent accéder à type
** Deux constructeurs de base : un sans paramètre pour l'appel Animal a
** Un avec paramètres pour quand on fait Animal a("Dog")
** Le destructeur doit impérativement ëtre en virtuel pour le polymorphisme.
** Sans le destructeur en virtuel, il y aurait des fuites de mémoires
** Le getter est en const car il ne modifie par l'objet, il le récupère
** makeSound est en virtuel et donc on ne peut pas la redéfinir dans les classes héritntes
*/

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual	~Animal();

	std::string getType(void) const;
	virtual void	makeSound() const;
};

#endif