#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

void	DiamondTrap::status()
{
	std::cout << "\n[HIT POINTS: " << this->hit_point << ", ENERGY POINTS: " << this->energy_point << "]" << std::endl;
}

int	main()
{
	{
		std::cout << CORAL << "\n*----- TEST 1 : WHO AM I? -----*" << RESET << std::endl << std::endl;
		DiamondTrap jean("Jean");
		std::cout << CORAL << "------------------------------" << RESET << std::endl;
		jean.whoAmI();
		std::cout << CORAL << "------------------------------" << RESET << std::endl;
		std::cout << "\n";
	}
	{
		std::cout << GREEN << "\n*----- TEST 2 : DID INHERITANCE WORKED? -----*" << RESET << std::endl << std::endl;
		DiamondTrap thomas("Thomas");
		std::cout << GREEN << "------------------------------" << RESET << std::endl;
		thomas.status();
		std::cout << GREEN << "------------------------------" << RESET << std::endl;
		std::cout << "\n";
	}
	{
		std::cout << BLUE_BRIGHT << "\n*----- TEST 3 : CAN DIAMONDTRAP ATTACK? -----*" << RESET << std::endl << std::endl;
		DiamondTrap gigi("Gigi");
		std::cout << BLUE_BRIGHT << "------------------------------" << RESET << std::endl;
		gigi.attack("Faustoche");
		std::cout << BLUE_BRIGHT << "------------------------------" << RESET << std::endl;
		std::cout << "\n";
	}
	{
		std::cout << PINK << "\n*----- TEST 4 : ILLEGAL CLONING -----*" << RESET << std::endl << std::endl;
		DiamondTrap dolly("Dolly");
		DiamondTrap clone = dolly;
		std::cout << PINK << "------------------------------" << RESET << std::endl;
		clone.whoAmI();
		std::cout << PINK << "------------------------------" << RESET << std::endl;
		std::cout << "\n";
	}
	{
		std::cout << TURQUOISE << "\n*----- TEST 5 : OPERATING 5+5=11 -----*" << RESET << std::endl << std::endl;
		DiamondTrap a("Louis");
		DiamondTrap b("Lagrange");
		b = a;
		std::cout << TURQUOISE << "------------------------------" << RESET << std::endl;
		b.whoAmI();
		std::cout << TURQUOISE << "------------------------------" << RESET << std::endl;
		std::cout << "\n";
	}
	{
		std::cout << MAGENTA << "\n*----- TEST 6 : WHO ARE THEY? -----*" << RESET << std::endl << std::endl;
		DiamondTrap team[] = {
			DiamondTrap("Riri"),
			DiamondTrap("Fifi"),
			DiamondTrap("Loulou")
		};
		std::cout << MAGENTA << "------------------------------" << RESET << std::endl;
		for (int i = 0; i < 3; i++)
			team[i].whoAmI();
		std::cout << MAGENTA << "------------------------------" << RESET << std::endl;
		std::cout << "\n";
	}
	{
		std::cout << TURQUOISE << "\n*----- TEST 7 : HERITAGE -----*" << RESET << std::endl << std::endl;
		DiamondTrap a("Louis");
		DiamondTrap b("Lagrange");
		b = a;
		std::cout << TURQUOISE << "------------------------------" << RESET << std::endl;
		b.whoAmI();
		std::cout << TURQUOISE << "------------------------------" << RESET << std::endl;
		std::cout << "\n";
	}
	return (0);
}
