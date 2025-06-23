#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>

/*-------------- DEFINES --------------*/

#define RESET   "\033[0m"
#define WHITE   "\033[1;97m"
#define FUCHSIA "\033[1;38;5;201m"
#define BLUE_BRIGHT "\033[1;94m"
#define GREEN       "\033[1;32m"
#define MAGENTA     "\033[1;35m"
#define CYAN        "\033[1;36m"
#define RED "\033[1;91m"
#define YELLOW "\033[1;93m"
#define ORANGE      "\033[1;38;5;208m"
#define PINK        "\033[1;38;5;205m"
#define TURQUOISE   "\033[1;38;5;45m"
#define GOLD        "\033[1;38;5;220m"
#define CORAL       "\033[1;38;5;203m"

/*-------------- CLASS --------------*/

class ClapTrap
{
private:
	std::string	name;
	int	hit_point;
	int	energy_point;
	int	attack_damage;

public:
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