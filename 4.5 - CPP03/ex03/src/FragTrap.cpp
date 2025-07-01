#include "../includes/FragTrap.hpp"

/*-------------- CONSTRUCTORS --------------*/

FragTrap::FragTrap(){
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap created by default constructor." << std::endl;
}

FragTrap::FragTrap(std::string name){
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

void	FragTrap::highFivesGuys() const {
		std::cout << "FragTrap " << this->name << " said : High Fives anyone?" << std::endl;
}
