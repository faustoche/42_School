#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

/*-------------- INCLUDES --------------*/

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/*-------------- CLASS --------------*/

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap();
	void	whoAmI();
	void	status();
};

#endif