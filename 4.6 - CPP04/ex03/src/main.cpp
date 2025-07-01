#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

void	PrintMateria(const Character &character)
{
	std::cout << "Inventory of " << character.getName() << std::endl;
	for (int i = 0; i < 4; i++){
		std::cout << i << " : ";
		character.use(i, character);
	}
}

int	main(void)
{
	std::cout << PINK << "\n======= TEST 1 : BASIC SHIT =======" << RESET << std::endl << std::endl;
	Ice* ice = new Ice();
	Cure* cure = new Cure();
	PrintMateria()
	std::cout << "Ice type: " << ice->getType() << std::endl;
	std::cout << "Cure type: " << cure->getType() << std::endl;

	std::cout << PINK << "\n======= TEST 2 : CLONING TEST =======" << RESET << std::endl << std::endl;
	AMateria *iceClone = ice->clone();
	AMateria *cureClone = cure->clone();
	std::cout << "Ice clone type: " << iceClone->getType() << std::endl;
	std::cout << "Cure clone type: " << cureClone->getType() << std::endl;

	std::cout << PINK << "\n======= TEST 3 : MATERIASOURCE CREATION =======" << RESET << std::endl << std::endl;
	IMateriaSource* base = new MateriaSource();
	base->learnMateria(ice);
	base->learnMateria(cure);

	std::cout << PINK << "\n======= TEST 4 : NEW CHARACTER CREATION =======" << RESET << std::endl << std::endl;
	ICharacter	*john = new Character("John");
	ICharacter	*martine = new Character("Martine");
	std::cout << "Hi, our names are " << john->getName() << " and " << martine->getName() << std::endl;

	std::cout << PINK << "\n======= TEST 5 : GET EQUIPED WITH MATERIA =======" << RESET << std::endl << std::endl;
	AMateria *johnEquipment = base->createMateria("ice");
	john->equip(johnEquipment);
	AMateria *martineEquipment = base->createMateria("cure");
	martine->equip(martineEquipment);

	std::cout << PINK << "======= TEST 6 : USE THE MATERIAS =======" << RESET << std::endl << std::endl;
	john->use(0, *martine);
	martine->use(1, *john);

	delete iceClone;
	delete cureClone;
	delete john;
	delete martine;
	delete ice;
	delete cure;
	return (0);
}









/* Main fourni dans le sujet */

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }
