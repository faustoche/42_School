#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

/*-------------- INCLUDES --------------*/

#include "ClapTrap.hpp"

/* 
** Construction et déconstruction en chaîne
** Quand un objet est hérité d'une autre class, le construction de la class est
** automatiquement appelé en premier, puis ensuite celui du second objet créé
** Pour la destruction c'est l'inverse, on détruit d'abord le dernier créé
*/

/*-------------- CLASS --------------*/

class ScavTrap : public ClapTrap {
public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	void	attack(const std::string &target);
	void	guardGate();
};

#endif