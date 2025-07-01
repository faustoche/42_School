#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/*-------------- CLASSES --------------*/

/* En virtual public pour pour hériter virtuellement */

class FragTrap : virtual public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	void	highFivesGuys() const;
};

#endif