#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string	Name;
	int	hit_point = 10;
	int	energy_point = 10;
	int	attack_damage = 0;

public:
	ClapTrap(std::string Name);
	~ClapTrap();
	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

ClapTrap::ClapTrap(std::string Name)
{
}

ClapTrap::~ClapTrap()
{
}


#endif