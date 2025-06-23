#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	{
		std::cout << CORAL << "\n*----- TEST 1 : CREATION OF A CLAPTRAP -----*" << RESET << std::endl << std::endl;
		ClapTrap michel("Michel");
		std::cout << CORAL << "------------------------------" << RESET;
		std::cout << "\n";
	}
	{
		std::cout << BLUE_BRIGHT << "\n*----- TEST 2 : CREATION OF A SCAVTRAP -----*" << RESET << std::endl << std::endl;
		ScavTrap	ghislaine("Ghislaine");
		std::cout << BLUE_BRIGHT << "------------------------------" << RESET;
		std::cout << "\n";
	}
	{
		std::cout << GREEN << "\n*----- TEST 3 : ATTACK MODE! -----*" << RESET << std::endl << std::endl;
		ClapTrap	jeannot("Jeannot");
		ScavTrap	lancelot("Lancelot");
		std::cout << GREEN << "------------------------------\n" << RESET;
		jeannot.attack("the dumbass reading this");
		lancelot.attack("that one guy harassing him at school");
		std::cout << GREEN << "------------------------------" << RESET;
		std::cout << "\n";
	}
	{
		std::cout << MAGENTA << "\n*----- TEST 4 : GUARDIAN MODE -----*" << RESET << std::endl << std::endl;
		ScavTrap	arthur("Arthur");
		std::cout << MAGENTA << "------------------------------\n" << RESET;
		arthur.guardGate();
		std::cout << MAGENTA << "------------------------------" << RESET;
		std::cout << "\n";
	}
	return (0);
}