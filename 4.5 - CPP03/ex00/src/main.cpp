#include "../includes/ClapTrap.hpp"

void	ClapTrap::status()
{
	std::cout << "\n[HIT POINTS: " << this->hit_point << ", ENERGY POINTS: " << this->energy_point << "]" << std::endl;
}

int	main()
{
	{
		std::cout << CORAL << "\n*----- TEST 1 : EVERYTHING ALL RIGHT -----*" << RESET << std::endl << std::endl;
		ClapTrap	tristan("Tristan");
		std::cout << CORAL << "------------------------------\n" << RESET;
		tristan.attack("banker");
		tristan.takeDamage(5);
		tristan.beRepaired(3);
		tristan.attack("banker");
		tristan.takeDamage(7);
		tristan.beRepaired(1);
		tristan.status();
		std::cout << CORAL << "------------------------------\n" << RESET;
		std::cout << "\n";
	}
	{
		std::cout << BLUE_BRIGHT << "\n*----- TEST 2 : NOT ENOUGH ENERGY POINT TO RESTORE HEALTH -----*" << RESET << std::endl << std::endl;
		ClapTrap	clemonce("Clémonce");
		std::cout << BLUE_BRIGHT << "------------------------------\n" << RESET;
		for (int i = 0; i < 10; i++)
			clemonce.attack("URSAFF");
		clemonce.beRepaired(5);
		clemonce.status();
		std::cout << BLUE_BRIGHT << "------------------------------\n" << RESET;
		std::cout << "\n";
	}
	{
		std::cout << MAGENTA << "\n*----- TEST 3 : NOT ENOUGH ENERGY POINT TO ATTACK -----*" << RESET << std::endl << std::endl;
		ClapTrap	david("David");
		std::cout << MAGENTA << "------------------------------\n" << RESET;
		for (int i = 0; i < 11; i++)
			david.attack("the void of his life");
		david.status();
		std::cout << MAGENTA << "------------------------------\n" << RESET;
		std::cout << "\n";
	}
	{
		std::cout << PINK << "\n*----- TEST 5 : NOT ENOUGH ENERGY FOR FULL REPAIR -----*" << RESET << std::endl << std::endl;
		ClapTrap	virginie("Virginie");
		std::cout << PINK << "------------------------------\n" << RESET;
		for (int i = 0; i < 10; i++)
			virginie.beRepaired(1);
		virginie.beRepaired(1);
		virginie.status();
		std::cout << PINK << "------------------------------\n" << RESET;
		std::cout << "\n";
	}
	{
		std::cout << GREEN << "\n*----- TEST 6 : REPAIR WITH A LOT OF HEALTH POINT -----*" << RESET << std::endl << std::endl;
		ClapTrap	didier("Didier");
		std::cout << GREEN << "------------------------------\n" << RESET;
		didier.beRepaired(2);
		didier.beRepaired(2);
		didier.status();
		std::cout << GREEN << "------------------------------\n" << RESET;
		std::cout << "\n";
	}
	{
		std::cout << CYAN << "\n*----- TEST 7 : ATTACK AFTER DYING | ZOMBIE VIBE -----*" << RESET << std::endl << std::endl;
		ClapTrap	veronique("Véronique");
		std::cout << CYAN << "------------------------------\n" << RESET;
		veronique.takeDamage(10);
		veronique.attack("small spider in the room corner");
		veronique.status();
		std::cout << CYAN << "------------------------------\n" << RESET;
		std::cout << "\n";
	}
	{
		std::cout << GOLD << "\n*----- TEST 8 : GOING DOWN DOWN DOWN (NEGATIVE HIT POINT) -----*" << RESET << std::endl << std::endl;
		ClapTrap	christophe("Christophe");
		std::cout << GOLD << "------------------------------\n" << RESET;
		christophe.takeDamage(20);
		christophe.status();
		std::cout << GOLD << "------------------------------\n" << RESET;
		std::cout << "\n";
	}
	return (0);
}