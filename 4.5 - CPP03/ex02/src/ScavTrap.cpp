#include "../includes/ScavTrap.hpp"

/*-------------- CONSTRUCTORS --------------*/

ScavTrap::ScavTrap() {
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap created by default constructor." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << name << " created by parameterized constructor." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " destroyed by destructor." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other){
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other){
		this->name = other.name;
		this->hit_point = other.hit_point;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

/*-------------- FUNCTIONS --------------*/

void	ScavTrap::attack(const std::string &target) {
	if (this->energy_point == 0) {
		std::cout << "Too bad, ScavTrap " << this->name << " has no energy point left and cannot attack " << target << std::endl;
		return ;
	}
	if (this->hit_point == 0) {
		std::cout << "Well, ScavTrap " << this->name << " has no hit point left and cannot attack " << target << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!"<< std::endl;
	energy_point--;
}

void	ScavTrap::guardGate() {
		std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
