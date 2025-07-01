#include "../includes/DiamondTrap.hpp"

/*-------------- CONSTRUCTORS --------------*/

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name){
	this->name = name;
	this->hit_point = FragTrap::hit_point;
	this->energy_point = ScavTrap::energy_point;
	std::cout << ScavTrap::energy_point << std::endl;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap " << name << " constructed." << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " destroyed by destructor." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other){
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other){
		this->name = other.name;
		this->hit_point = other.hit_point;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

/*-------------- FUNCTIONS --------------*/

void	DiamondTrap::whoAmI(){
	std::cout << "My name is " << this->name << " and my ClapTrap name is " << this->ClapTrap::name << std::endl;
}