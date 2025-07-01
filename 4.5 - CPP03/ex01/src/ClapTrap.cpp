#include "../includes/ClapTrap.hpp"

/*-------------- CONSTRUCTORS --------------*/

ClapTrap::ClapTrap(std::string name)
	: name("No name"), hit_point(10), energy_point(10), attack_damage(0){
	std::cout << "ClapTrap created by default constructor." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hit_point(10), energy_point(10), attack_damage(0){
	std::cout << "ClapTrap " << this->name << " created by constructor." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " destroyed by destructor." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->name = other.name;
		this->hit_point = other.hit_point;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

/*-------------- FUNCTIONS --------------*/

void	ClapTrap::attack(const std::string &target) {
	if (this->energy_point == 0) {
		std::cout << "Well, ClapTrap " << this->name << " has no energy point left. Thus, cannot attack " << target << std::endl;
		return ;
	}
	if (this->hit_point == 0) {
		std::cout << "Well, ClapTrap " << this->name << " has no hit point left. Thus, cannot attack " << target << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!"<< std::endl;
	energy_point--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if ((int)amount < 0 || amount > 1000){
		std::cout << "Oh oh... this is not possible..." << std::endl;
		return ;
	}
	if (this->hit_point == 0) {
		std::cout << "What did you expect ? ClapTrap " << this->name << " has no hit point left and died." << std::endl;
		return ;
	}
	std::cout << "Oh no... ClapTrap " << this->name << " received " << amount << " points of damage!" << std::endl;
	if (amount >= (unsigned int)this->hit_point) {
		this->hit_point = 0;
		std::cout << "Arf, ClapTrap " << this->name << " died." << std::endl;
	} else {
		this->hit_point -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount){
	if ((int)amount < 0 || amount > 1000){
		std::cout << "Oh oh... this is not possible..." << std::endl;
		return ;
	}
	if (this->hit_point == 0) {
		std::cout << "Too bad, ClapTrap " << this->name << " is dead. No hit point left..." << std::endl;
		return ;
	}
	if (this->energy_point == 0) {
		std::cout << "Damn, ClapTrap " << this->name << " has no energy point left. Cannot be repaired!" << std::endl;
		return ;
	}
	std::cout << "Wow, ClapTrap " << this->name << " is regaining " << amount << " hit points!" << std::endl;
	this->hit_point += amount;
	this->energy_point--;
	return ;
}