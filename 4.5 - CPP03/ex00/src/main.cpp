#include "../includes/ClapTrap.hpp"

void	ClapTrap::status()
{
	std::cout << WHITE << "\n[HIT POINTS: " << this->hit_point << ", ENERGY POINTS: " << this->energy_point << "]" << RESET << std::endl;
}

void printHeader(int i, std::string color, std::string reset, std::string testName)
{
	std::cout << color << "\n=======================================================\n" << reset;
	std::cout << WHITE << "TEST " << i << " : " << testName << RESET << std::endl;
	std::cout << color << "=======================================================\n" << reset;
}

int	main()
{
	{
		printHeader(0, TURQUOISE, RESET, "CALLING DEFAULT OR PARAMETERIZED CONSTRUCTORS");
		ClapTrap	jeannine("Jeannine");
		ClapTrap	clap_trap;
		std::cout << "\n";
	}
	{
		printHeader(1, CORAL, RESET, "EVERYTHING IS ALL RIGHT");
		ClapTrap	tristan("Tristan");
		tristan.status();
		std::cout << std::endl;
		tristan.attack("banker");
		tristan.takeDamage(5);
		tristan.beRepaired(3);
		tristan.attack("banker");
		tristan.takeDamage(7);
		tristan.beRepaired(1);
		tristan.status();
		std::cout << "\n";
	}
	{
		printHeader(2, BLUE_BRIGHT, RESET, "NOT ENOUGH ENERGY POINT TO RESTORE HEALTH");
		ClapTrap	clemonce("Clémonce");
		clemonce.status();
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			clemonce.attack("URSAFF");
		clemonce.beRepaired(5);
		clemonce.status();
		std::cout << "\n";
	}
	{
		printHeader(3, MAGENTA, RESET, "NOT ENOUGH ENERGY POINT TO ATTACK");
		ClapTrap	david("David");
		david.status();
		std::cout << std::endl;
		for (int i = 0; i < 11; i++)
			david.attack("the void of his life");
		david.status();
		std::cout << "\n";
	}
	{
		printHeader(4, GOLD, RESET, "TOO MANY POINTS, STOP IT!");
		ClapTrap	olivier("Olivier");
		olivier.status();
		std::cout << std::endl;
		olivier.beRepaired(787987465);
		olivier.status();
		std::cout << "\n";
	}
	{
		printHeader(5, PINK, RESET, "NOT ENOUGH ENERGY POINT FOR FULL REPAIR");
		ClapTrap	virginie("Virginie");
		virginie.status();
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			virginie.beRepaired(1);
		virginie.beRepaired(1);
		virginie.status();
		std::cout << "\n";
	}
	{
		printHeader(6, GREEN, RESET, "REPAIR WITH A LOT OF HEALTH POINT");
		ClapTrap	didier("Didier");
		didier.status();
		std::cout << std::endl;
		didier.beRepaired(2);
		didier.beRepaired(2);
		didier.status();
		std::cout << "\n";
	}
	{
		printHeader(7, CYAN, RESET, "ATTACK AFTER DYING");
		ClapTrap	veronique("Véronique");
		veronique.status();
		std::cout << std::endl;
		veronique.takeDamage(10);
		veronique.attack("small spider in the room corner");
		veronique.status();
		std::cout << "\n";
	}
	{
		printHeader(8, GOLD, RESET, "GOING DOWN DOWN DOWN (NEGATIVE HIT POINT)");
		ClapTrap	christophe("Christophe");
		christophe.status();
		std::cout << std::endl;
		christophe.takeDamage(20);
		christophe.status();
		std::cout << "\n";
	}
	return (0);
}