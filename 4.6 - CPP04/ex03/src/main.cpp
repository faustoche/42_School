#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

void PrintMateriaSource(const MateriaSource& source)
{
    std::cout << WHITE << "\nContent of MateriaSource:" << RESET << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << " • Slot [" << i << "]: ";
        if (source.materia[i] != NULL)
            std::cout << source.materia[i]->getType() << std::endl;
        else
            std::cout << "Empty" << std::endl;
    }
}

void UseMateria(ICharacter& character, ICharacter& target, int slot)
{
	if (slot >= 0 && slot <= 4){
		std::cout << character.getName() << " is using materia [" << slot << "] on " << target.getName() << std::endl;
		character.use(slot, target);
	}
	else
		std::cout << "Wow, this slot is complety out of bounds." << std::endl;
}

void printHeader(int i, std::string color, std::string reset, std::string testName)
{
	std::cout << color << "\n=======================================================\n" << reset;
	std::cout << WHITE << "      TEST " << i << " : " << testName << RESET << std::endl;
	std::cout << color << "=======================================================\n" << reset << std::endl;
}

int main(void)
{
	{
		printHeader(1, GREEN, RESET, "BASIC MATERIA CREATION");
		Ice	*ice = new Ice();
		Cure *cure = new Cure();
		std::cout << "• Ice created  : " << ice->getType() << std::endl;
		std::cout << "• Cure created : " << cure->getType() << std::endl;
		delete ice;
		delete cure;
	}
	{
		printHeader(2, PINK, RESET, "CLONING THE MATERIAS");
		Ice	*ice = new Ice();
		Cure *cure = new Cure();
		AMateria *iceClone = ice->clone();
		AMateria *cureClone = cure->clone();
		std::cout << "Ice has been cloned - Type: " << iceClone->getType() << std::endl;
		std::cout << "Cure has been cloned - Type: " << cureClone->getType() << std::endl;
		std::cout << "Adresses :" << std::endl;
		std::cout << " • Ice (original) : " << ice << " ||| Clone: " << iceClone << std::endl;
		std::cout << " • Cure (original): " << cure << " ||| Clone: " << cureClone << std::endl;
		delete ice;
		delete cure;
		delete iceClone;
		delete cureClone;
	}
	{
		printHeader(3, BLUE_BRIGHT, RESET, "CREATION AND LEARNING OF MATERIAS");
		MateriaSource *src = new MateriaSource();
		std::cout << "MateriaSource created" << std::endl;
		PrintMateriaSource(*src);
		std::cout << "\nLearning the materias..." << std::endl;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		PrintMateriaSource(*src);
		delete src;
	}
	{
		printHeader(4, YELLOW, RESET, "CREATION OF CHARACTERS");
		Character *riri = new Character("Riri");
		Character *fifi = new Character("Fifi");
		Character *loulou = new Character();
		std::cout << WHITE << "Characters created:" << RESET << std::endl;
		std::cout << " • " << riri->getName() << std::endl;
		std::cout << " • " << fifi->getName() << std::endl;
		std::cout << " • " << loulou->getName() << std::endl;
		delete riri;
		delete fifi;
		delete loulou;
	}
	{
		printHeader(5, TURQUOISE, RESET, "EQUIPMENT");
		MateriaSource *src = new MateriaSource();
		Character *jacky = new Character("Jacky");
		Character *patrick = new Character("Patrick");
		std::cout << "Jacky is getting equipped" << std::endl;
		jacky->equip(src->createMateria("ice"));
		jacky->equip(src->createMateria("cure"));
		jacky->equip(src->createMateria("ice"));
		jacky->equip(src->createMateria("cure"));
		std::cout << "Patrick is getting equipped" << std::endl;
		patrick->equip(src->createMateria("cure"));
		patrick->equip(src->createMateria("ice"));
		std::cout << "\n[Trying to add something to a full materia...]\n" << std::endl;
		jacky->equip(src->createMateria("ice"));
		delete src;
		delete jacky;
		delete patrick;
	}
	{
		printHeader(6, ORANGE, RESET, "COMBAT IS STARTING!");
		Character *franck = new Character("Franck");
		Character *didier = new Character("Didier");
		Character *michel = new Character();
		UseMateria(*franck, *didier, 0);
		UseMateria(*franck, *didier, 1);
		UseMateria(*didier, *franck, 0);
		UseMateria(*didier, *franck, 1);
		std::cout << "\nTrying on invalid slot. We never know..." << std::endl;
		UseMateria(*michel, *franck, 0);
		UseMateria(*franck, *didier, 5);
		UseMateria(*franck, *didier, -1);
		delete franck;
		delete didier;
		delete michel;
	}
	{
		printHeader(7, FUCHSIA, RESET, "UNEQUIPMENT");
		Character *charly = new Character("Charly");
		Character *edward = new Character("Edward");
		std::cout << "Unequipment of Charly's slot[0]" << std::endl;
		charly->unequip(0);
		UseMateria(*charly, *edward, 0);
		std::cout << "[Trying to emptied an already empty slot]" << std::endl;
		charly->unequip(0);
		std::cout << "[Trying to unequippe an invalid slot]" << std::endl;
		charly->unequip(10);
		charly->unequip(-5);
		delete charly;
		delete edward;
	}
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
