#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

/*-------------- INCLUDES --------------*/

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/*-------------- CLASS --------------*/

class FragTrap : public ClapTrap {
public:
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	void	highFivesGuys() const;
};

#endif