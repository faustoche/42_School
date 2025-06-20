#include "FragTrap.hpp"


/*-------------- CONSTRUCTORS --------------*/

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << name << " created by constructor." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " destroyed by destructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other){

}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other){
		this->name = other.name;
		this->hit_point = other.hit_point;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

/*-------------- FUNCTIONS --------------*/

void	FragTrap::attack(const std::string &target) {
	if (this->energy_point == 0) {
		std::cout << "Too bad, FragTrap " << this->name << " has no energy point left and cannot attack " << target << std::endl;
		return ;
	}
	if (this->hit_point == 0) {
		std::cout << "Well, FragTrap " << this->name << " has no hit point left and cannot attack " << target << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!"<< std::endl;
	energy_point--;
}

void	FragTrap::highFivesGuys() {
		std::cout << "FragTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
