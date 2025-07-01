#include "Character.hpp"
#include "ICharacter.hpp"

/*-------------- CONSTRUCTORS --------------*/

Character::Character(void) : name("unnamed"){
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const std::string name) : name(name){
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character &other){
	for (int i = 0; i < 4; i++){
		if (other.inventory[i] != NULL)
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character &Character::operator=(const Character &other){
	if (this != &other){
		for (int i = 0; i < 4; i++)
			delete this->inventory[i];
		this->name = other.name;
		for (int i = 0; i < 4; i++){
			if (other.inventory[i] != NULL)
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character(){
	for (int i = 0; i < 4; i++){
		delete this->inventory[i];
	}
}

/*-------------- GETTER --------------*/

std::string const &Character::getName() const{
	return (name);
}

/*-------------- FUNCTIONS --------------*/

void	Character::equip(AMateria *m){
	for (int i = 0; i < 4; i++){
		if (inventory[i] == NULL){
			inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx){
	if (idx >= 0 && idx <= 3){
		if (inventory[idx] != NULL){
			inventory[idx] = NULL;
			return ;
		}
	}
}

void	Character::use(int idx, ICharacter &target){
	if (idx >= 0 && idx <= 3){
		if (inventory[idx] != NULL){
			inventory[idx]->use(target);
			return ;
		}
	}
}

AMateria *Character::getMateria(int idx) const {
	if (idx >= 0 && idx < 4)
		return (inventory[idx]);
	return (NULL);
}