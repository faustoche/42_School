#include "../includes/DiamondTrap.hpp"

/*-------------- CONSTRUCTORS --------------*/

DiamondTrap::DiamondTrap(){
	this->name = "No name";
	this->hit_point = FragTrap::hit_point;
	this->energy_point = ScavTrap::energy_point;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << WHITE << "DiamondTrap created by default constructor." << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"){
	this->name = name;
	this->hit_point = FragTrap::hit_point;
	this->energy_point = ScavTrap::energy_point;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << WHITE << "DiamondTrap " << name << " created by parameterized constructor." << RESET << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << WHITE << "DiamondTrap " << this->name << " destroyed by destructor." << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other){
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
	std::cout << "My name is " << this->name << " and my trap name is " << this->ClapTrap::name << std::endl;
}