#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

/*-------------- INCLUDES --------------*/

#include "ClapTrap.hpp"

/* 
** When an object is heritated from another class, construction of the class is automatically
** called first. Then, the one from the second object.
** It is reverse for the destruction ones
*/

/*-------------- CLASSES --------------*/

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