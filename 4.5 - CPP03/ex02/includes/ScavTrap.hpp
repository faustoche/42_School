#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

/*-------------- INCLUDES --------------*/

#include "ClapTrap.hpp"

/*-------------- CLASS --------------*/

class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	void	attack(const std::string &target);
	void	guardGate();
};

#endif