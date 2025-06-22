#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

/*-------------- INCLUDES --------------*/

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/*-------------- CLASS --------------*/
 
class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);
};

#endif