#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>
#include "colors.hpp"

/*-------------- CLASS --------------*/

class ClapTrap
{
protected:
	std::string	name;
	int	hit_point;
	int	energy_point;
	int	attack_damage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	status();
};

#endif