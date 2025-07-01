#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

void	ClapTrap::status()
{
	std::cout << "\n[HIT POINTS: " << this->hit_point << ", ENERGY POINTS: " << this->energy_point << "]" << std::endl;
}

int	main()
{
	{
		std::cout << CORAL << "\n*----- TEST 1 : JUST AN ATTACK -----*" << RESET << std::endl << std::endl;
		ClapTrap xavier("Xavier");
		std::cout << CORAL << "------------------------------" << RESET << std::endl;
		xavier.attack("a dog");
		xavier.takeDamage(4);
		xavier.beRepaired(2);
		std::cout << CORAL << "------------------------------" << RESET << std::endl;
	}
	{
		std::cout << GREEN << "\n*----- TEST 2 : LET'S BE FRIENDS -----*" << RESET << std::endl << std::endl;
		FragTrap thomas("Thomas");
		std::cout << GREEN << "------------------------------" << RESET << std::endl;
		thomas.attack("a cat");
		thomas.highFivesGuys();
		thomas.beRepaired(2);
		std::cout << GREEN << "------------------------------" << RESET << std::endl;
	}
	return (0);
}