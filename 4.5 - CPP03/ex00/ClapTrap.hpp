#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string	name;
	int	hit_point;
	int	energy_point;
	int	attack_damage;

public:
	ClapTrap(std::string name); // Constructeur par défaut
	~ClapTrap(); // Destructeur par défault
	ClapTrap(const ClapTrap &other); // Constructeur de recopie
	ClapTrap &operator=(const ClapTrap &other); // Constructeur d'opérateur
	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	status();
};

#endif